#include <string>
using std::string;

class Solution
{
public:
	string longestPalindrome(string s)
	{
		auto len = s.length();
		if (len == 0)
		{
			return s;
		}
		int first = 0, last = 0;
		for (size_t i = 0; i < len - 1; i++)
		{
			longestPalindrome(s, i, i, first, last);
			longestPalindrome(s, i, i + 1, first, last);
		}
		return s.substr(first, last - first + 1);
	}
	// 这里的b,e,fisrt,last索引应该为int型，因为其值可能在运行过程中小于0
	void longestPalindrome(const string &s, int b, int e, int& first, int& last)
	{
		int len = s.length();
		while (b >= 0 && e < len && s[b] == s[e])
		{
			b--;
			e++;
		}
		b++;
		e--;
		if (e - b > last - first)
		{
			last = e;
			first = b;
		}
	}
};
