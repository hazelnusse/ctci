#pragma once

#include <string_view>

namespace is_unique
{

// Brute force approach: O(n^2)
bool brute_force(std::string_view sv);

// Sorting approach: O(n log n)
bool using_sort(std::string_view sv);

// Sort using a bit field that has a bit for each possible character: O(n)
bool using_bitfield(std::string_view sv);

}
