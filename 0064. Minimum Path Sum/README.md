# 思路(C++)

直观上，这题贪心选向右和向左中数字较小的方向前进肯定不行，可以很容易找出反例。考虑动态规划的方法。

- 最优子结构：设`mat[i][j]`表示从位置(i, j)到右下角的最小路径和，则`mat[i][j]`可以由`mat[i+1][j]`和`mat[i][j+1]`表示, `mat[i][j] = grid[i][j] + min(mat[i+1][j], mat[i][j+1])`.
- 重叠子问题：这个很容易得到, (i, j) -> (i+1, j)和(i, j+1); (i-1, j+1) -> (i, j+1)和(i-1, j+2)可见有重叠子问题。
- 边界条件：`mat[m-1][n-1] = grid[m-1][n-1]`
- 实现上，为了方便处理边界情况，特别是j+1 == m或者i+1 == n的情况，(此时`mat[i][j] = grid[i][j] + mat[i][j+1]`或者`mat[i][j] = grid[i][j] + mat[i+1][j]`)，可以创建一个m+1 * n+1的mat数组。`mat[m][n]` = 0 ,其余`mat[m][j]`和`mat[i][n]`均设置为INT_MAX。

```cpp
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        dp[m][n - 1] = dp[m - 1][n] = 0;
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                dp[i][j] = grid[i][j] + min(dp[i + 1][j], dp[i][j + 1]);
            }
        }
        return dp[0][0];
    }
};
```



