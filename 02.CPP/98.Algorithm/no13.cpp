/*
���� ���� ���� �ڸ���

Q. N�ڸ��� �ڿ����� �ԷµǸ� �Էµ� �ڿ����� �ڸ��� �� ���� ���� ���� ���ڸ� ����ϴ� ��
�α׷��� �ۼ��ϼ���.
���� ��� 1230565625��� �ڿ����� �ԷµǸ� 5�� 3�� ���Ǿ� ���� ���� ���� �����Դ�
��. ���� ���� ���� ��� �� �� ���� ū ���� ����ϼ���.

Input
ù �ٿ� �ڿ����� �Էµ˴ϴ�. �ڿ����� ���̴� 100�� ���� �ʽ��ϴ�.

Output
�ڸ����� ���� ����մϴ�.
Ex
In : 1230565625Out : 5
*/
#include <iostream>
#include <string>

using namespace std;

void main()
{
	int max_cnt = -1, max_no = -1;
	string str;
	cin >> str;

	int mat[10] = { 0, };

	for (int i = 0; i < str.size(); i++)
	{
		int x = str[i] - '0';
		mat[x]++;
	}

	for (int i = 0; i < 10; i++)
	{
		if (max_cnt <= mat[i])
		{
			max_cnt = mat[i];
			max_no = i;
		}
	}

	cout << max_no << endl;

	return;
}