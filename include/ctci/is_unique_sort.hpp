#pragma once

#include <ctci/is_unique_common.hpp>
#include <string_view>

namespace ctci {

// Sorting approach: O(n log n)
bool is_unique_sort(std::string_view sv);

} // namespace ctci
