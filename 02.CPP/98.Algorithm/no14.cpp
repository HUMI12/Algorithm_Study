/*
���� ���� ���� �ڸ���

Q. N���� �ڿ����� �ԷµǸ� �� �ڿ����� ������ �� �� ������ ���� �Ҽ��̸� �� ���� ����ϴ� 
���α׷��� �ۼ��ϼ���. ���� ��� 32�� �������� 23�̰�, 23�� �Ҽ��̴�. �׷��� 23�� ���
�Ѵ�. �� 910�� �������� 19�� ����ȭ �ؾ� �Ѵ�. ù �ڸ������� ���ӵ� 0�� �����Ѵ�.
������ �Լ��� int reverse(int x) �� �Ҽ������� Ȯ���ϴ� �Լ� bool isPrime(int x)�� �ݵ�� 
�ۼ��Ͽ� ���α׷��� �Ѵ�.

Input
ù �ٿ� �ڿ����� ���� N(3<=N<=100)�� �־�����, �� ���� �ٿ� N���� �ڿ����� �־�����.
�� �ڿ����� ũ��� 100,000�� ���� �ʴ´�.

Output
ù �ٿ� ������ �Ҽ��� ����մϴ�. ��¼����� �Էµ� ������� ����մϴ�.

Ex
In : 5
32 55 62 3700 250
Out : 23 73
*/
#include <iostream>
#include <string>

using namespace std;

int reverse(string x)
{
	string x_reverse = "";

	for (int i = 0; i < x.size(); i++)
	{
		x_reverse = x[i] + x_reverse;
	}

	return stoi(x_reverse);
}

bool isPrime(int x)
{
	if (x <= 1) return false;

	for (int i = 2; i < x / 2; i++)
	{
		if (x % i == 0) return false;
	}

	return true;
}

void main()
{
	int n;
	string x;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> x;
		auto x_reverse = reverse(x);
		if (isPrime(x_reverse)) cout << x_reverse << " ";
	}

	return;
}