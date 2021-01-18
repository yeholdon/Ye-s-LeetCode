# 思路(C++)

## 组合数的计算

将问题转化为对组合数C(n + m -2, m - 1)的计算。组合数的计算可以利用关系式

- C(n, m) = C(n - 1, m - 1) + C(n - 1, m)

- C(n, m) = 1, 当n == m 或 m = 0

然后递推求解。

```cpp
#pragma once
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        return combi(m - 1, m + n - 2);
    }
    int combi(int m, int n)
    {
        
        if (m > n>>1)
        {
            m = n - m;
        }

        if (m == n || m == 0)
        {
            return 1;
        }
        vector<vector<int>> combi(n + 1, vector<int>(m + 1));
        for (int i = 0; i <= m; i++)
        {
            combi[i][i] = 1;
            for (int j = i + 1; j <= n; j++)
            {
                if (i == 0)
                {
                    combi[j][i] = 1;
                }
                else
                {
                    combi[j][i] = combi[j - 1][i - 1] + combi[j - 1][i];
                }
            }
        }
        return combi[n][m];
    }
};
```

