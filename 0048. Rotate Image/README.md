# 思路(C++)

## 一、找规律

这题其实就是找出某个元素位置坐标的变化规律，然后解决原地旋转更新数组的问题。

- 坐标变化规律即元素的原始坐标(x, y)和经过旋转后变成的坐标(x', y')的关系。经过举例，不难得到(x', y') = (y, n - 1 - x) 设旋转后的数组为mn，原始数组是m，则`mn[x'][y'] = mn[y][n - 1 - x] = m[x][y]`
- 但是如果直接按照公式原地赋值的话，`m[y][n-1-x]`就会被覆盖，另外，从一个点开始不断其旋转后的坐标，再找从该旋转后的点旋转后的坐标，可以发现，经过四次这样的寻找，就会回到原来的(x, y)点。所以可以先将回到(x,y)前的最后一个点暂存，然后不断用其前一个点的值覆盖当前点，最后把暂存的值赋给(x, y)。
- 还有一个问题就是要搞清楚该枚举哪些起始点才能完成整个数组的原地旋转。这个问题可以结合具体例子，分为矩阵长度n为奇偶两种情况讨论，对于n为偶数的情况，分别处于下图四个区域中的四个点构成一组循环，因此枚举时只要枚举x[0...n/2]，y[0...n/2]即左上角这一块的位置即可；n为奇数时，同理只要枚举左上角的x[0...n/2]，y[0...(n+1)/2]这一块的点即可。中心的点不变。

![](https://gitee.com/yeholdon/imagebed/raw/master/img/20210106161500.png)

![](https://gitee.com/yeholdon/imagebed/raw/master/img/20210106161520.png)

```cpp
#pragma once
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = (int)matrix.size();
        int temp = 0;
        for (int i = 0; i < n/2; i++)
        {
            for (int j = 0; j < (n+1)/2; j++)
            {
                temp = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = matrix[i][j];
                matrix[i][j] = temp;
            }
        }
    }
};
```

## 二、用翻转代替旋转

这里的旋转可以用一次上下对称翻转和一次对角线翻转来替代。

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // 水平翻转
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < n; ++j) {
                swap(matrix[i][j], matrix[n - i - 1][j]);
            }
        }
        // 主对角线翻转
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/rotate-image/solution/xuan-zhuan-tu-xiang-by-leetcode-solution-vu3m/
```

