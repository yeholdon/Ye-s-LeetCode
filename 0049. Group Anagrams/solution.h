#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <array>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;

        unordered_map<string, vector<int>> map1;
        for (int i = 0; i < strs.size(); i++)
        {
            string strTmp = hash(strs[i]);
            map1[strTmp].push_back(i);
        }

        for (auto& vec : map1)
        {
            vector<string> vecTmp;
            for (auto index : vec.second)
            { 
                vecTmp.push_back(strs[index]);
            }
            ans.push_back(vecTmp);
        }

        return ans;
    }

    string hash(string str)
    {
        int arr[26] = { 0 };
        for (auto ch : str)
            arr[ch - 'a']++;

        string strTmp;
        for (int j = 0; j < 26; j++)
        {
            if (arr[j] > 0)
                strTmp.append(arr[j], j + 'a');
        }
        return strTmp;
    }
};