cmake_minimum_required(VERSION 3.10)

project(DLProg VERSION 0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

option(USE_MYFUNC "Use dlprog provided functions" ON)

configure_file(DLProgConfig.h.in DLProgConfig.h)

if(USE_MYFUNC)
  add_subdirectory(Functions)
  list(APPEND EXTRA_LIBS Functions)
  list(APPEND EXTRA_INCLUDES
       "${PROJECT_SOURCE_DIR}/Functions")
endif()

add_executable(DLProg DLProg.cpp)

target_link_libraries(DLProg PUBLIC ${EXTRA_LIBS})

target_include_directories(DLProg PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${EXTRA_INCLUDES}"
                           )
