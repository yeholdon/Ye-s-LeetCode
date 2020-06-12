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