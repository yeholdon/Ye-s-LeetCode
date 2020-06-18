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