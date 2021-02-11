# Exercise 1.1
add_library(is_unique)
target_sources(is_unique
    PRIVATE is_unique_brute_force.cpp is_unique_using_bitfield.cpp is_unique_using_sort.cpp
)
target_include_directories(is_unique
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)
target_compile_options(is_unique
    PRIVATE -fstack-usage
)
target_compile_features(is_unique
    PUBLIC cxx_std_17               # Need for std::string_view
)

if(CTCI_BUILD_TESTS)
    add_subdirectory(test)
endif()

if(CTCI_BUILD_BENCHMARKS)
    add_subdirectory(benchmark)
endif()
