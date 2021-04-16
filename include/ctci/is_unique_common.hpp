#pragma once
#include <climits>
#include <string_view>

static constexpr std::size_t bits_per_char =
    sizeof(std::string_view::value_type) * CHAR_BIT;
static constexpr std::size_t num_unique_chars = std::size_t{1} << bits_per_char;

inline bool size_guarantees_nonunique(std::size_t size) {
  return size > num_unique_chars;
}

inline bool size_guarantees_unique(std::size_t size) { return size < 2; }
