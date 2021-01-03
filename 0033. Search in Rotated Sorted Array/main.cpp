#include "solution1.h"
#include "../catch.hpp"

TEST_CASE("Search in Rotated Sorted Array", "[search]")
{
	Solution s;
	vector<int> v1 = { 4,5,6,7,0,1,2 };
	vector<int> v2 = { 1, 2, 0 };
	vector<int> v3 = { 1, 0 };
	REQUIRE(s.search(v1, 0) == 4);
	REQUIRE(s.search(v2, 3) == -1);
	REQUIRE(s.search(v3, 0) == 1);
}