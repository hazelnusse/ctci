#include <is_unique.hpp>

#include <boost/ut.hpp>

int main()
{
    // Some simple examples which are unique.
    for (auto const s: {"", "1", "12", "0123456789"})
    {
        boost::ut::expect(is_unique::brute_force(s) == true);
        boost::ut::expect(is_unique::using_sort(s) == true);
        boost::ut::expect(is_unique::using_bitfield(s) == true);
    }

    // Some simple examples which are not unique.
    for (auto const s: {"11", "121", "Hello world!", "Heaao worad!"})
    {
        boost::ut::expect(is_unique::brute_force(s) == false);
        boost::ut::expect(is_unique::using_sort(s) == false);
        boost::ut::expect(is_unique::using_bitfield(s) == false);
    }

    return 0;
}
