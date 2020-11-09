#pragma once
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.size();
        int max_len = 0;
        vector<int> dp(len);
        for (int i = 1; i < len; i++)
        {
            if (s[i] == ')')
            {
                if (s[i - 1] == '(')
                {
                    dp[i] = (i > 1 ? dp[i - 2] : 0) + 2;
                }
                else if (s[i - 1] == ')' && i - dp[i - 1] - 1 >= 0 && s[i - 1 - dp[i-1]] == '(')
                {
                    dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
                max_len = max(max_len, dp[i]);
            }
        }
        return max_len;
    }

};