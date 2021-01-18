#pragma once
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
class Solution {
public:
	struct Status {
		int lSum, rSum, mSum, iSum;
	};

	Status pushUp(Status l, Status r)
	{
		int iSum = l.iSum + r.iSum;
		int lSum = max(l.lSum, l.iSum + r.lSum);
		int rSum = max(r.rSum, l.rSum + r.iSum);
		int mSum = max(l.rSum + r.lSum, max(l.mSum, r.mSum));
		return Status{ lSum, rSum, mSum, iSum };
	}

	Status get(vector<int>& a, int l, int r)
	{
		if (l == r)
		{
			return Status{ a[l], a[l], a[l], a[l] };
		}
		int m = (l + r) >> 1;
		Status lPart = get(a, l, m);
		Status rPart = get(a, m + 1, r);
		return pushUp(lPart, rPart);
	}
	int maxSubArray(vector<int>& nums) {
		return get(nums, 0, nums.size() - 1).mSum;
	}
};
