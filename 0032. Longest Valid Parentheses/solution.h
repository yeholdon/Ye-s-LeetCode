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
        for (size_t i = 0; i < len; i++)
        {
            for (size_t j = i + 2; j <= len; j++)
            {
                if (isValid(s.substr(i, j - i)))
                {
                    max_len = max(max_len, int(j - i));
                }
            }
        }
        return max_len;
    }

    bool isValid(string s)
    {
        stack<char> st;
        for (size_t i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                st.push(s[i]);
            }
            else if (s[i] == ')' && !st.empty())
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
        return st.empty();
    }
};