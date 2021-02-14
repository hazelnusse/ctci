cmake_minimum_required(VERSION 3.13...3.19)
project(ctci
    DESCRIPTION "Cracking the Coding Interview, 6th edition"
    LANGUAGES CXX
)
set(CMAKE_CXX_EXTENSIONS OFF)

option(CTCI_BUILD_BENCHMARKS "Build benchmark examples" ON)
option(CTCI_BUILD_TESTS "Build tests" ON)

include(cmake/Externals.cmake)

add_subdirectory(ch1)
message(STATUS "CMAKE_CXX_COMPILE_FEATURES = ${CMAKE_CXX_COMPILE_FEATURES}")
