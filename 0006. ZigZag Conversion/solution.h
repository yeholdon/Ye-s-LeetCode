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
		// border situation
		if (numRows == 1)    return s;
		vector<string> v(std::min(numRows, (int)s.size()));
		size_t curRow = 0;
		int up_down = -1; // start with 'up'
		for (auto c : s)
		{
			v[curRow] += c;
			if (curRow == 0 || curRow == numRows - 1) up_down = -up_down;
			curRow += up_down;
		}
		string ans_s = "";
		for (auto e : v)
		{
			ans_s += e;
		}
		return ans_s;
	}

	string convert1(string s, int numRows)
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