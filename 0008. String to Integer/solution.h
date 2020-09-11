#pragma once

/*
author:ye
title:8. String to Integer (atoi)
my answer
*/
#include <string>

using std::string;
enum type
{
	Neg = -1,
	Inv,
	Pos,
};
class Solution
{
public:
	int myAtoi(string str)
	{
		size_t j = 0, len = str.length();
		long long ans = 0;
		type flag = Inv;
		while (j < len)
		{
			if (str[j] == ' ')
			{
				j++;
			}
			else if (str[j] == '-' || str[j] == '+')
			{
				flag = str[j] == '-' ? Neg : Pos;
				j++;
				break;
			}
			else if (str[j] >= '0' && str[j] <= '9')
			{
				flag = Pos;
				break;
			}
			else
			{
				flag = Inv;
				break;
			}
		}

		if (flag == Inv)
		{
			return 0;
		}

		while (j < len && str[j] >= '0' && str[j] <= '9')
		{
			ans = ans * 10 + (str[j++] - '0');
			if (ans * flag > INT_MAX)
			{
				return INT_MAX;
			}
			if (ans * flag < INT_MIN)
			{
				return INT_MIN;
			}
		}
		return ans * flag;
	}
};

