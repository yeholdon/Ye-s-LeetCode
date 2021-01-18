#include "../catch.hpp"
#include "solution1.h"

TEST_CASE("Maximum Subarray", "[maxSubArray]")
{
	Solution s;
	vector<int> v1{ -2,1,-3,4,-1,2,1,-5,4 };

	REQUIRE(s.maxSubArray(v1) == 6);
}