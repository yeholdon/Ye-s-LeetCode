#include "solution.h"
#include "../catch.hpp"

TEST_CASE("4Sum", "[fourSum]")
{
	Solution s;
	vector<int> v = { 1, 0, -1, 0, -2, 2 };
	vector<vector<int>> res = 
	{ 
		{-1,  0, 0, 1} ,
		{-2, -1, 1, 2 },
		{-2,  0, 0, 2} 
	};
	REQUIRE(s.fourSum(v, 0) == res);
}