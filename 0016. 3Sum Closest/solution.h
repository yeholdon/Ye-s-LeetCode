#pragma once
#include <vector>
#include <algorithm>
#include <cmath>
using std::vector;

class Solution
{
public:
    int threeSumClosest(vector<int>& nums, int target) {
		//vector<vector<int>> ans;
		int size = nums.size();
		std::sort(nums.begin(), nums.end());
		int min_dis = INT_MAX;
		int min_allsum = 0;
		for (size_t i = 0; i < size; i++)
		{
			int left = i + 1, right = size - 1;
			while (left < right)
			{
				int allsum = nums[left] + nums[right] + nums[i];
				int dis = std::abs(allsum - target);
				if (dis < min_dis)
				{
					min_dis = dis;
					min_allsum = allsum;
				}
				if (allsum < target)
				{
					left++;
				}
				else if (allsum > target)
				{
					right--;
				}
				else
				{
					return target;
				}
			}
			while (i+1 < size && nums[i+1] == nums[i])
			{
				i++;
			}
		}
		return min_allsum;
    }
};