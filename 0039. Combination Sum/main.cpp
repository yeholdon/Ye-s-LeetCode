#include "solution.h"
#include "../catch.hpp"

TEST_CASE("Combination Sum", "[combinationSum]")
{
	Solution s;
	vector<int> v1 = { 2,3,6,7 };
	vector<int> v2 = { 5,7,7,8,8,10 };
	vector<int> v3 = { 2, 2 };
	vector<vector<int>> res1 = { {2, 2, 3}, {7} };
	REQUIRE(s.combinationSum(v1, 7) == res1);
	//REQUIRE(s.searchRange(v2, 6) == vector<int>({ -1, -1 }));
	//REQUIRE(s.searchRange(v3, 3) == vector<int>({ -1, -1 }));
}