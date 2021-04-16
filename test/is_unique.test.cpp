#include <ctci/is_unique_bitfield.hpp>
#include <ctci/is_unique_brute_force.hpp>
#include <ctci/is_unique_sort.hpp>

#include <boost/ut.hpp>

TEST_CASE("SimpleUnique") {
  for (auto const s : {"", "1", "12", "0123456789"}) {
    CHECK(ctci::is_unique_bitfield(s) == true);
    CHECK(ctci::is_unique_brute_force(s) == true);
    CHECK(ctci::is_unique_sort(s) == true);
  }
}

TEST_CASE("SimpleNonUnique") {
  for (auto const s : {"11", "121", "Hello world!", "Heaao worad!"}) {
    CHECK(ctci::is_unique_brute_force(s) == false);
    CHECK(ctci::is_unique_bitfield(s) == false);
    CHECK(ctci::is_unique_sort(s) == false);
  }
}
