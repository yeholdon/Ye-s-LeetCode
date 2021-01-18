#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int last = 0;
        int len = nums.size();
        for (int i = 0; i < len; i++)
        {
            if (last >= i)
            {
                last = max(last, nums[i] + i);
            }
            else
                return false;
            if (last >= len - 1)
            {
                return true;
            }
        }
        return false;
    }
};