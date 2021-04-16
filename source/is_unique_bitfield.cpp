#include <ctci/is_unique_bitfield.hpp>

namespace ctci {

bool is_unique_bitfield(std::string_view sv) {
  const std::size_t size = sv.size();
  if (size_guarantees_unique(size)) {
    return true;
  }

  if (size_guarantees_nonunique(size)) {
    return false;
  }

  constexpr std::size_t num_bytes = num_unique_chars / bits_per_char;
  unsigned char ar[num_bytes] = {0};
  for (auto c : sv) {
    std::size_t byte = static_cast<unsigned char>(c) / bits_per_char;
    std::size_t bit = std::size_t{1} << (c % bits_per_char);
    if (ar[byte] & bit) {
      return false;
    }
    ar[byte] |= bit;
  }
  return true;
}

} // namespace ctci
