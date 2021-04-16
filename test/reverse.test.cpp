#include <ctci/reverse.hpp>

#include <boost/ut.hpp>
#include <string>

int main() {
  {
    std::string input{"abc"};
    ctci::reverse(input);
    boost::ut::expect(input == "cba");
  }
  {
    std::string input{"vaginabutthole"};
    ctci::reverse(input);
    boost::ut::expect(input == "elohttubanigav");
  }
  {
    std::string input{"taint"};
    ctci::reverse(input);
    boost::ut::expect(input == "tniat");
  }
  {
    std::string input;
    ctci::reverse(input);
    boost::ut::expect(input == "");
  }
  {
    std::string input{"P"};
    ctci::reverse(input);
    boost::ut::expect(input == "P");
  }
}
