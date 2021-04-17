#include <ctci/one_away.hpp>

namespace ctci {
bool one_away(std::string_view s1, std::string_view s2) {
  if (s1.size() > s2.size() + 1 || s2.size() > s1.size() + 1) {
    return false;
  }

  if (s1.size() == s2.size()) {
    unsigned int num_different{0};
    for (std::string_view::size_type i = 0; i < s1.size(); ++i) {
      if (s1[i] != s2[i]) {
        if (++num_different > 1) {
          return false;
        }
      }
    }

    return true;
  }

  if (s1.size() > s2.size()) {
    auto tmp = s1;
    s1 = s2;
    s2 = tmp;
  }

  for (std::string_view::size_type i = 0, j = 0; i < s1.size(); ++i, ++j) {
    if (s1[i] != s2[j]) {
      ++j;
    }

    if (j > i + 1) {
      return false;
    }
  }

  return true;
}
} // namespace ctci
