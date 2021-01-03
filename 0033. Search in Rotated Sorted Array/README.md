# 思路(C++)

## 一、二分搜索

一般的对于有序数组的二分搜素复杂度就是O(log n)。这里只是做了一点变化。只要找到顺序倒转的点就可以转换回二分搜索的情况。

- 寻找倒转点：从左往右找这样的复杂度为O(n)。容易想到，找倒转点也可以用二分搜索。这样两次二分搜索，总的复杂度就不会超过O(log n)了。
- 二分搜索找倒转点的策略，首先是判断下一轮搜索的子区间——策略是判断A[mid]和A[low]以及A[high]的大小关系，若A[mid]<A[low]则子区间为A[low...mid]，若A[mid]>A[high]则子区间为A[mid+1...high]，另外，这里虽然题目写了保证数组必然被倒转，但是实际上还是会有没有被倒转的测试样例，所以还需要考虑两者都不满足的情况，这时仅需返回-1即可; 然后是搜索完成的条件，若A[mid] > A[mid+1]则表示搜索到了倒转点。

- 找到倒转点时候，只需在两个有序区间中分别二分查找即可。

```cpp
#pragma once
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int rotaPoint = searchRotaPoint(nums);
        int index1 = binarySearch(nums, 0, rotaPoint, target);
        int index2 = binarySearch(nums, rotaPoint + 1, n - 1, target);
        if (index1  == -1 && index2 == -1)
        {
            return -1;
        }
        else
        {
            if (index1 != -1)
            {
                return index1;
            }
            else
            {
                return index2;
            }
        }
        return -1;
    }

    int searchRotaPoint(vector<int>& nums)
    {
        int n = nums.size();
        int low = 0, high = n - 1;
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] > nums[mid+1] )
            {
                return mid;
            }
            if (nums[mid] < nums[low])
            {
                high = mid;
            }
            else if (nums[mid] > nums[high])
            {
                low = mid + 1;
            }
            else
                return -1; // 
        }
        return -1;
    }

    int binarySearch(vector<int>& nums, int low, int high, int target)
    {
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return -1;
    }
};
```

## 二、直接二分搜索

直接进行二分搜索，只不过在判断下一轮搜索子区间的时候，要分处于单调递增的一半还是有倒转的一半来处理。

- 如果A[mid] < A[high]则右半段是单调递增的，否则左半段是有序的；只需在有序的半段里用target和首尾元素比较即可判断target是否在该段中了
- 注意点是判断target和首尾元素大小的时候，要注意除了mid一端另一端要包含"=="情况

```cpp
#pragma once
#pragma once
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        return binarySearch(nums, 0, n - 1, target);
    }


    int binarySearch(vector<int>& nums, int low, int high, int target)
    {
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < nums[high]) // right half is in order
            {
                // attention! "<="
                if (target <= nums[high] && nums[mid] < target)
                {
                    low = mid + 1;
                }
                else
                    high = mid - 1;
            }
            else
            {
                if (target >= nums[low] && target < nums[mid])
                {
                    high = mid - 1;
                }
                else
                    low = mid + 1;
            }
        }
        return -1;
    }
};
```

