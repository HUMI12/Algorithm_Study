/*
소수의 개수 

Q. 자연수 N이 입력되면 1부터 N까지의 소수의 개수를 출력하는 프로그램을 작성하세요. 
만약 20이 입력되면 1부터 20까지의 소수는 2, 3, 5, 7, 11, 13, 17, 19로 총 8개입니다.
제한시간은 1초입니다.

Input
첫 줄에 자연수의 개수 N(2<=N<=200,000)이 주어집니다.

Output
첫 줄에 소수의 개수를 출력합니다.

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
