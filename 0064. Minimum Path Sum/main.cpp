#include "../catch.hpp"
#include "solution.h"

TEST_CASE("Minimum Path Sum", "[minPathSum]")
{
	Solution s;
	vector<vector<int>> v1 = { {1, 3, 1}, {1, 5, 1}, {4, 2, 1} };
	REQUIRE(s.minPathSum(v1) == 7);
	//REQUIRE(s.minPathSum() == 28);
}