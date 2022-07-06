/*
�Ҽ��� ���� 

Q. �ڿ��� N�� �ԷµǸ� 1���� N������ �Ҽ��� ������ ����ϴ� ���α׷��� �ۼ��ϼ���. 
���� 20�� �ԷµǸ� 1���� 20������ �Ҽ��� 2, 3, 5, 7, 11, 13, 17, 19�� �� 8���Դϴ�.
���ѽð��� 1���Դϴ�.

Input
ù �ٿ� �ڿ����� ���� N(2<=N<=200,000)�� �־����ϴ�.

Output
ù �ٿ� �Ҽ��� ������ ����մϴ�.

Ex
In : 20
Out : 8
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int n;
	vector<int> primes;
	cin >> n;

	int cnt = 0;
	bool flag = false;

	for (int i = 2; i <= n; i++)
	{
		flag = false;
		for (auto prime : primes)
		{
			if (i % prime == 0)
			{
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			primes.push_back(i);
			cnt++;
		}
	}

	cout << cnt << endl;

	return 0;
}
