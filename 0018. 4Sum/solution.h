#pragma once
#include <vector>
#include <string>
#include <algorithm>

using std::vector;
using std::string;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        return kSum(nums, target, 0, 4);
    }

    vector<vector<int>> kSum(vector<int>& nums, int target, int s, int k) {
        vector<vector<int>> res;
        if (s == nums.size() || nums[s] * k > target || nums.back() * k < target)
        {
            return res;
        }
        size_t len = nums.size();
        if (k == 2)
        {
            return twoSum(nums, target, s);
        }
        for (size_t i = s; i < len; i++)
        {
            if (i > s && nums[i] == nums[i - 1])
            {
                continue;
            }
            for (auto &v : kSum(nums, target - nums[i], i + 1, k - 1))
            {
                v.push_back(nums[i]);
                res.push_back(v);
            }

        }
        return res;
    }

    vector<vector<int>> twoSum(vector<int>& nums, int target, int start)
    {
        vector<vector<int>> res;
        int l = start, r = nums.size() - 1;
        while (l < r)
        {
            int sum = nums[l] + nums[r];
            if (sum < target || (l < nums.size() - 1 && l > start && nums[l] == nums[l - 1]))
            {
                l++;
            }
            else if (sum > target || (r > start && r < nums.size() - 1 && nums[r] == nums[r + 1]))
            {
                r--;
            }
            else
            {
                res.push_back({ nums[l++], nums[r--] });
            }
        }
        return res;
    }
};