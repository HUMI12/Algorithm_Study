/*
분노 유발자

Q. 오늘은 수능이 끝난 다음날로 교장선생님은 1, 2학년 재학생들에게 강당에 모여 어벤져스 영
화를 보여준다고 하여 학생들이 강당에 모였습니다.
강당의 좌석은 영화관처럼 계단형이 아니라 평평한 바닥에 의자만 배치하고 학생들이 앉습니
다. 그런데 만약 앞자리에 앉은 키가 큰 학생이 앉으면 그 학생보다 앉은키가 작은 뒷자리 학
생은 스크린이 보이지 않습니다. 한 줄에 앉은키 정보가 주어지면 뒷사람 모두의 시야를 가려 
영화 시청이 불가능하게 하는 분노유발자가 그 줄에 몇 명이 있는지 구하는 프로그램을 작성
하세요.

Input
첫 줄에 한 줄에 앉은 학생수 N(3<=N<=100)이 주어집니다.
두 번째 줄에 N명의 앉은 키 정보(45이상 100이하)가 앞 자리 학생부터 차례대로 주어집니다.

Output
자신의 뒷 사람 모두를 시청방해하는 학생수를 출력합니다.

Ex
In :
10
56 46 55 76 65 53 52 53 55 50

Out :
3

*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void main()
{
	int n;
	cin >> n;

	if (n == 1)
	{
		cout << 1 << endl;
		return;
	}

	vector<int> v;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}

	reverse(v.begin(), v.end());
	int max = 0;
	int cnt = 0;

	for (int i = 0; i < n; i++)
	{
		if (v[i] > max)
		{
			max = v[i];
			cnt++;
		}
	}

	cout << cnt - 1 << endl;

	return;
}