#include "solution.h"
#include "../catch.hpp"
#include <iostream>
TEST_CASE("Longest Palindromic Substring", "[longestPalindrome]")
{
    Solution s;
    std::string str1 = "babad";
    std::string str2 = "bab";
    //REQUIRE((s.findMedianSortedArrays(v1, v2) == 2.5));
    REQUIRE((s.longestPalindrome(str1) == "bab"));
    //REQUIRE((s.findMedianSortedArrays(v1, v2) == 3.5));
    REQUIRE((s.longestPalindrome(str2) == "bab"));
}