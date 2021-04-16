#include <cstring>
#include <ctci/reverse.hpp>

namespace ctci {

void reverse(std::string &s) {
  if (s.empty()) {
    return;
  }

  auto last_char = s.end() - 1;
  for (auto first_char = s.begin(); first_char < last_char;) {
    std::string::value_type const tmp = *first_char;
    *first_char++ = *last_char;
    *last_char-- = tmp;
  }
}

} // namespace ctci
