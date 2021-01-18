#include "../catch.hpp"
#include "solution.h"

TEST_CASE("Unique Paths", "[uniquePaths]")
{
	Solution s;
	REQUIRE(s.uniquePaths(3, 2) == 3);
	REQUIRE(s.uniquePaths(3, 7) == 28);
}