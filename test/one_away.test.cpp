#include <ctci/one_away.hpp>

#include <boost/ut.hpp>
#include <string>

int main() {
  using boost::ut::expect;
  using boost::ut::test;
  test("EqualLength") = []() {
    expect(ctci::one_away("Pale", "Bale") == true);
    expect(ctci::one_away("Pale", "Bake") == false);
  };
  test("UnequalLength") = []() {
    expect(ctci::one_away("Pale", "Ple") == true);
    expect(ctci::one_away("Pales", "Pale") == true);
    expect(ctci::one_away("Pales", "Pble") == false);
    expect(ctci::one_away("Pales", ";lakdsjla;ksjfPble") == false);
  };
}
