#include <cstring>
#include <ctci/reverse.hpp>

namespace ctci {

void reverse(char *first_char) {
  if (first_char == nullptr) {
    return;
  }

  char *last_char = first_char + std::strlen(first_char) - 1;
  while (first_char < last_char) {
    char const tmp = *first_char;
    *first_char++ = *last_char;
    *last_char-- = tmp;
  }
}

} // namespace ctci
