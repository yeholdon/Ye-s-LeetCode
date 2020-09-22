#include "solution.h"
#include "../catch.hpp"
#include <iostream>
TEST_CASE("Letter Combinations of a Phone Number", "[letterCombinations]")
{
    Solution s;
    vector<string> v;
    REQUIRE((s.letterCombinations(string()) == v));
}