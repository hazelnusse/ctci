#include <ctci/urlify.hpp>

#include <boost/ut.hpp>
#include <string>

TEST_CASE("SimpleUrlifyTest") {
  {
    std::string input{"Mr John Smith    "};
    ctci::urlify(input, 13);
    CHECK(input == std::string{"Mr%20John%20Smith"});
  }
  {
    std::string input{"Mr   John   Smith            "};
    ctci::urlify(input, 17);
    CHECK(input == std::string{"Mr%20%20%20John%20%20%20Smith"});
  }
  {
    std::string input{"Mr   John   Smith               "};
    ctci::urlify(input, 18);
    CHECK(input == std::string{"Mr%20%20%20John%20%20%20Smith%20"});
  }
  {
    std::string input{" Mr   John   Smith                 "};
    ctci::urlify(input, 19);
    CHECK(input == std::string{"%20Mr%20%20%20John%20%20%20Smith%20"});
  }
  {
    std::string input{"  Mr   John   Smith                   "};
    ctci::urlify(input, 20);
    CHECK(input == std::string{"%20%20Mr%20%20%20John%20%20%20Smith%20"});
  }
}
