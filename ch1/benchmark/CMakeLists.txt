add_executable(is_unique_benchmark)
target_sources(is_unique_benchmark
    PRIVATE is_unique.benchmark.cpp
)
target_link_libraries(is_unique_benchmark
    PRIVATE benchmark::benchmark_main is_unique
)
