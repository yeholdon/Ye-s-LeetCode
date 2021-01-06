# 思路(C++)

## 二分搜索

STL中有lower_bound和upper_bound两个函数，分别是二分查找数组中第一个大于等于target的数的位置，和第一个大于target的数的位置。利用这两个函数可以以O(log n)的复杂度实现本题的目标。

- 一个注意点就是：二分的初始区间应该为[0, n]因为可能出现target大于nums[n-1]的情况，此时要能够区分。
- 除了lower_bound和upper_bound两个stl函数，还有一个STL函数能直接解决这个问题：equal_range()

```cpp
vector<int> searchRange(vector<int>& nums, int target) {
	auto it = std::equal_range(nums.begin(), nums.end(), target);
	if (it.first != nums.end() and *(it.first) == target) {
		return vector<int> {it.first - nums.begin(), it.second - nums.begin() - 1};    
	} else {
		return vector<int> {-1, -1};
	}
}
```

```cpp
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = lowerBound(nums, target);
        int r = upperBound(nums, target);
        if (nums.size() == 0 || l == nums.size() || nums[l] != target)
        {
            return { -1, -1 };
        }
        vector<int> res = { l, r - 1 };
        return res;
    }

    int lowerBound(vector<int>& nums, int target) {
        int n = nums.size(), low = 0, high = n;
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= target)
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }

    int upperBound(vector<int>& nums, int target) {
        int n = nums.size(), low = 0, high = n;
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] <= target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        return low;
        
    }
};
```

