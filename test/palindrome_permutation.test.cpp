#include <ctci/palindrome_permutation.hpp>

#include <boost/ut.hpp>

int main() {
  using boost::ut::expect;
  using boost::ut::test;
  using ctci::palindrome_permutation;
  test("empty") = []() { expect(palindrome_permutation("") == true); };

  test("length1") = []() { expect(palindrome_permutation("a") == true); };

  test("length2") = []() {
    expect(palindrome_permutation("aa") == true);
    expect(palindrome_permutation("ab") == false);
  };

  test("length3") = []() {
    expect(palindrome_permutation("aba") == true);
    expect(palindrome_permutation("abc") == false);
  };

  test("length4") = []() {
    expect(palindrome_permutation("abba") == true);
    expect(palindrome_permutation("aBba") == false);
    expect(palindrome_permutation("bbba") == false);
  };

  test("length5") = []() { expect(palindrome_permutation("abcde") == false); };

  test("length7") = []() { expect(palindrome_permutation("aabbbaa") == true); };
}
