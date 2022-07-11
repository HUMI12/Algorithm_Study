#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ��ȯ ��Ģ

class Test
{
public:
	explicit operator bool() const // operator bool() -> bool �� ����ؾ��� ��� �ڵ����� �ش� �Լ� ȣ�� ex) Test t; if(t)
	{
		return true;
	}
};

int main(void)
{
	// cout << typeid(1.3f + 1).name() << endl;
	// 1 (int) -> float
	
	// ���� ������ ū ������ ��ȯ�� ��
	// promotion = �±� = Ȯ�� ��ȯ = widening
	// ������ �ս��� ���� ������ ������ �߻����� ����
	char ch = 'a';
	int num = ch;

	// ch �� 1B -> 1544 �� �� ǥ���� �� ����
	// int �� �Ҽ����� ǥ���� �� ����
	// demotion = ���� = narrowing = ��� ��ȯ
	// �� ��ȯ ���� �ʿ�
	char ch2 = 1544;
	int i = 1.1;

	// ��� ��ȯ�� �߻��ϴ��� Ȯ�� ��� -> �߰�ȣ ��� = uniform initialization
	/*
	int j = { 1.1f };
	*/
	// ������ �߰�ȣ�� �� ��� ������ ���� ����
	/*
	int num2 = 1;
	char ch3{ num2 };
	*/
	// ������ ������ Ÿ�ӿ� ������ Ÿ���� �� �� ������ ������ ����
	const int num2 = 10;
	char ch3{ num2 };
	
	// ��� ��ȯ
	// + - * /
	// �ǿ����� Ÿ�ӿ� ���� return ���� �޶���
	unsigned short s0 = 40000; // maximum = 65535
	cout << typeid(s0 + s0).name() << endl; // overflow �� �߻����� ����
	// int ���� �Ʒ� �ִ� ���� ��� ������ �� ��� ������ int �� promotion ��
	// int �� ������ �⺻���� �����̱� ������ int �� promotiom ��

	unsigned int i0 = 4100000000; // maximum �� 4100000000
	cout << typeid(i0 + i0).name() << endl; // overflow �߻�
	// int �� ��������� ���� ��� int �� �׳� ���� -> promotion �߻����� ����
	
	// �ٸ� Ÿ���� ��� : int ���� �Ʒ� ���� int �� �ٲ�, int ���� ū ���� �⺻������ �� ���� ����� ���� ������ ��ȯ
	long long ll0 = 4100000000;
	cout << typeid(i0 + ll0).name() << endl; // overflow �߻����� ����
	cout << i0 + ll0 << endl;

	// signed �� unsigned �� ���� ���� ��� signed �� unsigned �� �ٲ�
	unsigned int i1 = 10;
	int i2 = -110;
	cout << typeid(i1 + i2).name() << endl;
	cout << i1 + i2 << endl; // underflow �߻�

	// �ε� �Ҽ��� ���� ���� : �׳� ū ��
	// long double, double, float

	// �ε� �Ҽ����� ������ ���� : �ε� �Ҽ������� ��ȯ
	float f0 = 1.f;
	unsigned long long ull0 = 10;
	cout << typeid(f0 + ull0).name() << endl;

	// boolean ���� ��ȯ : boolean �� �� �ڸ����� boolean ���� ��ȯ
	// if, while, for ���
	// !, &&, || ���
	// ���� ������

	Test t;
	// bool b = t; // �Ұ���
	if (t) // ����
	{

	}

	int a = 1;
	const int& b = a;
	const int* c = &a;

	// �θ� �ڽ� ���� : �ڽ��� �θ��� ����, �Լ��� ������ �� ���� = �θ� �ڽ��� ���� �� �ִ�
	/*
	Child c;
	Parent* p0 = &c;
	Parent& p1 = c;
	
	������ Child �� private ���� Parent �� ��ӹ��� ��� ����ȯ �Ұ��� is-a ���谡 �ƴϱ� ������?
	*/
}