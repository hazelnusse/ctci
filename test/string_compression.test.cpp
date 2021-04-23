#include <ctci/string_compression.hpp>

#include <boost/ut.hpp>
#include <string>

int main() {
  using boost::ut::expect;
  using boost::ut::test;
  test("aabcccccaaa") = []() {
    expect(ctci::string_compression("aabcccccaaa") == std::string("a2b1c5a3"));
  };
}
