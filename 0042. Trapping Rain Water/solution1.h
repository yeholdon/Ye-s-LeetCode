#pragma once
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0;
        stack<int> st;
        int len = static_cast<int>(height.size());
        if (len == 0)   return 0;
        vector<int> left_max(height.size()), right_max(height.size());
        for (int i = 0; i < len; i++)
        {
            while (!st.empty() && height[st.top()] < height[i])
            {
                int top = st.top();
                st.pop();
                if (st.empty()) // 从栈顶第二个位置开始算
                {
                    break;
                }
                int dis = i - st.top() - 1;
                int relaHeight = min(height[i], height[st.top()]) - height[top];
                sum += dis * relaHeight;
            }
            st.push(i);
        }
        return sum;
    }
};