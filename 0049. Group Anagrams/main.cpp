#include "solution.h"
#include "../catch.hpp"

TEST_CASE("Group Anagrams", "[groupAnagrams]")
{
	Solution s;
	//vector<int> v1 = { 1,2,3 };
	vector<string> v1 = { "eat","tea","tan","ate","nat","bat" };
	vector<vector<string>> ans1 = { {"ate","eat","tea"} ,{"nat","tan"},{"bat" } };
	REQUIRE(s.groupAnagrams(v1) == ans1);
	//REQUIRE(s.trap(v2) == 9);
	//REQUIRE(s.searchRange(v3, 3) == vector<int>({ -1, -1 }));
}