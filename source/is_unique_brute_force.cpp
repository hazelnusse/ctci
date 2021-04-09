#include <ctci/is_unique_brute_force.hpp>

namespace ctci
{

bool is_unique_brute_force(std::string_view sv)
{
    const std::size_t size = sv.size();
    if (size_guarantees_unique(size))
    {
        return true;
    }

    if (size_guarantees_nonunique(size))
    {
        return false;
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
}
