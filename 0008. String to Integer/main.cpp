#include "solution.h"
#include "../catch.hpp"

TEST_CASE("Reverse Integer", "[reverse]")
{
    Solution s;
    string s1 = "12454";
    string s2 = "-974583";
    string s3 = "   124";
    string s4 = " k345";
    string s5 = "  94758347kjdf";
    string s6 = "  9475834711kjdf";
    REQUIRE((s.myAtoi(s1) == 12454));
    REQUIRE((s.myAtoi(s2) == -974583));
    REQUIRE((s.myAtoi(s3) == 124));
    REQUIRE((s.myAtoi(s4) == 0));
    REQUIRE((s.myAtoi(s5) == 94758347));
    REQUIRE((s.myAtoi(s6) == INT_MAX));
}