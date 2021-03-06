#pragma once
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		vector<int> dp(nums.size());
		dp[0] = nums[0];
		int ans = nums[0];
		for (int i = 1; i < nums.size(); i++)
		{
			dp[i] = max(dp[i - 1] + nums[i], nums[i]);
			ans = max(dp[i], ans);
		}
		return ans;
	}
};
