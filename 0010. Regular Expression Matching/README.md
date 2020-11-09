# 思路(C++)

## 思路一（递归）

递归比较容易理解，但是也有很多细节需要注意。

- 边界条件：`if(p.empty())	return s.empty();`这里要注意，开始我还加了`if(s.empty())	return p.empty()`但是这其实是有问题的，因为可能出现这样一种情况，s已经empty，但是p还剩下一个'*'，这种情况是有可能match的，比如"abcd"和"abcd *"。

- 递归式：由于最后的结果是由当前字符匹配的结果以及剩余字串的匹配结果共同决定的。剩余字串的匹配结果用递归调用表示，当前字符的匹配结果根据以下条件获取。首先，为了防止越界，要加入s.empty()的判断；然后，情况一就是当前字符与模式串的当前字符相同，或者当前模式串的字符为'.'，可以匹配任意字符，这种情况下直接返回当前字符和剩余字串的匹配结果相&&的结果即可；情况二则是处理存在'*'的情况，由于' *'要和它前面的字符一起来看，一种是"字符 *"匹配0个字符，则直接进入isMatch(s, p.substr(2))的递归，或者另一种情况，匹配一个或者多个字符。

  这种方法的时间复杂度和空间复杂度都很不好计算，leetcode里的solution也讲的很不清楚，暂时还没有找到合适的解答。

  

## 思路二（DP）

用`dp[i][j]`表示s[0...i) 和p[0...j)是否匹配。为true表示匹配，否则为不匹配。注意，由于要考虑字符串为 空的情况，作为边界值，所以dp数组的大小为(m+1)*(n+1), m = s.size(), n = p.size().

状态转移方程如下：

1. `dp[i][j] = dp[i-1][j-1], if p[j - 1] != '*' && (s[i - 1] == p[j - 1] || p[j - 1] == '.');`
2. `dp[i][j] = dp[i][j - 2]`, if `p[j - 1] == '*'` 且pattern仅重复0次，即‘字符*’的模式没有匹配任何字符
3. `dp[i][j] = dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.')`, if `p[j - 1] == '*'` 且pattern重复至少一次。

还要注意就是外层循环即以m为边界的循环的起始值应该为0，内层则为1.这是因为目标串为空时，匹配结果也可能为true，比如模式串全为"字符*"的情况。而模式串为空时，除了目标串也为空，否则匹配结果不可能为true；同时，为了避免数组下标小于0，出现s[i-1]的地方要与上i.

[参考链接](https://leetcode.com/problems/regular-expression-matching/discuss/5684/C%2B%2B-O(n)-space-DP)


