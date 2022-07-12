#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ������� �� ��ȯ�� �����ϴ�!! (C++ â������ ����)
// C �� ����ȯ�� �����ϱ� ������ casting �ϴ� ����� �پ��ϰ� ���� ���Ҵ�

class ClassA
{

};

class ClassB
{

};

enum class TypeA
{
	A, B, C
};

enum class TypeB
{
	A, B, C
};

class Test
{
public:
	explicit Test(int num)
	{
		cout << num << endl;
	}

	explicit operator bool() const
	{
		return true;
	}
};

class Parent
{

};

class Child : public Parent
{
public:
	int num = 10;
};

int main(void)
{
	ClassA a;
	//ClassB* b = static_cast<ClassB*>(&a);	// ������ �ܰ迡�� ����ȯ�� ������ �ִٴ� ���� �� �� ����
	ClassB* b0 = (ClassB*)&a;				// ������ �ܰ迡�� ����ȯ�� ������ �ִ��� �� �� ����

	float f = 1.1f;
	int i = static_cast<int>(f);
	//int* i0 = static_cast<int*>(&f);	// i �� f �� �ּҰ��� �ִ´� -> �ش� �ּҿ� �ִ� ���� int ���·� �ؼ� �ϰڴ� �� �ǹ�
	int* i1 = (int*)(&f);

	TypeA typea = static_cast<TypeA>(0);	// ���� ���� enum ���� �����ϰ� ���� ��
	TypeB typeb = static_cast<TypeB>(typea);

	cout << static_cast<int>(typea) << endl;
	cout << static_cast<int>(typeb) << endl;	// enum �� ������ ����ϰ� ���� ��

	Test t1 = static_cast<Test>(1);	// �̷��� �ϸ� ������ ȣ����
	Test t2(10);
	bool b = static_cast<bool>(t1);
	cout << b << endl;

	// �θ� �ڽ� ������ static_cast
	Child c;
	Parent& p1 = static_cast<Parent&>(c);
	Parent& p2 = (Parent&)c;

	Child& c0 = static_cast<Child&>(p1);

	cout << c0.num << endl;

	// p3 �� c1 ���� static_cast �ϸ� ������ Ÿ�ӿ����� ������ �ִ��� �� �� ����.
	// ������ ��Ÿ�ӿ��� ���� �߻� -> p3 ���� num �� ���� ������ c1 �� p3 �� ������ ���̱� ������
	Parent p3;
	Child& c1 = static_cast<Child&>(p3);

	cout << c1.num << endl;
}