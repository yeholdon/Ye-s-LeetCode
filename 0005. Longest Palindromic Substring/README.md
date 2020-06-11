# 思路(C++)

## 思路一
常规遍历法，时间复杂度O(n^2), 但是写起来比较简洁，思路也清晰。
对于每一个起始的单字符或者两个相同的连续字符的情况，不断向两端拓展直至不是回文子串。

```c
#include <string>
using std::string;

class Solution {
    void longestPalindrome(const string& s, int b, int e, int &start, int &last) {
        int len = s.size();
        while (b >= 0 && e < len && s[b] == s[e])
            --b, ++e;
        ++b, --e;
        if (e - b > last - start) {
            start = b;
            last = e;
        }
    }

public:
    string longestPalindrome(string s) {
        int len = s.size();
        if (len == 0) return s;
        int start = 0, last = 0;
        for (int i=0; i<len-1; ++i) {
            longestPalindrome(s, i, i, start, last);
            longestPalindrome(s, i, i+1, start, last);
        }
        return s.substr(start, last-start+1);
    }
};
```
测试结果40ms
## 思路二
DP(动态规划）：复杂度O(n^2).
dp[i][j] 为bool型，为true代表字串s[i]~s[j]为回文子串，否则则为非回文子串。且状态转移方程为dp[i+1][j-1]到dp[i][j]因此是从中间到两端。这和其它的一些状态转移方式不同。因此循环变量应该为回文子串的长度，边界条件要分回文子串长度为奇数和偶数两种情况讨论，即计算dp[i][i+1]和dp[i][i]的值。对从3开始的每个长度都判断整个字符串所有当前长度的回文子串的头尾字符是否相等，并结合次头尾字符的dp[i+1][j-1]值得到dp[i][j]的值。这种方法写起来比较麻烦，代码也比较复杂，复杂度也比较高。

测试结果500~600ms左右

## 思路三
类似思路一，只不过可以利用连续重复字符的特点，在遍历每个起始回文中心字符的时候，直接将两端指针指向连续重复子串的两端再向外拓展，这样可以避免将重复的字符作为中心字符进行判断，从而优化。比如abbbc这个字符串里，以三个b中间的b作为起始字符向外拓展得到的最长回文子串必然是以这三个b作为起始字符向外拓展的情况中最长的。这种方法只在有重复连续字符的情况下有优化效果，其他情况下的复杂度还是O(n^2)

```cpp
#include <string>
#include <vector>
using std::string;

const int maxn = 1010;
// dp array
int dp[maxn][maxn] = { 0 };
size_t ans = 1, idxl = 0;
class Solution {
public:
	string longestPalindrome(string s) {
		if (s.empty()) return "";
		if (s.size() == 1) return s;
		int min_start = 0, max_len = 1;
		for (int i = 0; i < s.size();) {
			if (s.size() - i <= max_len / 2) break;
			int j = i, k = i;
			while (k < s.size() - 1 && s[k + 1] == s[k]) ++k; // Skip duplicate characters.
			i = k + 1;
			while (k < s.size() - 1 && j > 0 && s[k + 1] == s[j - 1]) { ++k; --j; } // Expand.
			int new_len = k - j + 1;
			if (new_len > max_len) { min_start = j; max_len = new_len; }
		}
		return s.substr(min_start, max_len);
	}

};
```
## 思路四（Manacher算法）
经典的解决最长回文子串问题的“马拉车”算法。复杂度为O(n)
参见https://segmentfault.com/a/1190000008484167 （不过有点小问题，评论区已指出）



