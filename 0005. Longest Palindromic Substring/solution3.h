#include <string>
using std::string;

class Solution
{
public:
	string longestPalindrome(string s)
	{
		int len = s.length();
		if (len == 1)	return s;
		size_t max_len = 1, max_srt = 0;
		for (size_t i = 0; i < len;)
		{
			// ������Լ�һ���Ż�������i�ұߵ��ַ���С�ڵ�ǰmax_len��һ��ʱ��˵�����治�����д���max_len���Ӵ���
			if (len - i <= max_len / 2)	break;
			// �ӵ�ǰ������ʼ�Ӵ�������չ
			int j = i, k = i;
			// �ֱ�j��k��Ϊ�ɵ�ǰ�����ظ��ַ����ɵ���ʼ�Ӵ�������
			while (k < len - 1 && s[k] == s[k + 1])	k++;
			// ��i��Ϊk+1������һ�����ظ����ַ�
			i = k + 1;
			// ��j��k��������չ
			while (j > 0 && k < len - 1 && s[j-1] == s[k+1])
			{
				j--;
				k++;
			}
			if (k - j + 1 > max_len)
			{
				max_len = k - j + 1;
				max_srt = j;
			}
		}
		return s.substr(max_srt, max_len);
	}
};