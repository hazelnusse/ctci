# Exercise 1.1
add_library(is_unique)
target_sources(is_unique
    PRIVATE is_unique.cpp
    PUBLIC is_unique.hpp
)
target_include_directories(is_unique
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

if(CTCI_BUILD_TESTS)
    add_subdirectory(test)
endif()

if(CTCI_BUILD_BENCHMARKS)
    add_subdirectory(benchmark)
endif()
