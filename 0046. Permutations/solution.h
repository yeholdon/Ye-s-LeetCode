#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = (int)nums.size();
        vector<bool> vis(n, false);
        vector<int> temp;
        vector<vector<int>> ans;
        backTracking(nums, temp, vis, ans, 0);
        return ans;
    }
    void backTracking(vector<int>& nums, vector<int>& temp, vector<bool> &vis, vector<vector<int>> &ans, int cnt)
    {
        if (cnt >= nums.size())
        {
            ans.emplace_back(temp);
            return;
        }
        for (int i = 0; i < vis.size(); i++)
        {
            if (vis[i] == false)
            {
                vis[i] = true;
                temp.emplace_back(nums[i]);
                backTracking(nums, temp, vis, ans, cnt + 1);
                temp.pop_back();
                vis[i] = false;
            }
        }
    }
};