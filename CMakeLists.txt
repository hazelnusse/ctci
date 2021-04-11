cmake_minimum_required(VERSION 3.17...3.20 FATAL_ERROR)

project(
  ctci
  VERSION 1.0
  DESCRIPTION "Cracking the Coding Interview, 6th edition"
  LANGUAGES CXX
)

macro(ctci_add_library CTCI_LIBRARY_NAME)
    add_library(${CTCI_LIBRARY_NAME} ${ARGN})
    set_target_properties(${CTCI_LIBRARY_NAME}
        PROPERTIES
            CXX_STANDARD 20
            CXX_EXTENSIONS OFF
    )
    target_include_directories(${CTCI_LIBRARY_NAME} PUBLIC include)
endmacro()

ctci_add_library(is_unique_bitfield source/is_unique_bitfield.cpp)
ctci_add_library(is_unique_brute_force source/is_unique_brute_force.cpp)
ctci_add_library(is_unique_sort source/is_unique_sort.cpp)
ctci_add_library(reverse source/reverse.cpp)
ctci_add_library(check_permutation_map source/check_permutation_map.cpp)
ctci_add_library(check_permutation_array source/check_permutation_array.cpp)
