#include<cstdio>
#include<string>
#include<vector>
using std::string;
using std::vector;
using std::pair;

class Solution
{
public:
	string longestPalindrome(string s)
	{
		size_t L = s.size();
		vector<vector<bool>> dp(L, vector<bool>(L, false));
		auto p = init(s, dp);
		for (size_t r = 3; r <= L; r++)
		{
			for (size_t i = 0; i < L - r + 1; i++)
			{
				if (s[i] == s[i+r-1] && dp[i+1][i+r-2] == true)
				{
					dp[i][i + r - 1] = true;
					if (p.first < r)
					{
						p.first = r;
						p.second = s.substr(i, r);
					}

				}
			}
		}
		return p.second;
	}
	pair<size_t, string> init(const string &s, vector<vector<bool>> &dp)
	{
		size_t len = s.length();
		pair<size_t, string> p(1, s.substr(0, 1));
		for (size_t i = 0; i < len; i++)
		{
			dp[i][i] = true;
			if (i < len - 1)
			{
				if (s[i] == s[i + 1])
				{
					dp[i][i + 1] = true;
					if (p.first == 1)
					{
						p.first = 2;
						p.second = s.substr(i, 2);
					}
				}
				else
				{
					dp[i][i + 1] = false;
				}
			}
		}
		return p;
	}

};


