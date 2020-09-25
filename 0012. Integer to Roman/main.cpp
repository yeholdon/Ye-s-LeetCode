#include "solution1.h"
#include "../catch.hpp"
#include <iostream>
TEST_CASE("Integer", "[intToRoman]")
{
    Solution s;
    //REQUIRE((s.intToRoman(3) == "III"));
    //REQUIRE((s.intToRoman(4) == "IV"));
    //REQUIRE((s.intToRoman(9) == "IX"));
    //REQUIRE((s.intToRoman(58) == "LVIII"));
    REQUIRE((s.intToRoman(1994) == "MCMXCIV"));
}