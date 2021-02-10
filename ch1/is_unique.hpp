#pragma once

#include <climits>
#include <string_view>

namespace is_unique
{

// Sort using a bit field that has a bit for each possible character: O(n)
bool using_bitfield(std::string_view sv);

// Brute force approach: O(n^2)
bool brute_force(std::string_view sv);

// Sorting approach: O(n log n)
bool using_sort(std::string_view sv);

static constexpr std::size_t bits_per_char = sizeof(std::string_view::value_type) * CHAR_BIT;
static constexpr std::size_t num_unique_chars = 1u << bits_per_char;

inline bool size_guarantees_nonunique(std::size_t size)
{
    return size > num_unique_chars;
}

inline bool size_guarantees_unique(std::size_t size)
{
    return size < 2;
}
}
