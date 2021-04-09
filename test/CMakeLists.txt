cmake_minimum_required(VERSION 3.13...3.20 FATAL_ERROR)

project(CTCITests LANGUAGES CXX)

# ---- Options ----

option(ENABLE_TEST_COVERAGE "Enable test coverage" OFF)
option(TEST_INSTALLED_VERSION "Test the version found by find_package" OFF)

# --- Import tools ----

include(../cmake/tools.cmake)

# ---- Dependencies ----

include(../cmake/get_CPM.cmake)

macro(ctci_add_test CTCI_TEST_NAME CTCI_TEST_SOURCE)
    add_executable(${CTCI_TEST_NAME} ${CTCI_TEST_SOURCE})
    target_link_libraries(${CTCI_TEST_NAME} PUBLIC doctest_main ${ARGN})
    target_compile_options(${CTCI_TEST_NAME} PUBLIC -Wall -Wpedantic -Wextra -Werror)
    set_target_properties(${CTCI_TEST_NAME}
        PROPERTIES
            CXX_STANDARD 20
            CXX_EXTENSIONS OFF
    )
    doctest_discover_tests(${CTCI_TEST_NAME})
endmacro()

CPMAddPackage("gh:onqtam/doctest#2.4.5")
include(${doctest_SOURCE_DIR}/scripts/cmake/doctest.cmake)

CPMAddPackage("gh:TheLartians/Format.cmake@1.7.0")

CPMAddPackage(NAME ctci SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/..)

# Doctest main entry point. TODO: figure out how to refer to the target already
# built inside of doctest.
add_library(doctest_main main.cpp)
set_target_properties(doctest_main
    PROPERTIES
        CXX_STANDARD 20
        CXX_EXTENSIONS OFF
)
target_link_libraries(doctest_main PUBLIC doctest::doctest)

# Add tests for each exercise below:
ctci_add_test(is_unique_brute_force_test is_unique.test.cpp
    is_unique_brute_force
    is_unique_bitfield
    is_unique_sort
)

ctci_add_test(reverse_test reverse.test.cpp
    reverse
)

enable_testing()

# ---- code coverage ----

#if(ENABLE_TEST_COVERAGE)
#  target_compile_options(Greeter PUBLIC -O0 -g -fprofile-arcs -ftest-coverage)
#  target_link_options(Greeter PUBLIC -fprofile-arcs -ftest-coverage)
#endif()
