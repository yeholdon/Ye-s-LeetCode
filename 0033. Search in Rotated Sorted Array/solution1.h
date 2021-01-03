#pragma once
#pragma once
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        return binarySearch(nums, 0, n - 1, target);
    }


    int binarySearch(vector<int>& nums, int low, int high, int target)
    {
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < nums[high])
            {
                // right half is in order
                if (target <= nums[high] && nums[mid] < target)
                {
                    low = mid + 1;
                }
                else
                    high = mid - 1;
            }
            else
            {
                if (target >= nums[low] && target < nums[mid])
                {
                    high = mid - 1;
                }
                else
                    low = mid + 1;
            }
        }
        return -1;
    }
};