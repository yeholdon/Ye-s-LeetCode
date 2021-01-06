# 思路(C++)

## 一、动态规划

每个位置上能蓄的水量，等于其两侧最高位置中较小的那一个减去该位置的高度。因此，首先需要获取每个位置两侧的最高位置。这个可以直接暴力对每个位置向两侧寻找，但是这样复杂度会达到O(n^2)。这里考虑动态规划的思想，可以把复杂度降到O(n)。

首先，分析最优子结构，设left_max[i]为位置i左侧的最高位置的高度(包括位置i)，则left_max[i+1] = max(height[i+1], left_max[i])。右侧同理，可见问题的最优解包含子问题的最优解，具有最优子结构。

其次，分析重叠子问题，这个容易得到，因为计算得到left_max[i+1]需要left_max[i], left_max[i]又需要left_max[i-1]。因此问题left_max[i+1]和left_max[i]的子问题是重叠的。

最后，在获得left_max[]和right_max[]后，遍历一遍数组，按照以下公式计算各个位置能蓄的水量: min(left_max[i], right_max[i]) - height[i]。然后同时累加该值即可。

```cpp
#pragma once
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0;
        int len = static_cast<int>(height.size());
        if (len == 0)   return 0;
        vector<int> left_max(height.size()), right_max(height.size());
        left_max[0] =  height[0];
        right_max[len - 1] = height[len - 1];
        for (int i = 1; i < len; i++)
        {
            left_max[i] = max(left_max[i - 1], height[i]);
            right_max[len - i - 1] = max(right_max[len - (i - 1) - 1], height[len - i - 1]);
        }
        for (int i = 0; i < len; i++)
        {
            sum += min(left_max[i], right_max[i]) - height[i];
        }
        return sum;
    }
};
```



## 二、栈

除了按照每个位置来计算蓄水量，也可以按照层来计算。但是按照层来计算就涉及到跟踪各层端点的问题，这个容易用栈来解决。先把高度依次递减的位置下标都入栈，直到遇到高度大于栈顶的位置，栈顶不断出栈，直到栈顶高度大于当前位置的高度。在出栈过程中依次计算该层的水量，由于连续的两个位置之间不能蓄水，所以这个蓄水是当前位置和栈顶位置的下一个位置之间所围成的层的水量。

```cpp
#pragma once
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0;
        stack<int> st;
        int len = static_cast<int>(height.size());
        if (len == 0)   return 0;
        vector<int> left_max(height.size()), right_max(height.size());
        for (int i = 0; i < len; i++)
        {
            while (!st.empty() && height[st.top()] < height[i])
            {
                int top = st.top();
                st.pop();
                if (st.empty()) // 从栈顶第二个位置开始算
                {
                    break;
                }
                int dis = i - st.top() - 1;
                int relaHeight = min(height[i], height[st.top()]) - height[top];
                sum += dis * relaHeight;
            }
            st.push(i);
        }
        return sum;
    }
};
```

## 三、Two Pointers

和方法 2 相比，我们不从左和从右分开计算，我们想办法一次完成遍历。
从动态编程方法的示意图中我们注意到，只要right\_max[i]>left\_max[i]，right_max[i]>left_max[i] （元素 0 到元素 6），积水高度将由 left_max 决定，类似地left_max[i]>right_max[i]（元素 8 到元素 11）。
所以我们可以认为如果一端有更高的条形块（例如右端），积水的高度依赖于当前方向的高度（从左到右）。当我们发现另一侧（右侧）的条形块高度不是最高的，我们则开始从相反的方向遍历（从右到左）。
我们必须在遍历时维护left_max 和right_max ，但是我们现在可以使用两个指针交替进行，实现 1 次遍历即可完成。

> 这个方法属于前面动规方法的改进，虽然比较难以想到，但是以后再遇到这种数组中某个中间位置的属性需要由两端元素的情况共同决定的问题就可以往这个方向考虑。

作者：LeetCode
链接：https://leetcode-cn.com/problems/trapping-rain-water/solution/jie-yu-shui-by-leetcode/

