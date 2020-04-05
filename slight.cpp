// slight.cpp: Copyright 2020 Micah Switzer
// SPDX-License-Identifier: GPL-3.0-or-later

#include <iostream>
#include <SlightConfig.h>
#include <RF24/RF24.h>
#ifdef USE_MYFUNC
#  include "Functions.h"
#endif

RF24 radio(59,0);

const uint8_t endpoints[][6] = { "node1", "node2" };

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << argv[0] << " Version " << 
            Slight_VERSION_MAJOR << "." <<
            Slight_VERSION_MINOR << std::endl;
        std::cout << "Usage: " << argv[0] <<
            " value" << std::endl;
        return 1;
    }

    try {
        radio.begin();
    } catch (SPIException spiEx) {
        std::cout << "Couldn't open the SPI device (is SPIDEV enabled?)" << std::endl;
        return 1;
    }

    radio.setPALevel(RF24_PA_LOW);

    radio.openReadingPipe(1, endpoints[0]);
    radio.startListening();

    const double inputValue = std::stod(argv[1]);

    const double outputVal = 
#ifdef USE_MYFUNC
        myFunc(inputValue);
#else
        (inputValue + 1) * 2;
#endif

    std::cout << "The result is " << outputVal << std::endl;

    return 0;
}

