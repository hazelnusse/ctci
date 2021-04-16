#pragma once

#include <ctci/is_unique_common.hpp>
#include <string_view>

namespace ctci {

// Brute force approach: O(n^2)
bool is_unique_brute_force(std::string_view sv);

} // namespace ctci
