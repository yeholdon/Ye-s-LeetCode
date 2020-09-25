#include "solution.h"
#include "../catch.hpp"
#include <iostream>
TEST_CASE("Roman to integer", "[romanToInt]")
{
    Solution s;
    REQUIRE((s.romanToInt("III") == 3));
    REQUIRE((s.romanToInt("LVIII") == 58));
    REQUIRE((s.romanToInt("MCMXCIV") == 1994));
}