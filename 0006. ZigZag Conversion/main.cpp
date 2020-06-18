#include "solution.h"
#include "../catch.hpp"
#include <iostream>
TEST_CASE("ZigZag Conversion", "[convert]")
{
    Solution s;
    std::string str1 = "PAYPALISHIRING";
    int numRow1 = 3;
    std::string str2 = "PAYPALISHIRING";
    int numRow2 = 4;
    //REQUIRE((s.findMedianSortedArrays(v1, v2) == 2.5));
    REQUIRE((s.convert(str1, numRow1) == "PAHNAPLSIIGYIR"));
    //REQUIRE((s.findMedianSortedArrays(v1, v2) == 3.5));
    REQUIRE((s.convert(str2, numRow2) == "PINALSIGYAHRPI"));
}