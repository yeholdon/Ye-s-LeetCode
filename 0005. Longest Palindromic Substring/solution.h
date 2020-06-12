#include <string>
#include <vector>
#include <algorithm>
using std::string;
using std::array;
using std::vector;

class Solution
{
public:
	string longestPalindrome(string s)
	{
		// 在每两个字符中间添加分隔符，以统一奇偶两种情况
		char splitter = '$';
		int len = s.size();
		vector<int> p(len * 2 + 1, 0);
		string str(len * 2 + 1, 0);
		int pt = 0;
		str[pt++] = splitter;
		for (int i = 0; i < len; i++)
		{
			str[pt++] = s[i];
			str[pt++] = splitter;
		}

		// manacher算法
		int max_len = 0, max_center = 0;
		int center = 0, rboundary = 0;
		// 对称点计算需要索引从1开始
		for (int i = 0; i < len * 2 + 1; i++)
		{
			// 这种情况下，p[i]可以借助前面的p[]得到
			if (i <= rboundary)
			{
				int mirr = center * 2 - i;
				p[i] = std::min(p[mirr], rboundary - i + 1);
			}
			else
			{
				p[i] = 1;
			}
			// 当p[i] == rboundary - i时，rboundary可能需要更新
			while (i - p[i] >= 0 && i + p[i] < len * 2 + 1 && str[i - p[i]] == str[i + p[i]])
			{
				p[i]++;
			}
			// aboundary确实需要更新
			if (rboundary < i + p[i] - 1)
			{
				center = i;
				rboundary = i + p[i] - 1;
			}
			// 更新max_len，p[i] - 1正好等于原字符串中最长回文串的长度
			if (max_len < p[i])
			{
				max_center = i;
				max_len = p[i];
			}

		}
		// 这个由修改后的字符串的最长回文子串的起始字符索引得到原始
		// 字符串的起始回文子串的字符索引的问题也要想清楚，即为什么是(max_center - max_len + 1)/2
		return s.substr((max_center - max_len + 1) / 2, max_len - 1);
	}
};
