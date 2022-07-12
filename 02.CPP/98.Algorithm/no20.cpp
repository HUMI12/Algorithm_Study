/*
가위 바위 보

Q. A, B 두 사람이 가위바위보 게임을 합니다. 총 N번의 게임을 하여 A가 이기면 A를 출력하고, 
B가 이기면 B를 출력합니다. 비길 경우에는 D를 출력합니다. 
가위, 바위, 보의 정보는 1:가위, 2:바위, 3:보로 정하겠습니다.
예를 들어 N=5이면

회수 1 2 3 4 5
A의 정보 2 3 3 1 3
B의 정보 1 1 2 2 3
승자 A B A B D
두 사람의 각 회의 가위, 바위, 보 정보가 주어지면 각 회를 누가 이겼는지 출력하는 프로그램
을 작성하세요.

Input
첫 번째 줄에 게임 횟수인 자연수 N(1<=N<=100)이 주어집니다.
두 번째 줄에는 A가 낸 가위, 바위, 보 정보가 N개 주어집니다.
세 번째 줄에는 B가 낸 가위, 바위, 보 정보가 N개 주어집니다.

Output
각 줄에 각 회의 승자를 출력합니다. 비겼을 경우는 D를 출력합니다.

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