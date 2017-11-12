#include <iostream>
#include <string>
#include <vector>

/*
1003. ��Ҫͨ����(20)

ʱ������
400 ms
�ڴ�����
65536 kB
���볤������
8000 B
�������
Standard
����
CHEN, Yue
������ȷ�����Զ�����ϵͳ�����������˻�ϲ�Ļظ�����������PAT�ġ�����ȷ�������� ���� ֻҪ������ַ�����������������ϵͳ�����������ȷ��������������𰸴��󡱡�

�õ�������ȷ���������ǣ�

1. �ַ����б������P, A, T�������ַ��������԰��������ַ���
2. �������� xPATx ���ַ��������Ի�á�����ȷ�������� x �����ǿ��ַ����������ǽ�����ĸ A ��ɵ��ַ�����
3. ��� aPbTc ����ȷ�ģ���ô aPbATca Ҳ����ȷ�ģ����� a, b, c �������ǿ��ַ����������ǽ�����ĸ A ��ɵ��ַ�����

���ھ�����ΪPATдһ���Զ����г����ж���Щ�ַ����ǿ��Ի�á�����ȷ���ġ�
�����ʽ�� ÿ�������������1��������������1�и���һ����Ȼ��n (<10)������Ҫ�����ַ���������������ÿ���ַ���ռһ�У��ַ������Ȳ�����100���Ҳ������ո�

�����ʽ��ÿ���ַ����ļ����ռһ�У�������ַ������Ի�á�����ȷ���������YES���������NO��

����������
8
PAT
PAAT
AAPATAA
AAPAATAAAA
xPATx
PT
Whatever
APAAATAA
���������
YES
YES
YES
YES
NO
NO
NO
NO
*/

using namespace std;

bool IsPass(string& s)
{
	size_t p = s.find('P');
	for (size_t i = 0; i < p; ++i)
	{
		if (s[i] != 'A')
		{
			return false;
		}
	}
	if (p == string::npos)
	{
		return false;
	}
	size_t k = s.length() - p;
	if (k >= 3 && s.substr(p, 3) == "PAT")
	{
		p += 3;
		for (size_t i = p; i < s.length(); ++i)
		{
			if (s[i] != 'A')
			{
				return false;
			}
		}
		return true;
	}
	if (k >= 4 && s.substr(p, 4) == "PAAT")
	{
		p += 4;
		for (size_t i = p; i < s.length(); ++i)
		{
			if (s[i] != 'A')
			{
				return false;
			}
		}
		return true;
	}
	return false;
}

void B1003(void)
{
	vector<string> v = {
		"PAT",
		"PAAT",
		"AAPATAA",
		"AAPAATAAAA",
		"xPATx",
		"PT",
		"Whatever",
		"APAAATAA",
	};

	for (auto& i : v)
	{
		auto b = IsPass(i);
		if (b)
		{
			cout << "Yes";
		}
		else
		{
			cout << "No";
		}
		cout << endl;
	}
}