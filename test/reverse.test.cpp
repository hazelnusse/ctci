#include <ctci/reverse.hpp>

#include <doctest/doctest.h>
#include <string>

TEST_CASE("SimpleReverse") {
  {
    std::string input{"abc"};
    ctci::reverse(input);
    CHECK(input == "cba");
  }
  {
    std::string input{"vaginabutthole"};
    ctci::reverse(input);
    CHECK(input == "elohttubanigav");
  }
  {
    std::string input{"taint"};
    ctci::reverse(input);
    CHECK(input == "tniat");
  }
  {
    std::string input;
    ctci::reverse(input);
    CHECK(input == "");
  }
  {
    std::string input{"P"};
    ctci::reverse(input);
    CHECK(input == "P");
  }
}
