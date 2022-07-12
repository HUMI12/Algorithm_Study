/*
���� ���� ��

Q. A, B �� ����� ���������� ������ �մϴ�. �� N���� ������ �Ͽ� A�� �̱�� A�� ����ϰ�, 
B�� �̱�� B�� ����մϴ�. ��� ��쿡�� D�� ����մϴ�. 
����, ����, ���� ������ 1:����, 2:����, 3:���� ���ϰڽ��ϴ�.
���� ��� N=5�̸�

ȸ�� 1 2 3 4 5
A�� ���� 2 3 3 1 3
B�� ���� 1 1 2 2 3
���� A B A B D
�� ����� �� ȸ�� ����, ����, �� ������ �־����� �� ȸ�� ���� �̰���� ����ϴ� ���α׷�
�� �ۼ��ϼ���.

Input
ù ��° �ٿ� ���� Ƚ���� �ڿ��� N(1<=N<=100)�� �־����ϴ�.
�� ��° �ٿ��� A�� �� ����, ����, �� ������ N�� �־����ϴ�.
�� ��° �ٿ��� B�� �� ����, ����, �� ������ N�� �־����ϴ�.

Output
�� �ٿ� �� ȸ�� ���ڸ� ����մϴ�. ����� ���� D�� ����մϴ�.

Ex
In :
5
2 3 3 1 3
1 1 2 2 3

Out :
A
B
A
B
D

*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int shobu(int a, int b)
{
	if (a == b) return 0;
	else if (a < b)
	{
		if (b - a == 2)
		{
			return 1;
		}
		return -1;
	}
	else if (a > b)
	{
		if (a - b == 2)
		{
			return -1;
		}
		return 1;
	}
}

void main()
{
	int n;
	cin >> n;

	vector<int> v1, v2;
	int x = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> x;
		v1.push_back(x);
	}

	for (int i = 0; i < n; i++)
	{
		cin >> x;
		v2.push_back(x);
	}

	for (int i = 0; i < n; i++)
	{
		if (shobu(v1[i], v2[i]) == 1) cout << "A" << endl;
		else if (shobu(v1[i], v2[i]) == 0) cout << "D" << endl;
		else cout << "B" << endl;
	}

	return;
}