#include <ctci/reverse.hpp>

#include <string_view>
#include <doctest/doctest.h>

TEST_CASE("SimpleReverse")
{
    {
        char input[] = "abc";
        ctci::reverse(input);
        CHECK(std::string_view(input) == "cba");
    }
    {
        char input[] = "vaginabutthole";
        ctci::reverse(input);
        CHECK(std::string_view(input) == "elohttubanigav");
    }
    {
        char input[] = "";
        ctci::reverse(input);
        CHECK(std::string_view(input) == "");
    }
    {
        char input[] = "P";
        ctci::reverse(input);
        CHECK(std::string_view(input) == "P");
    }
}
