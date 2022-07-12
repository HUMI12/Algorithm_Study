#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 명시적인 형 변환은 위험하다!! (C++ 창시자의 생각)
// C 의 형변환은 위험하기 때문에 casting 하는 방법을 다양하게 나눠 놓았다

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
	//ClassB* b = static_cast<ClassB*>(&a);	// 컴파일 단계에서 형변환에 문제가 있다는 것을 알 수 있음
	ClassB* b0 = (ClassB*)&a;				// 컴파일 단계에서 형변환에 문제가 있는지 알 수 없음

	float f = 1.1f;
	int i = static_cast<int>(f);
	//int* i0 = static_cast<int*>(&f);	// i 에 f 의 주소값을 넣는다 -> 해당 주소에 있는 값을 int 형태로 해석 하겠다 는 의미
	int* i1 = (int*)(&f);

	TypeA typea = static_cast<TypeA>(0);	// 정수 값을 enum 으로 변경하고 싶을 때
	TypeB typeb = static_cast<TypeB>(typea);

	cout << static_cast<int>(typea) << endl;
	cout << static_cast<int>(typeb) << endl;	// enum 을 정수로 출력하고 싶을 때

	Test t1 = static_cast<Test>(1);	// 이렇게 하면 생성자 호출함
	Test t2(10);
	bool b = static_cast<bool>(t1);
	cout << b << endl;

	// 부모 자식 관계의 static_cast
	Child c;
	Parent& p1 = static_cast<Parent&>(c);
	Parent& p2 = (Parent&)c;

	Child& c0 = static_cast<Child&>(p1);

	cout << c0.num << endl;

	// p3 를 c1 으로 static_cast 하면 컴파일 타임에서는 오류가 있는지 알 수 없다.
	// 하지만 런타임에서 오류 발생 -> p3 에는 num 이 없기 때문에 c1 은 p3 를 가져온 것이기 때문에
	Parent p3;
	Child& c1 = static_cast<Child&>(p3);

	cout << c1.num << endl;
}