/*
������ ����

Q. ������ ���� �л��� N�� �ֽ��ϴ�. �������� �������� ��� �ڸ��� ����� �ϴµ� �� ���� ��
������ ����ų� ���� �ʵ��� �� �л��鿡�� ��� �½��ϴ�.
�������� �� �л��鿡�� ���ڰ� ���� ī�带 ����ϴ�. �� �л����� 1���� �ڱ� ī�忡 ���� 
���ڱ����� ���� ���ϴ� �����Դϴ�. 
�������� ���ƿͼ� �� �л����� ���� �¾Ҵ��� Ȯ���� �Ϸ��� �ϴµ� �ʹ� ���� �����п�
�� �ڵ����� ä���� �ϴ� ���α׷��� ��Ź�߽��ϴ�. �������� �������� �����ּ���.

Input
ù �ٿ� �� �л����� �ڿ��� N(1<=N<=10)�� �־����ϴ�.
�� �л����� 1���� N���� ��ȣ�� �ο��Ǿ� �ִٰ� �����մϴ�.
�� ��° �ٺ��� 1�� �л������� ī�忡 ���� ���� �л��� ���� ������ ������ ���̿� �ΰ�
�Էµȴ�. ī�忡 ���� ���� 1000�� ���� �ʴ´�.

Output
ù �ٺ��� 1�� �л��� ������ ���߸� ��YES", Ʋ���� ��NO"�� ����ϼ���.

Ex
In :
3
10 55
20 350
100 5050
Out :
YES
NO
YES
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void main()
{
	vector<int> v(1000);

	for (int i = 1; i < v.size(); i++)
	{
		v[i] = v[i - 1] + i;
	}
	
	int n;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x, answer;

		cin >> x >> answer;

		if (v[x] == answer)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}

	return;
}