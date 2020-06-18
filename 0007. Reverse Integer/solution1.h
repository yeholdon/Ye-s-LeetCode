#include <climits>
class Solution
{
public:
	int reverse(int x) {
		int ans_i = 0;
		while (x)
		{
			if (x / 10 == 0)
			{
				if (ans_i > INT_MAX / 10) return 0;
				else if (ans_i == INT_MAX / 10 && x > INT_MAX % 10)
				{
					return 0;
				}
				if (ans_i < INT_MIN / 10) return 0;
				else if (ans_i == INT_MIN / 10 && x < INT_MIN % 10)
				{
					return 0;
				}
			}
			ans_i = ans_i * 10 + x % 10;
			x /= 10;
		}
		return ans_i;
	}
};