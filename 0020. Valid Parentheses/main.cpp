#include "solution.h"
#include "../catch.hpp"

TEST_CASE("Valid Parentheses", "[isValid]")
{
	Solution s;
	REQUIRE(s.isValid("()") == true);
	REQUIRE(s.isValid("([)]") == false);
}