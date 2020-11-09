#pragma once
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.size();
        vector<vector<int>> dp(len, vector<int>(len));
        vector<int> count(len);
        for (size_t i = 0; i < len; i++)
        {
            if (s[i] == '(')
            {
                dp[i][i] = 1;
            }
            else
            {
                dp[i][i] = 0;
            }
        }
        int max_len = 0;
        for (size_t i = 0; i < len; i++)
        {
            for (size_t j = i + 1; j < len; j++)
            {
                if (s[j] == '(')
                {
                    dp[i][j] = dp[i][j - 1] + 1;
                }
                else
                {
                    if (dp[i][j - 1] > 1)
                    {
                        dp[i][j] = dp[i][j - 1] - 1;
                        count[i]++;
                    }
                    else if (dp[i][j - 1] == 1)
                    {
                        dp[i][j] = dp[i][j - 1] - 1;
                        count[i]++;
                        max_len = max(max_len, count[i]);
                    }
                    else
                    {
                        break;
                    }
                }

            }
        }
        return max_len * 2;
    }
};