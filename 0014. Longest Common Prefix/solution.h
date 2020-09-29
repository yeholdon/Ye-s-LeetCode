#pragma once
#include <string>
#include <vector>
#include <algorithm>
using std::vector;
using std::string;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int str_n = strs.size();
        if (str_n == 0)   return "";
        size_t min_len = INT_MAX, index = 0;
        for (size_t i = 0; i < str_n; i++)
        {
            if (strs[i].size() == 0) return "";
            if (min_len > strs[i].size())
            {
                min_len = strs[i].size();
                index = i;
            }
        }

        for (int i = 0; i < min_len; i++)
        {
            char c = strs[index][i];
            for (size_t j = 0; j < str_n; j++)
            {
                if (strs[j][i] != c) return strs[index].substr(0, i);
            }
        }
        return strs[index];
    }
};