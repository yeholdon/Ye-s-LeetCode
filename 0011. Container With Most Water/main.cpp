#include "solution.h"
#include "../catch.hpp"

TEST_CASE("Reverse Integer", "[reverse]")
{
    Solution s;
    vector<int> v1 = { 1,8,6,2,5,4,8,3,7 };

    REQUIRE((s.maxArea(v1) == 49));

}