#include <ctci/reverse.hpp>

#include <doctest/doctest.h>
#include <string>
// This should not be needed but is due to weird doctest bug, see issue #126
#include <iostream>

TEST_CASE("SimpleReverse") {
  {
    std::string input{"abc"};
    ctci::reverse(input);
    CHECK(input == std::string{"cba"});
  }
  {
    std::string input{"vaginabutthole"};
    ctci::reverse(input);
    CHECK(input == std::string{"elohttubanigav"});
  }
  {
    std::string input{"taint"};
    ctci::reverse(input);
    CHECK(input == std::string{"tniat"});
  }
  {
    std::string input;
    ctci::reverse(input);
    CHECK(input == std::string{""});
  }
  {
    std::string input{"P"};
    ctci::reverse(input);
    CHECK(input == std::string{"P"});
  }
}
