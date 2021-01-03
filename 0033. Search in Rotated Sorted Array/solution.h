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
        int rotaPoint = searchRotaPoint(nums);
        int index1 = binarySearch(nums, 0, rotaPoint, target);
        int index2 = binarySearch(nums, rotaPoint + 1, n - 1, target);
        if (index1  == -1 && index2 == -1)
        {
            return -1;
        }
        else
        {
            if (index1 != -1)
            {
                return index1;
            }
            else
            {
                return index2;
            }
        }
        return -1;
    }

    int searchRotaPoint(vector<int>& nums)
    {
        int n = nums.size();
        int low = 0, high = n - 1;
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] > nums[mid+1] )
            {
                return mid;
            }
            if (nums[mid] < nums[low])
            {
                high = mid;
            }
            else if (nums[mid] > nums[high])
            {
                low = mid + 1;
            }
            else
                return -1; // 
        }
        return -1;
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
            else if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return -1;
    }
};