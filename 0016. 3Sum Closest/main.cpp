#include "solution.h"
#include "../catch.hpp"

TEST_CASE("3Sum", "[threeSum]")
{
    Solution s;
    vector<int> v1 = { -1,2,1,-4 };
    //vector<vector<int>> ans1 = { {-1,-1,2} ,{-1,0,1} };
    REQUIRE((s.threeSumClosest(v1, 1) == 2));

}