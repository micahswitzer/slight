cmake_minimum_required(VERSION 3.10)

project(Slight VERSION 0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

option(USE_MYFUNC "Use slight provided functions" ON)

configure_file(SlightConfig.h.in SlightConfig.h)

if(USE_MYFUNC)
  add_subdirectory(Functions)
  list(APPEND EXTRA_LIBS Functions)
  list(APPEND EXTRA_INCLUDES
       "${PROJECT_SOURCE_DIR}/Functions")
endif()

add_library(librf24 SHARED IMPORTED)
set_property(TARGET librf24 PROPERTY IMPORTED_LOCATION /usr/lib/librf24.so.1)

add_executable(Slight slight.cpp)

target_link_libraries(Slight PRIVATE librf24 PUBLIC ${EXTRA_LIBS})

target_include_directories(Slight PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${EXTRA_INCLUDES}"
                           )
