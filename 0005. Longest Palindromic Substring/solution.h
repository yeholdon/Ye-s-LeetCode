#include <string>
#include <vector>
#include <algorithm>
using std::string;
using std::array;
using std::vector;

class Solution
{
public:
	string longestPalindrome(string s)
	{
		// ��ÿ�����ַ��м���ӷָ�������ͳһ��ż�������
		char splitter = '$';
		int len = s.size();
		vector<int> p(len * 2 + 1, 0);
		string str(len * 2 + 1, 0);
		int pt = 0;
		str[pt++] = splitter;
		for (int i = 0; i < len; i++)
		{
			str[pt++] = s[i];
			str[pt++] = splitter;
		}

		// manacher�㷨
		int max_len = 0, max_center = 0;
		int center = 0, rboundary = 0;
		// �ԳƵ������Ҫ������1��ʼ
		for (int i = 0; i < len * 2 + 1; i++)
		{
			// ��������£�p[i]���Խ���ǰ���p[]�õ�
			if (i <= rboundary)
			{
				int mirr = center * 2 - i;
				p[i] = std::min(p[mirr], rboundary - i + 1);
			}
			else
			{
				p[i] = 1;
			}
			// ��p[i] == rboundary - iʱ��rboundary������Ҫ����
			while (i - p[i] >= 0 && i + p[i] < len * 2 + 1 && str[i - p[i]] == str[i + p[i]])
			{
				p[i]++;
			}
			// aboundaryȷʵ��Ҫ����
			if (rboundary < i + p[i] - 1)
			{
				center = i;
				rboundary = i + p[i] - 1;
			}
			// ����max_len��p[i] - 1���õ���ԭ�ַ���������Ĵ��ĳ���
			if (max_len < p[i])
			{
				max_center = i;
				max_len = p[i];
			}

		}
		// ������޸ĺ���ַ�����������Ӵ�����ʼ�ַ������õ�ԭʼ
		// �ַ�������ʼ�����Ӵ����ַ�����������ҲҪ���������Ϊʲô��(max_center - max_len + 1)/2
		return s.substr((max_center - max_len + 1) / 2, max_len - 1);
	}
};
