#include "solution1.h"
#include "../catch.hpp"
#include <iostream>
TEST_CASE("Regular Expression Matching", "[isMatch]")
{
    Solution s;
    REQUIRE((s.isMatch(s5, p5) == false));

}