#include <string>
using std::string;

class Solution {
public:
    int romanToInt(string s) {
		int ans = 0;
		for (size_t i = 0; i < s.length(); i++)
		{
			if (i < s.length() - 1 && charToInt(s[i]) < charToInt(s[i+1]) )
			{
				ans -= charToInt(s[i]);
			}
			else
			{
				ans += charToInt(s[i]);
			}
		}
		return ans;
    }

	int charToInt(char c) {
		int ans = 0;
		switch (c)
		{
		case 'I':
			ans = 1;
			break;
		case 'V':
			ans = 5;
			break;
		case 'X':
			ans = 10;
			break;
		case 'L':
			ans = 50;
			break;
		case 'C':
			ans = 100;
			break;
		case 'D':
			ans = 500;
			break;
		case 'M':
			ans = 1000;
			break;
		default:
			ans = 0;
			break;
		}
		return ans;
	}
};