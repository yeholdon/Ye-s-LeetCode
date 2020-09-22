#pragma once
#include <vector>
#include <algorithm>
using std::vector;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ans;
		int size = nums.size();
		std::sort(nums.begin(), nums.end());
		for (size_t i = 0; i < size; i++)
		{
			int target = -nums[i];
			int left = i + 1, right = size - 1;
			vector<int> triplet(3, 0);
			triplet[0] = nums[i];
			while (left < right)
			{
				int sum = nums[left] + nums[right];
				if (sum < target)
				{
					left++;
				}
				else if (sum > target)
				{
					right--;
				}
				else
				{
					
					triplet[1] = nums[left];
					triplet[2] = nums[right];
					ans.push_back(triplet);
					while (left < right && nums[left] == triplet[1])
					{
						left++;
					}
					while (left < right && nums[right] == triplet[2])
					{
						right--;
					}
				}
			}
			while (i+1 < size && nums[i+1] == nums[i])
			{
				i++;
			}
		}
		return ans;
    }
};