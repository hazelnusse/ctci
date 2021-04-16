#include <ctci/urlify.hpp>

#include <boost/ut.hpp>
#include <string>

int main() {
  {
    std::string input{"Mr John Smith    "};
    ctci::urlify(input, 13);
    boost::ut::expect(input == "Mr%20John%20Smith");
  }
  {
    std::string input{"Mr   John   Smith            "};
    ctci::urlify(input, 17);
    boost::ut::expect(input == "Mr%20%20%20John%20%20%20Smith");
  }
  {
    std::string input{"Mr   John   Smith               "};
    ctci::urlify(input, 18);
    boost::ut::expect(input == "Mr%20%20%20John%20%20%20Smith%20");
  }
  {
    std::string input{" Mr   John   Smith                 "};
    ctci::urlify(input, 19);
    boost::ut::expect(input == "%20Mr%20%20%20John%20%20%20Smith%20");
  }
  {
    std::string input{"  Mr   John   Smith                   "};
    ctci::urlify(input, 20);
    boost::ut::expect(input == "%20%20Mr%20%20%20John%20%20%20Smith%20");
  }
}
