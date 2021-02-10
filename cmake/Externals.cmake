include(FetchContent)

if (CTCI_BUILD_TESTS)
    include(CTest)
    FetchContent_Declare(boost.ut
        URL https://github.com/boost-ext/ut/archive/1ed97e36ecc1ad64a12380248942480ce8df97a1.tar.gz
        URL_HASH SHA256=c6878c11f5691e696d6bf2cd371ce351511725cea24810c7f9b07e63012321f0
    )
    set(BOOST_UT_ENABLE_MEMCHECK OFF)
    set(BOOST_UT_ENABLE_COVERAGE OFF)
    set(BOOST_UT_ENABLE_SANITIZERS OFF)
    set(BOOST_UT_ENABLE_RUN_AFTER_BUILD OFF)
    set(BOOST_UT_BUILD_BENCHMARKS OFF)
    set(BOOST_UT_BUILD_EXAMPLES OFF)
    set(BOOST_UT_BUILD_TESTS OFF)
    FetchContent_MakeAvailable(boost.ut)
endif()

FetchContent_Declare(fmt
    URL https://github.com/fmtlib/fmt/archive/7.1.3.tar.gz
    URL_HASH SHA256=5cae7072042b3043e12d53d50ef404bbb76949dad1de368d7f993a15c8c05ecc
)
set(FMT_DOC OFF)
set(FMT_INSTALL OFF)
set(FMT_TEST OFF)
set(FMT_FUZZ OFF)
set(FMT_CUDA_TEST OFF)
set(FMT_OS OFF)
FetchContent_MakeAvailable(fmt)

if (CTCI_BUILD_BENCHMARKS)
    FetchContent_Declare(benchmark
        URL https://github.com/google/benchmark/archive/8df87f6c879cbcabd17c5cfcec7b89687df36953.tar.gz
        URL_HASH SHA256=800112ff3ca87344e034d8f8f2d081c945d218c02a2ab6dc1025a091e29f279e
    )
    set(BENCHMARK_ENABLE_TESTING OFF)
    set(BENCHMARK_ENABLE_EXCEPTIONS ON)
    set(BENCHMARK_ENABLE_LTO ON)
    set(BENCHMARK_ENABLE_INSTALL OFF)
    set(BENCHMARK_DOWNLOAD_DEPENDENCIES OFF)
    set(BENCHMARK_ENABLE_GTEST_TEST OFF)
    FetchContent_MakeAvailable(benchmark)
endif()
