# 思路(C++)

这题虽然答案写的是用贪心的思想，但是和一般意义上的贪心问题还是有所不同，这里没有按照策略贪心地选择一个子问题求解这样的情况。不过也可以看成是对于每个位置都贪心地走到最远能到的地方。

依次遍历数组中的每一个位置，并实时维护 最远可以到达的位置。对于当前遍历到的位置 x，如果它在 最远可以到达的位置 的范围内，那么我们就可以从起点通过若干次跳跃到达该位置，因此我们可以用x+nums[x] 更新 最远可以到达的位置。

在遍历的过程中，如果 最远可以到达的位置 大于等于数组中的最后一个位置，那就说明最后一个位置可达，我们就可以直接返回 True 作为答案。反之，如果在遍历结束后，最后一个位置仍然不可达，我们就返回 False 作为答案。

```cpp
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int last = 0;
        int len = nums.size();
        for (int i = 0; i < len; i++)
        {
            if (last >= i)
            {
                last = max(last, nums[i] + i);
            }
            else
                return false;
            if (last >= len - 1)
            {
                return true;
            }
        }
        return false;
    }
};
```

