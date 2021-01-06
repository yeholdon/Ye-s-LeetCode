#include "solution.h"
#include "../catch.hpp"

TEST_CASE("Permutations", "[permute]")
{
	Solution s;
	vector<int> v1 = { 1,2,3 };
	vector<int> v2 = { 4,2,0,3,2,5 };
	vector<int> v3 = { 2, 2 };
	vector<vector<int>> ans1 = { {1,2,3} ,{1,3,2},{2,1,3 }, { 2,3,1 }, { 3,1,2 }, { 3,2,1 } };
	REQUIRE(s.permute(v1) == ans1);
	//REQUIRE(s.trap(v2) == 9);
	//REQUIRE(s.searchRange(v3, 3) == vector<int>({ -1, -1 }));
}