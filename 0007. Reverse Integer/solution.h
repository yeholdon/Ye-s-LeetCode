#include <string>
#include <algorithm>
using std::string;

class Solution
{
public:
	int reverse(int x) {
		auto s = std::to_string(x);
		string ans_s;
		if (x < 0)
		{
			ans_s.push_back('-');
			for (size_t i = s.size() - 1; i > 0; i--)
			{
				ans_s.push_back(s[i]);
			}
		}
		else
		{
			for (int i = s.size() - 1; i >= 0; i--)
			{
				ans_s.push_back(s[i]);
			}
		}
		auto ans_ll =  std::stoll(ans_s);
		if (std::abs(ans_ll) > INT_MAX) return 0;
		else return (int)ans_ll;
	}
}; 