#include "solution.h"
#include "../catch.hpp"

TEST_CASE("Median of Two Sorted Arrays", "[findMedianSortedArrays]")
{
    Solution s;
    std::vector<int>v1 = { 1, 2 };
    std::vector<int>v2 = { 3, 4 };
    //REQUIRE((s.findMedianSortedArrays(v1, v2) == 2.5));
    REQUIRE((s.findMedianSortedArraysRecursion(v1, v2) == 2.5));
    v1 = { 1 };
    v2 = { 1, 3, 4, 5, 6 };
    //REQUIRE((s.findMedianSortedArrays(v1, v2) == 3.5));
    REQUIRE((s.findMedianSortedArraysRecursion(v1, v2) == 3.5));
}