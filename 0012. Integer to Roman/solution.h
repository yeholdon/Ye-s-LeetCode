#pragma once

#include <string>
#include <map>
using std::string;
using std::map;
enum Symbol
{
	I = 1,
	V = 5,
	X = 10,
	L = 50,
	C = 100, 
	D = 500, 
	M = 1000
};
int base_num[7] = { 1, 5, 10, 50, 100, 500, 1000 };
class Solution
{
public:
	string intToRoman(int num) {
		map<int, int, std::greater<int>> m_s2n;
		map<int, char> m_n2c;
		map<int, int> m_s2i;
		string ans;
		for (size_t i = 0; i < 7; i++)
		{
			if (num / base_num[7 - i - 1] > 0)
			{
				m_s2n[base_num[7 - i - 1]] = num / base_num[7 - i - 1];
			}
			num = num % base_num[7 - i - 1];
			m_s2i[base_num[7 - i - 1]] = 7 - i - 1;
		}
		m_n2c[I] = 'I';
		m_n2c[V] = 'V';
		m_n2c[X] = 'X';
		m_n2c[L] = 'L';
		m_n2c[C] = 'C';
		m_n2c[D] = 'D';
		m_n2c[M] = 'M';

		for (map<int, int>::iterator i = m_s2n.begin(); i != m_s2n.end(); i++)
		{
			if (i->second == 4 )
			{
				switch (i->first)
				{
				case I:
					if (m_s2n[V] == 0)
						ans += "IV";
					else
					{
						ans += "IX";
					}
					break;
				case X:
					if (m_s2n[L] == 0)
						ans += "XL";
					else
					{
						ans += "XC";
					}
					break;
				case C:
					if (m_s2n[D] == 0)
						ans += "CD";
					else
					{
						ans += "CM";
					}
					break;
				default:
					break;
				}
			}
			else
			{
				if (m_s2i[i->first] > 0 && m_s2n[base_num[m_s2i[i->first] - 1]] == 4)
				{
					continue;
				}
				ans += string(i->second, m_n2c[i->first]);
			}
		}
		return ans;
	}
};