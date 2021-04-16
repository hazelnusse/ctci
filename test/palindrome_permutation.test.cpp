#include <ctci/palindrome_permutation.hpp>

#include <boost/ut.hpp>
#include <string>

int main() {
  {
    std::string input{"Tact Coa"};
    ctci::palindrome_permutation(input);
    boost::ut::expect(input == "taco cat");
  }
  {
    std::string input{"Tact Coa"};
    ctci::palindrome_permutation(input);
    boost::ut::expect(input == "atco cta");
  }
}
