#include "solution.h"
#include "../catch.hpp"
#include <iostream>
TEST_CASE("Longest Common Prefix", "[longestCommonPrefix]")
{
    Solution s;
    vector<string> strs1 = { "flower","flow","flight" };
    vector<string> strs2 = { "dog","racecar","car" };
    REQUIRE((s.longestCommonPrefix(strs1) == "fl"));
    REQUIRE((s.longestCommonPrefix(strs2) == ""));
}