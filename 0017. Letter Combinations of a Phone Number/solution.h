#pragma once
#include <vector>
#include <string>
#include <unordered_map>
using std::vector;
using std::string;
using std::unordered_map;

class Solution {
public:
    vector<string> ans = {};
    unordered_map<int, string> m =
    {
        {2, "abc"},
        {3, "def"},
        {4, "ghi"},
        {5, "jkl"},
        {6, "mno"},
        {7, "pqrs"},
        {8, "tuv"},
        {9, "wxyz"}
    };

    vector<string> letterCombinations(string digits) {
        if (digits.length() != 0)
        {
            recursive("", digits);
        }

        return ans;
    }
    void recursive(string combi, string next_digits)
    {
        if (next_digits.empty())
        {
            ans.push_back(combi);
            return;
        }
        int j = next_digits[0] - '0';
        for (size_t i = 0; i < m[j].size(); i++)
        {
            recursive(combi + m[j][i], next_digits.substr(1));
        }
    }

};