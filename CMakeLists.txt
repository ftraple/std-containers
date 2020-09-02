cmake_minimum_required(VERSION 3.10)

project(std-container VERSION 0.0.0)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

option(BUILD_LIBRARY "Build library" ON)
option(BUILD_TEST "Build test" ON)

if(BUILD_LIBRARY)
    add_subdirectory(container)
endif()

if(BUILD_TEST)
    enable_testing()
    add_subdirectory(test)
endif()