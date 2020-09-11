#include "solution1.h"
#include "../catch.hpp"

TEST_CASE("Reverse Integer", "[reverse]")
{
    Solution s;
    int s1 = 12421;
    int s2 = -974583;
    int s3 = 2147483647;
    //string s4 = " k345";
    //string s5 = "  94758347kjdf";
    //string s6 = "  9475834711kjdf";
    REQUIRE((s.isPalindrome(s1) == true));
    REQUIRE((s.isPalindrome(s2) == false));
    REQUIRE((s.isPalindrome(s3) == false));
    //REQUIRE((s.myAtoi(s4) == 0));
    //REQUIRE((s.myAtoi(s5) == 94758347));
    //REQUIRE((s.myAtoi(s6) == INT_MAX));
}