#include <ctci/is_unique_bitfield.hpp>
#include <ctci/is_unique_brute_force.hpp>
#include <ctci/is_unique_sort.hpp>

#include <boost/ut.hpp>

int main() {
  for (auto const s : {"", "1", "12", "0123456789"}) {
    boost::ut::expect(ctci::is_unique_bitfield(s) == true);
    boost::ut::expect(ctci::is_unique_brute_force(s) == true);
    boost::ut::expect(ctci::is_unique_sort(s) == true);
  }

  for (auto const s : {"11", "121", "Hello world!", "Heaao worad!"}) {
    boost::ut::expect(ctci::is_unique_brute_force(s) == false);
    boost::ut::expect(ctci::is_unique_bitfield(s) == false);
    boost::ut::expect(ctci::is_unique_sort(s) == false);
  }
}
