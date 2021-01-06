#include "solution1.h"
#include "../catch.hpp"

TEST_CASE("Combination Sum", "[combinationSum]")
{
	Solution s;
	vector<int> v1 = { 0,1,0,2,1,0,1,3,2,1,2,1 };
	vector<int> v2 = { 4,2,0,3,2,5 };
	vector<int> v3 = { 2, 2 };
	REQUIRE(s.trap(v1) == 6);
	REQUIRE(s.trap(v2) == 9);
	//REQUIRE(s.searchRange(v3, 3) == vector<int>({ -1, -1 }));
}