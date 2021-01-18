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