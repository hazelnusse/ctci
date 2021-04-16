#pragma once

#include <ctci/is_unique_common.hpp>
#include <string_view>

namespace ctci {

// Sort using a bit field that has a bit for each possible character: O(n)
bool is_unique_bitfield(std::string_view sv);

} // namespace ctci
