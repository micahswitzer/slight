// slight.cpp: Copyright 2020 Micah Switzer
// SPDX-License-Identifier: GPL-3.0-or-later

#include <iostream>
#include <SlightConfig.h>
#ifdef USE_MYFUNC
#  include "Functions.h"
#endif

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << argv[0] << " Version " << 
            Slight_VERSION_MAJOR << "." <<
            Slight_VERSION_MINOR << std::endl;
        std::cout << "Usage: " << argv[0] <<
            " value" << std::endl;
        return 1;
    }

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

