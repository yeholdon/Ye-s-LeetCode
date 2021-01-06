#include "solution1.h"
#include "../catch.hpp"

TEST_CASE("Find First and Last Position of Element in Sorted Array", "[searchRange]")
{
	Solution s;
	vector<int> v1 = { 5,7,7,8,8,10 };
	vector<int> v2 = { 5,7,7,8,8,10 };
	vector<int> v3 = { 2, 2 };
	REQUIRE(s.searchRange(v1, 8) == vector<int>({3, 4}));
	REQUIRE(s.searchRange(v2, 6) == vector<int>({-1, -1}));
	REQUIRE(s.searchRange(v3, 3) == vector<int>({-1, -1}));
}