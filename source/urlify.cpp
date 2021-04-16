#include <ctci/urlify.hpp>
#include <algorithm>
#include <cassert>

namespace ctci
{

void urlify(std::string& s, std::string::size_type true_size)
{
    if (true_size == s.size())
    {
        return;
    }

    assert(true_size < s.size());

    auto const extra_characters = s.size() - true_size;

    assert(extra_characters % 2 == 0);

    auto spaces_remaining = extra_characters / 2;

    auto space_rbegin = s.rbegin();
    auto space_rend = s.rbegin() + extra_characters;

    auto space_to_percent20 = [&spaces_remaining](auto& rbegin, auto rend, auto it) {
        auto num_spaces = it - rend;
        spaces_remaining -= num_spaces;
        while (num_spaces-- > 0)
        {
            *rbegin++ = '0';
            *rbegin++ = '2';
            *rbegin++ = '%';
        }
    };


    while (spaces_remaining > 0)
    {
        bool const is_space = *space_rend == ' ';
        auto it = std::find_if(space_rend, s.rend(),
                [is_space](auto c) { return (c == ' ') != is_space; });
        if (it == s.rend())
        {
            space_to_percent20(space_rbegin, space_rend, it);
        }
        else
        {
            if (is_space)
            {
                space_to_percent20(space_rbegin, space_rend, it);
            }
            else
            {
                space_rbegin = std::rotate(space_rbegin, space_rend, it);
            }
            space_rend = it;
        }
    }
}

}
