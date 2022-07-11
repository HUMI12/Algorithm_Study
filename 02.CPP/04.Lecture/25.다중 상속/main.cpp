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
	// �� ���� �θ� ���� �̸��� ���� �Ǵ� �Լ��� ���� ���� ���
	// �ڽ��� �θ��� ���� �Ǵ� �Լ��� ������ ������ ����
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
	// ���� ������ ���� �ʳ� -> � �� A �θ�, � �� B �θ� ������ ����??
	using BaseB::m;
	using BaseA::foo;
};

// ���̾Ƹ�� ���
//     A
// B0     B1
//     C
// C �� B0, B1 �� ���� ���� -> B0, B1 �� ���� A �� ���� ���� -> C �� A �� �� �� ����

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
	cout << "���� ��� �⺻ ����" << endl;
	Derived d;
	d.foo();
	d.m = 10;
	cout << d.m << endl;

	BaseA& ba = d;
	ba.foo();

	BaseB* bb = &d;
	bb->foo();

	cout << "���̾Ƹ�� ������ ���� ����� ����� ���" << endl;
	DerivedB db;

	cout << db.BaseC::m << endl;
	cout << db.BaseD::m << endl;
}