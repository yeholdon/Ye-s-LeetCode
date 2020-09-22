#include "solution.h"
#include "../catch.hpp"

TEST_CASE("Merge k Sorted Lists", "[mergeKLists]")
{
	Solution s;
	vector<ListNode*> v;
	REQUIRE(s.mergeKLists(v) == nullptr);
}