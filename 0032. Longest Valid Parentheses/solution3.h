#pragma once
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.size();
        int max_len = 0;
        stack<int> st;
        st.push(-1);
        for (int i = 0; i < len; i++)
        {
            if (s[i] == '(')
            {
                st.push(i);
            }
            else
            {
                st.pop();
                if (st.empty())
                {
                    st.push(i);
                }
                else
                {
                    max_len = max(max_len, i - st.top());
                }
            }
        }
        return max_len;
    }

};