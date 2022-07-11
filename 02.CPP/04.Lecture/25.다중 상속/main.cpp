#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class BaseA
{
public:
	int m;
	void foo()
	{
		cout << "BaseA" << endl;
	}
};

class BaseB
{
	// 두 개의 부모가 같은 이름의 변수 또는 함수를 갖고 있을 경우
	// 자식이 부모의 변수 또는 함수를 가리고 있으면 괜찮
public:
	int m;
	void foo()
	{
		cout << "BaseB" << endl;
	}
};

class Derived : public BaseA, public BaseB
{
public:
	// 설계 문제가 있지 않나 -> 어떤 건 A 부모, 어떤 건 B 부모를 가져다 쓴다??
	using BaseB::m;
	using BaseA::foo;
};

// 다이아몬드 상속
//     A
// B0     B1
//     C
// C 는 B0, B1 을 갖고 있음 -> B0, B1 은 각각 A 를 갖고 있음 -> C 가 A 를 두 개 가짐

class Base
{
public:
	int m;
	Base(int m)
		: m(m)
	{
		cout << "Base(" << m << ")" << endl;
	}
};

class BaseC : virtual public Base
{
public:
	BaseC() : Base(10)
	{
		cout << "BaseC" << endl;
	}
};

class BaseD : virtual public Base
{
public:
	BaseD() : Base(20)
	{
		cout << "BaseD" << endl;
	}
};

class DerivedB : public BaseC, public BaseD
{
public:
	DerivedB()
		: Base(30)
	{
		cout << "DerivedB" << endl;
	}
};

int main(void)
{
	cout << "다중 상속 기본 형태" << endl;
	Derived d;
	d.foo();
	d.m = 10;
	cout << d.m << endl;

	BaseA& ba = d;
	ba.foo();

	BaseB* bb = &d;
	bb->foo();

	cout << "다이아몬드 형태의 다중 상속을 사용할 경우" << endl;
	DerivedB db;

	cout << db.BaseC::m << endl;
	cout << db.BaseD::m << endl;
}