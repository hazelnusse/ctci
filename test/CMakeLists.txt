cmake_minimum_required(VERSION 3.17...3.20 FATAL_ERROR)
project(CTCITests LANGUAGES CXX)

option(ENABLE_TEST_COVERAGE "Enable test coverage" OFF)
option(TEST_INSTALLED_VERSION "Test the version found by find_package" OFF)

include(../cmake/tools.cmake)
include(../cmake/get_CPM.cmake)

enable_testing()

#cpmaddpackage("gh:onqtam/doctest#2.4.6")
cpmaddpackage("gh:boost-ext/ut#ffe66dd9414f73ed252c5dc815f56bf4d53929ca")
message("ut_SOURCE_DIR = ${ut_SOURCE_DIR}")
#include(${doctest_SOURCE_DIR}/scripts/cmake/doctest.cmake)
cpmaddpackage("gh:TheLartians/Format.cmake@1.7.0")
cpmaddpackage(NAME ctci SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/..)

macro(ctci_add_test CTCI_TEST_NAME CTCI_TEST_SOURCE)
  add_executable(${CTCI_TEST_NAME} ${CTCI_TEST_SOURCE})
  target_link_libraries(${CTCI_TEST_NAME} PUBLIC ut PRIVATE ${ARGN})
  if(CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID MATCHES
                                              "GNU")
    target_compile_options(${CTCI_TEST_NAME} PUBLIC -Wall -Wpedantic -Wextra
                                                    -Werror)
  elseif(MSVC)
    foreach(lib ${ARGN})
      target_compile_options(${lib} PUBLIC /W4 /WX)
    endforeach()
    target_compile_definitions(${CTCI_TEST_NAME}
                               PUBLIC DOCTEST_CONFIG_USE_STD_HEADERS)
  endif()
  set_target_properties(${CTCI_TEST_NAME} PROPERTIES CXX_STANDARD 20
                                                     CXX_EXTENSIONS OFF)
  add_test(NAME ${CTCI_TEST_NAME} COMMAND ${CTCI_TEST_NAME})
  if(ENABLE_TEST_COVERAGE)
    foreach(lib ${ARGN})
      target_compile_options(${lib} PUBLIC -O0 -g --coverage)
      target_link_options(${lib} PUBLIC --coverage)
    endforeach()
  endif()
endmacro()

# Add tests for each exercise below:
#ctci_add_test(is_unique_brute_force_test is_unique.test.cpp
#              is_unique_brute_force is_unique_bitfield is_unique_sort)

ctci_add_test(reverse_test reverse.test.cpp reverse)

#ctci_add_test(check_permutation_test check_permutation.test.cpp
#              check_permutation_array check_permutation_map)
#
#ctci_add_test(urlify_test urlify.test.cpp urlify)
