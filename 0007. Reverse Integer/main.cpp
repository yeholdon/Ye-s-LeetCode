#include "solution1.h"
#include "../catch.hpp"
#include <iostream>
TEST_CASE("Reverse Integer", "[reverse]")
{
    Solution s;
    int a1 = -1234;
    int a2 = -1534236469;
    REQUIRE((s.reverse(a1) == -4321));
    REQUIRE((s.reverse(a2) == 0));
}