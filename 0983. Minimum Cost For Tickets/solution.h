#pragma once
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
	int duration[3] = { 1, 7, 30 };
	vector<int> dp;
	vector<int> days, costs;
    int mincostTickets(vector<int>& days, vector<int>& costs) {
		this->days = days;
		this->costs = costs;
		dp.assign(days.size(), -1); // 直接只考虑那些要旅行的日子
		return DP(0);
    }

	int DP(int i)
	{
		if (i >= days.size())
		{
			return 0;
		}
		if (dp[i] != -1)
		{
			return dp[i];
		}
		dp[i] = INT_MAX;
		int j = i;
		for (size_t k = 0; k < 3; k++)
		{
			while (j < days.size() && days[j] < days[i] + duration[k])
			{
				j++;
			}
			dp[i] = min(dp[i], DP(j) + costs[k]);
		}
		return dp[i];
	}
	
};