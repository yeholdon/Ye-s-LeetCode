#pragma once
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        // to make it run faster, don't use map and set, instead, compare directly
        unordered_set<char> sl = { '(', '[', '{' }, sr = { ')', ']', '}' };
        unordered_map<char, char> ml = { {'(', ')'}, {'[', ']'}, {'{', '}'} };
        for (auto& c : s)
        {
            if (sl.count(c))
            {
                st.push(c);
            }
            else if (sr.count(c))
            {
                if (st.empty())
                {
                    return false;
                }
                if (c == ml[st.top()])
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        return st.empty();
    }
};