# 思路(C++)

## 思路一
总体来讲，这题的难度不高，初看以为是要按照实例的形状(如图)
```
P   A   H   N
A P L S I I G
Y   I   R
```
输出，这样难度会高一些，但是只要求输出按照行的顺序重新排列的字符串，难度会小一些。
第一种思路，numRows行每行的字母存在一个字符串中，然后从头开始遍历字符串的每个字母，
先从第0行到第numRows - 1行，然后又折回第0行，不断地折返，每到一行都将当前的字符添加到当前行对应的字符串的末尾，
最后依次将各行的字符串拼成一个字符串返回。

这种方法比较自然，也比较容易理解和实现。
复杂度为O(n)

## 思路二
第二种则是依次遍历目标字符串的各个字符，关键在于找出前后字符之间的位置关系。
- 第0行的字符的索引（原始字符串中)为k*(2*numRows- 2), k = 0,1,2...
- 第numRows - 1行的字符的索引为k*(2*numRows - 2) + numRows - 1, k = 0,1,2...
- 中间的第i行的字符的索引为 i + k*(2*numRows - 2)以及(k+1)*(2*numRows - 2) - i

```cpp
#include <string>
#include <vector>
#include <algorithm>
using std::string;
using std::vector;

class Solution
{
public:
	string convert(string s, int numRows)
	{
		if (numRows == 1)	return s;
		size_t n = s.size();
		size_t step = 2 * (numRows - 1);
		string ans_s;
		for (int i = 0; i < numRows; i++)
		{
			
			for (size_t j = 0; j + i < n; j += step)
			{
				ans_s += s[i + j];
				if (i != 0 && i != numRows - 1 && j + step - i < n)
				{
					ans_s += s[j + step - i];
				}
			}
		}
		return ans_s;
	}
};

```