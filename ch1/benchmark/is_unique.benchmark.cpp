#include "is_unique.hpp"

#include <benchmark/benchmark.h>
#include <climits>
#include <random>

std::string generate_random_string(std::size_t N) {
  std::random_device
      rd; // Will be used to obtain a seed for the random number engine
  std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
  std::uniform_int_distribution<std::string_view::value_type> distrib('a', 'z');
  std::string s;
  for (std::size_t i = 0; i < N; ++i) {
    s.push_back(distrib(gen));
  }

  return s;
}

std::string generate_sawtooth_string(std::size_t N) {
  constexpr std::size_t bits_per_char =
      sizeof(std::string::value_type) * CHAR_BIT;
  constexpr std::size_t num_of_unique_chars = 1u << bits_per_char;
  std::string s;
  for (std::size_t i = 0; i < N; ++i) {
    s.push_back(static_cast<std::string::value_type>(i % num_of_unique_chars));
  }

  return s;
}

static void BM_using_bitfield(benchmark::State &state) {
  // auto const test_string = generate_random_string(state.range(0));
  auto const test_string = generate_sawtooth_string(state.range(0));
  for (auto _ : state) {
    benchmark::DoNotOptimize(is_unique::using_bitfield(test_string));
  }
  state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_using_bitfield)
    ->RangeMultiplier(2)
    ->Range(1 << 0, 1 << 8)
    ->Complexity();
BENCHMARK(BM_using_bitfield)
    ->RangeMultiplier(2)
    ->Range(1 << 9, 1 << 12)
    ->Complexity();

static void BM_brute_force(benchmark::State &state) {
  // auto const test_string = generate_random_string(state.range(0));
  auto const test_string = generate_sawtooth_string(state.range(0));
  for (auto _ : state) {
    benchmark::DoNotOptimize(is_unique::brute_force(test_string));
  }
  state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_brute_force)
    ->RangeMultiplier(2)
    ->Range(1 << 0, 1 << 8)
    ->Complexity();
BENCHMARK(BM_brute_force)
    ->RangeMultiplier(2)
    ->Range(1 << 9, 1 << 12)
    ->Complexity();

static void BM_using_sort(benchmark::State &state) {
  // auto const test_string = generate_random_string(state.range(0));
  auto const test_string = generate_sawtooth_string(state.range(0));
  for (auto _ : state) {
    benchmark::DoNotOptimize(is_unique::using_sort(test_string));
  }
  state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_using_sort)
    ->RangeMultiplier(2)
    ->Range(1 << 0, 1 << 8)
    ->Complexity();
BENCHMARK(BM_using_sort)
    ->RangeMultiplier(2)
    ->Range(1 << 9, 1 << 12)
    ->Complexity();

BENCHMARK_MAIN();
