# 思路(C++)

## 回溯法

dfs搜索解空间，同时剪枝。注意，保存当前已选的元素的vector<int>变量应该传引用，传值的话会慢非常多，差一个数量级。还有就是push_back()改成emplace_back()也可以提升速度。

```cpp
#pragma once
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> com;
        dfs(res, com, target, 0, candidates, candidates.size());
        return res;
    }
    void dfs(vector<vector<int>>& res, vector<int>& com, int rem, int index, vector<int>& candidates, int len)
    {
        if (rem == 0)
        {
            res.emplace_back(com);
            return;
        }
        if (index >= len || rem < 0)
        {
            return;
        }
        if (candidates[index] < rem)
        {
            dfs(res, com, rem, index + 1, candidates, len);
        }
        if (candidates[index] <= rem)
        {
            com.emplace_back(candidates[index]);
            dfs(res, com, rem - candidates[index], index, candidates, len);
            com.pop_back();
        }
            
    }
    
};
```

