#include <ctci/check_permutation_array.hpp>
#include <array>
#include <climits>

namespace ctci
{

using array = std::array<unsigned int, 1u << (sizeof(std::string_view::value_type) * CHAR_BIT)>;

void populate_array(array &a, std::string_view s)
{
    for (auto c: s)
    {
        ++a[c];
    }
}

bool check_permutation_array(std::string_view a, std::string_view b)
{
    if (a.size() != b.size())
    {
        return false;
    }

    array aa{0}, ab{0};

    populate_array(aa, a);
    populate_array(ab, b);

    for (array::size_type i = 0; i < aa.size(); ++i)
    {
        if (aa[i] != ab[i])
        {
            return false;
        }
    }

    return true;
}

}
