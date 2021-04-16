#include <ctci/check_permutation_map.hpp>

#include <map>

namespace ctci {

void populate_map(std::map<std::string_view::value_type, unsigned int> &m,
                  std::string_view s) {
  for (auto c : s) {
    if (m.count(c) == 0) {
      m.emplace(c, 1);
    } else {
      ++m[c];
    }
  }
}

bool check_permutation_map(std::string_view a, std::string_view b) {
  if (a.size() != b.size()) {
    return false;
  }

  std::map<std::string_view::value_type, unsigned int> ma, mb;
  populate_map(ma, a);
  populate_map(mb, b);

  return ma == mb;
}

} // namespace ctci
