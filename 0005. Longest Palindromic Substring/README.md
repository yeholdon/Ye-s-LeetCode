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
**该方法的巧妙之处在于，通过直接从重复字符组成的子串向两端拓展，避免了重复考虑的同时，也避免了分奇偶两种情况讨论，因为重复字符组成的子串无论奇偶都是回文子串。**
这个方法在字符串的字符都相同时可以达到O(n)，当字符串的字符为"ababababa"这种两个字符交替的情况时，复杂度最大，为O(n^2).
```cpp
#include <string>
using std::string;

class Solution
{
public:
	string longestPalindrome(string s)
	{
		int len = s.length();
		if (len == 1)	return s;
		size_t max_len = 1, max_srt = 0;
		for (size_t i = 0; i < len;)
		{
			// 这里可以加一个优化，即当i右边的字符数小于当前max_len的一半时，说明后面不可能有大于max_len的子串了
			if (len - i <= max_len / 2)	break;
			// 从当前中心起始子串向外拓展
			int j = i, k = i;
			// 分别将j和k设为由当前连续重复字符构成的起始子串的两端
			while (k < len - 1 && s[k] == s[k + 1])	k++;
			// 将i设为k+1，即下一个非重复的字符
			i = k + 1;
			// 从j和k向两端拓展
			while (j > 0 && k < len - 1 && s[j-1] == s[k+1])
			{
				j--;
				k++;
			}
			if (k - j + 1 > max_len)
			{
				max_len = k - j + 1;
				max_srt = j;
			}
		}
		return s.substr(max_srt, max_len);
	}
};
```

## 思路四（Manacher算法）
经典的解决最长回文子串问题的“马拉车”算法。复杂度为O(n)
参见https://segmentfault.com/a/1190000008484167 （不过有点小问题，评论区已指出）
该算法在字符串字符都相同时为最坏情况，为O(n)；字符各不相同时是最坏情况，也是O(n).
### 算法分析
由于回文分为偶回文（比如 bccb）和奇回文（比如 bcacb），而在处理奇偶问题上会比较繁琐，所以这里我们使用一个技巧，具体做法是：在字符串首尾，及各字符间各插入一个字符（前提这个字符未出现在串里）。
举个例子：s="abbahopxpo"，转换为s_new="#a#b#b#a#h#o#p#x#p#o#"（这里的字符 $ 只是为了防止越界，下面代码会有说明），如此，s 里起初有一个偶回文abba和一个奇回文opxpo，被转换为#a#b#b#a#和#o#p#x#p#o#，长度都转换成了奇数。
定义一个辅助数组int p[]，其中p[i]表示以 i 为中心的最长回文的半径，比如p[0] = 1, p[2] = 2.(半径包含中心字符)
这样只要在求p数组的过程中不断更新p[i]中的最大值即可得到最长回文子串。
接下来重点就是求解p数组。

![](https://resource.ethsonliu.com/image/20180403_02.png)
设置两个变量，mx 和 id 。mx 代表以 id 为中心的最长回文的右边界，也就是mx = id + p[id]。

假设我们现在求p[i]，也就是以 i 为中心的最长回文半径，如果i < mx，如上图，那么：
```cpp
if (i < mx)  
    p[i] = min(p[2 * id - i], mx - i);
```
2 * id - i为 i 关于 id 的对称点，即上图的 j 点，而p[j]表示以 j 为中心的最长回文半径，因此我们可以利用p[j]来加快查找。
```cpp
    if (i < mx)
        p[i] = min(p[2 * id - i], mx - i);  // 需搞清楚上面那张图含义, mx 和 2*id-i 的含义
    else
        p[i] = 1;

    while (i - p[i] >= 0 && i + p[i] < s.size() * 2 + 1 && s_new[i - p[i]] == s_new[i + p[i]])  
        p[i]++;
```
这个算法的原理在于，可以借助前面的p[i]的信息计算后面的p[i]，而不需要对每个p[i]都从s_new[i]开始向两端拓展计算，从而降低了复杂度。
![](https://resource.ethsonliu.com/image/20180403_03.png)
如图，由于回文子串的对称性，我们可以借助前面计算得到的p[j]值来更新p[i]值。
