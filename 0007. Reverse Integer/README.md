# 思路(C++)

这题唯一的难点在于接近INT最大值的数倒置会溢出。要准确判断出溢出的情况。
## 思路一（转成long long)
这是容易想到且可行的方法，但是不够优雅，一旦题目变成64位的integer就失效了。但是在本题中也不失为一种方法。
另外还可以借助std::to_string() 和 std::stoi(), std::stoll()。进行string和整型的转换。
由于最初没有考虑到转换后可能溢出int范围的问题，使用了std::stoi()将超过INT_MAX的值转化为int会导致溢出。
对这个问题，只要使用std::stoll()转换为long long即可，再结合与INT_MAX的大小判断即可。

## 思路二(用除10取余结合溢出判断)
由于在不用long long存reverse结果的前提下，无法用可能溢出的结果直接与INT_MAX比较。因此难点在于如何在不溢出的情况下进行比较，判断出溢出的情况。
对于这个问题，可以分别判断最低位和其余位和INT_MAX/INT_MIN的最低位和其余位的大小，将整个数拆分出来比较。
还有就是INT_MAX及INT_MIN的使用，该宏定义在<limits.h>中，另外还有INT8_MAX、INT32_MAX、INT64_MAX等等，定义在<stdint.h>中。
```cpp
#include <climits>
class Solution
{
public:
	int reverse(int x) {
		int ans_i = 0;
		while (x)
		{
			if (x / 10 == 0)
			{
				if (ans_i > INT_MAX / 10) return 0;
				else if (ans_i == INT_MAX / 10 && x > INT_MAX % 10)
				{
					return 0;
				}
				if (ans_i < INT_MIN / 10) return 0;
				else if (ans_i == INT_MIN / 10 && x < INT_MIN % 10)
				{
					return 0;
				}
			}
			ans_i = ans_i * 10 + x % 10;
			x /= 10;
		}
		return ans_i;
	}
};
```