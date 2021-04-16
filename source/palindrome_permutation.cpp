#include <ctci/palindrome_permutation.hpp>
#include <string>
#include <unordered_map>

namespace ctci {

bool palindrome_permutation(const std::string &s) {
  if (s.size() < 2) {
    return true;
  }

  // construct map of observed characters to character frequency
  std::unordered_map<std::string::value_type, unsigned int> character_map;
  for (auto c : s) {
    if (character_map.count(c)) {
      ++character_map[c];
    } else {
      character_map.emplace(c, 1u);
    }
  }

  unsigned int num_odd = 0;
  for (auto [_, count] : character_map) {
    if (count % 2 != 0) {
      if (++num_odd > 1) {
        return false;
      }
    }
  }

  return true;
}

} // namespace ctci
