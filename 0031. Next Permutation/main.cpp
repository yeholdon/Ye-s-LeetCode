#include "solution.h"
#include "../catch.hpp"

TEST_CASE("Next Permutation", "[nextPermutation]")
{
	Solution s;
	vector<int> nums = { 2, 3, 1 }, ans = { 3, 1, 2};
	REQUIRE(s.nextPermutation(nums) == ans);
}