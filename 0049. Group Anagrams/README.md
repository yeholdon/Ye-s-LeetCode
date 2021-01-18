  # 思路(C++)

## 字符串hash

关键在于设计哈希函数，使得字母异位词的hash值相同。

- 这里设计的hash函数是将字符异位词的字母重新按照26个字母的顺序排列，排列后的字符串设为hash值。然后具有相同hash值的字符串组成一组。
- hash函数就是将每个字母异位词按照字典序排序。
- 由于互为字母异位词的两个字符串包含的字母相同，因此两个字符串中的相同字母出现的次数一定是相同的，故可以将每个字母出现的次数使用字符串表示，作为哈希表的键。

```cpp
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
```



