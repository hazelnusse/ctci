#include <ctci/check_permutation_array.hpp>
#include <ctci/check_permutation_map.hpp>

#include <doctest/doctest.h>

TEST_CASE("SimpleCheckPermutation")
{
    CHECK(ctci::check_permutation_map("12", "123") == false);
    CHECK(ctci::check_permutation_map("12", "123456") == false);
    CHECK(ctci::check_permutation_map("1234567890", "0123456789") == true);
    CHECK(ctci::check_permutation_array("12", "123") == false);
    CHECK(ctci::check_permutation_array("12", "123456") == false);
    CHECK(ctci::check_permutation_array("1234567890", "0123456789") == true);
}
