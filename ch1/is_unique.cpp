#include "is_unique.hpp"

#include <algorithm>
#include <climits>
#include <string>

// Functions which detemrine if a string has all unique characters.
namespace is_unique
{

bool brute_force(std::string_view sv)
{
    if (sv.size() < 2)
    {
        return true;
    }

    // total number of iterations will be n * (n - 1) / 2
    for (auto a = sv.begin(); a != sv.end(); ++a)
    {
        for (auto b = sv.begin(); b != a; ++b)
        {
            if (*a == *b)
            {
                return false;
            }
        }
    }

    return true;
}

bool using_sort(std::string_view sv)
{
    if (sv.size() < 2)
    {
        return true;
    }

    std::string s{sv};              // Copy the string.
    std::sort(s.begin(), s.end());  // Sort the copy in place.
    for (auto a = s.begin(), b = a + 1; b != s.end(); ++a, ++b)
    {
        if (*a == *b)
        {
            return false;
        }
    }

    return true;
}

bool using_bitfield(std::string_view sv)
{
    if (sv.size() < 2)
    {
        return true;
    }

    constexpr std::size_t bits_per_char = sizeof(std::string_view::value_type) * CHAR_BIT;
    constexpr std::size_t num_bytes = (1u << bits_per_char) / bits_per_char;
    unsigned char ar[num_bytes] = {0};
    for (auto c : sv)
    {
        std::size_t byte = static_cast<unsigned char>(c) / bits_per_char;
        std::size_t bit = 1u << (c % bits_per_char);
        if (ar[byte] & bit)
        {
            return false;
        }
        ar[byte] |= bit;
    }
    return true;
}

}
