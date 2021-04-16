#include <ctci/check_permutation_array.hpp>
#include <ctci/check_permutation_map.hpp>

#include <boost/ut.hpp>

int main() {
  boost::ut::expect(ctci::check_permutation_map("12", "123") == false);
  boost::ut::expect(ctci::check_permutation_map("12", "123456") == false);
  boost::ut::expect(ctci::check_permutation_map("1234567890", "0123456789") ==
                    true);
  boost::ut::expect(ctci::check_permutation_array("12", "123") == false);
  boost::ut::expect(ctci::check_permutation_array("12", "123456") == false);
  boost::ut::expect(ctci::check_permutation_array("1234567890", "0123456789") ==
                    true);
}
