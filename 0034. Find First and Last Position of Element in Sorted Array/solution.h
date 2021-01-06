#pragma once
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto l = lower_bound(nums.begin(), nums.end(), target);
        auto r = upper_bound(nums.begin(), nums.end(), target);
        if (nums.size() == 0 || l == nums.end() || *l != target)
        {
            return { -1, -1 };
        }
        vector<int> res = { int(l - nums.begin()), int(r - nums.begin() - 1) };
        return res;
    }
};