/*
�Ƴ��׷�(����)

Q. Anagram�̶� �� ���ڿ��� ���ĺ��� ���� ������ �ٸ����� �� ������ ��ġ�ϸ� �� �ܾ�� ��
���׷��̶�� �մϴ�. 
���� ��� AbaAeCe �� baeeACA �� ���ĺ��� ���� ������ �ٸ����� �� ������ ���캸�� 
A(2), a(1), b(1), C(1), e(2)�� ���ĺ��� �� ������ ��� ��ġ�մϴ�. �� ��� �� �ܾ �� 
�迭�ϸ� ����� �ܾ �� �� �ִ� ���� �Ƴ��׷��̶� �մϴ�.
���̰� ���� �� ���� �ܾ �־����� �� �ܾ �Ƴ��׷����� �Ǻ��ϴ� ���α׷��� �ۼ��ϼ�
��. �Ƴ��׷� �Ǻ��� ��ҹ��ڰ� ���е˴ϴ�.

Input
ù �ٿ� ù ��° �ܾ �Էµǰ�, �� ��° �ٿ� �� ��° �ܾ �Էµ˴ϴ�.
�ܾ��� ���̴� 100�� ���� �ʽ��ϴ�.

Output
�� �ܾ �Ƴ��׷��̸� ��YES"�� ����ϰ�, �ƴϸ� ��NO"�� ����մϴ�.

Ex
In :
AbaAeCe
baeeACA
Out : YES
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void main()
{
	string s1, s2;
	vector<int> v(46);
	cin >> s1 >> s2;

	for (int i = 0; i < s1.size(); i++)
	{
		auto x = s1[i] - 'A';
		v[x]++;
		x = s2[i] - 'A';
		v[x]--;
	}
	
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] != 0)
		{
			cout << "NO" << endl;
			return;
		}
	}

	cout << "YES" << endl;

	return;
}