/*
가장 많이 사용된 자릿수

Q. N개의 자연수가 입력되면 각 자연수를 뒤집은 후 그 뒤집은 수가 소수이면 그 수를 출력하는 
프로그램을 작성하세요. 예를 들어 32를 뒤집으면 23이고, 23은 소수이다. 그러면 23을 출력
한다. 단 910를 뒤집으면 19로 숫자화 해야 한다. 첫 자리부터의 연속된 0은 무시한다.
뒤집는 함수인 int reverse(int x) 와 소수인지를 확인하는 함수 bool isPrime(int x)를 반드시 
작성하여 프로그래밍 한다.

Input
첫 줄에 자연수의 개수 N(3<=N<=100)이 주어지고, 그 다음 줄에 N개의 자연수가 주어진다.
각 자연수의 크기는 100,000를 넘지 않는다.

Output
첫 줄에 뒤집은 소수를 출력합니다. 출력순서는 입력된 순서대로 출력합니다.

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