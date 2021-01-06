#pragma once
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0;
        int len = static_cast<int>(height.size());
        if (len == 0)   return 0;
        vector<int> left_max(height.size()), right_max(height.size());
        left_max[0] =  height[0];
        right_max[len - 1] = height[len - 1];
        for (int i = 1; i < len; i++)
        {
            left_max[i] = max(left_max[i - 1], height[i]);
            right_max[len - i - 1] = max(right_max[len - (i - 1) - 1], height[len - i - 1]);
        }
        for (int i = 0; i < len; i++)
        {
            sum += min(left_max[i], right_max[i]) - height[i];
        }
        return sum;
    }
};