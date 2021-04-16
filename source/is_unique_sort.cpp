#include <ctci/is_unique_sort.hpp>

#include <algorithm>
#include <string>

namespace ctci {

bool is_unique_sort(std::string_view sv) {
  const std::size_t size = sv.size();
  if (size_guarantees_unique(size)) {
    return true;
  }

  if (size_guarantees_nonunique(size)) {
    return false;
  }

  std::string s{sv};             // Copy the string.
  std::sort(s.begin(), s.end()); // Sort the copy in place.
  for (auto a = s.begin(), b = a + 1; b != s.end(); ++a, ++b) {
    if (*a == *b) {
      return false;
    }
  }

  return true;
}

} // namespace ctci
