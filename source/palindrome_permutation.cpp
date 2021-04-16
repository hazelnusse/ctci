#include <ctci/palindrome_permutation.hpp> #include <string>
#include <unordered_map>

namespace ctci {

bool palindrome_permutation(const std::string &s)
{
    if (s.size() < 2)
    {
        return true;
    }

    // construct map of observed characters to character frequency
    std::unordered_map<std::string::value_type, unsigned int> character_map;
    for (auto c : s)
    {
      if (character_map.count(c))
      {
          ++character_map[c];
      }
      else
      {
          character_map.emplace(c, 1u);
      }
    }

    // Check if input is a permutation of a palindrome based on input size
    unsigned int odd_character_freq{0};
    bool even_character_freq{true};
    if (s.size() % 2 == 0)
    {
        for (auto c : s)
        {
            if ( character_map[c] % 2 != 0)
            {
                return false;
            }
        }
    }
    else // input string has an an odd number of characters
    {
        for (auto c : s)
        {
            if ( character_map[c] % 2 != 0)
            {
                ++odd_character_freq;
                if (odd_character_freq > 1)
                {
                    return false;
                }
            }
        }
    }

    return true;
}

} // namespace ctci
