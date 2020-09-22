#pragma once
#include <string>
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0) return false;
        int sum = 0, y = x;
        while (y > 0)
        {
            sum = sum * 10 + y % 10;
            y /= 10;
            if (sum > INT_MAX / 10) break;
        }
        return (sum == x);
    }
};