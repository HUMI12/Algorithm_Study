/*
가장 많이 사용된 자릿수

Q. N자리의 자연수가 입력되면 입력된 자연수의 자릿수 중 가장 많이 사용된 숫자를 출력하는 프
로그램을 작성하세요.
예를 들어 1230565625라는 자연수가 입력되면 5가 3번 상용되어 가장 많이 사용된 숫자입니
다. 답이 여러 개일 경우 그 중 가장 큰 수를 출력하세요.

Input
첫 줄에 자연수가 입력됩니다. 자연수의 길이는 100을 넘지 않습니다.

Output
자릿수의 곱을 출력합니다.
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