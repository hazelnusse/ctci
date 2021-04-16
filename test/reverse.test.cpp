#include <ctci/reverse.hpp>

#include <doctest/doctest.h>
#include <string>

TEST_CASE("SimpleReverse") {
  {
    char input[] = "abc";
    ctci::reverse(input);
    CHECK(std::string(input) == "cba");
  }
  {
    char input[] = "vaginabutthole";
    ctci::reverse(input);
    CHECK(std::string(input) == "elohttubanigav");
  }
  {
    char input[] = "taint";
    ctci::reverse(input);
    CHECK(std::string(input) == "tniat");
  }
  {
    char input[] = "";
    ctci::reverse(input);
    CHECK(std::string(input) == "");
  }
  {
    char input[] = "P";
    ctci::reverse(input);
    CHECK(std::string(input) == "P");
  }
}
