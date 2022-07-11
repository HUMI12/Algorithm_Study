#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 변환 규칙

class Test
{
public:
	explicit operator bool() const // operator bool() -> bool 을 사용해야할 경우 자동으로 해당 함수 호출 ex) Test t; if(t)
	{
		return true;
	}
};

int main(void)
{
	// cout << typeid(1.3f + 1).name() << endl;
	// 1 (int) -> float
	
	// 작은 형에서 큰 형으로 변환할 때
	// promotion = 승급 = 확장 변환 = widening
	// 데이터 손실이 없기 때문에 문제가 발생하지 않음
	char ch = 'a';
	int num = ch;

	// ch 는 1B -> 1544 를 다 표현할 수 없음
	// int 는 소수점을 표현할 수 없음
	// demotion = 강등 = narrowing = 축소 변환
	// 형 변환 주의 필요
	char ch2 = 1544;
	int i = 1.1;

	// 축소 변환이 발생하는지 확인 방법 -> 중괄호 사용 = uniform initialization
	/*
	int j = { 1.1f };
	*/
	// 변수가 중괄호에 들어갈 경우 컴파일 되지 않음
	/*
	int num2 = 1;
	char ch3{ num2 };
	*/
	// 하지만 컴파일 타임에 변수의 타입을 알 수 있으면 컴파일 가능
	const int num2 = 10;
	char ch3{ num2 };
	
	// 산술 변환
	// + - * /
	// 피연산자 타임에 따라 return 값이 달라짐
	unsigned short s0 = 40000; // maximum = 65535
	cout << typeid(s0 + s0).name() << endl; // overflow 가 발생하지 않음
	// int 보다 아래 있는 형은 산술 연산을 할 경우 각각이 int 로 promotion 됨
	// int 가 빠르고 기본적인 연산이기 때문에 int 로 promotiom 됨

	unsigned int i0 = 4100000000; // maximum 약 4100000000
	cout << typeid(i0 + i0).name() << endl; // overflow 발생
	// int 는 명시적이지 않을 경우 int 로 그냥 사용됨 -> promotion 발생하지 않음
	
	// 다른 타입일 경우 : int 보다 아래 형은 int 로 바뀜, int 보다 큰 형은 기본적으로 더 높은 사이즈를 가진 형으로 변환
	long long ll0 = 4100000000;
	cout << typeid(i0 + ll0).name() << endl; // overflow 발생하지 않음
	cout << i0 + ll0 << endl;

	// signed 와 unsigned 가 섞여 있을 경우 signed 가 unsigned 로 바뀜
	unsigned int i1 = 10;
	int i2 = -110;
	cout << typeid(i1 + i2).name() << endl;
	cout << i1 + i2 << endl; // underflow 발생

	// 부동 소수점 끼리 연산 : 그냥 큰 거
	// long double, double, float

	// 부동 소수점과 정수의 연산 : 부도 소수점으로 변환
	float f0 = 1.f;
	unsigned long long ull0 = 10;
	cout << typeid(f0 + ull0).name() << endl;

	// boolean 으로 변환 : boolean 이 들어갈 자리에는 boolean 으로 변환
	// if, while, for 등등
	// !, &&, || 등등
	// 삼항 연산자

	Test t;
	// bool b = t; // 불가능
	if (t) // 가능
	{

	}

	int a = 1;
	const int& b = a;
	const int* c = &a;

	// 부모 자식 관계 : 자식이 부모의 변수, 함수를 가져올 수 있음 = 부모에 자식을 담을 수 있다
	/*
	Child c;
	Parent* p0 = &c;
	Parent& p1 = c;
	
	하지만 Child 가 private 으로 Parent 를 상속받을 경우 형변환 불가능 is-a 관계가 아니기 때문에?
	*/
}