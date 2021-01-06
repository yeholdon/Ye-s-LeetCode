#pragma once
/************
* ֱ����lower_bound��upper_bound�Ľⷨ��֪Ϊ�αȽ���
* ���������Լ�ʵ��
*************/

#pragma once
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = lowerBound(nums, target);
        int r = upperBound(nums, target);
        if (nums.size() == 0 || l == nums.size() || nums[l] != target)
        {
            return { -1, -1 };
        }
        vector<int> res = { l, r - 1 };
        return res;
    }

    int lowerBound(vector<int>& nums, int target) {
        int n = nums.size(), low = 0, high = n;
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= target)
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }

    int upperBound(vector<int>& nums, int target) {
        int n = nums.size(), low = 0, high = n;
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] <= target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        return low;
        
    }
};
