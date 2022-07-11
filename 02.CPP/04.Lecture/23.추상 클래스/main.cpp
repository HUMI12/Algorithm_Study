#include <iostream>

using namespace std;

class Shape
{
public:
	//넓이를 구하는 기능은 Shape 를 상속한 원, 다각형이 수행하는 일
	//순수 가상 함수 : 앞에는 virtual 뒤에는 = 0
	//추상 클래스여서 인스턴스화 할 수 없음. Shape s; 라고 선언할 수 없음
	//순수 가상 함수만으로 이루어진 추상 class 를 interface 라고도 한다.
	virtual double getArea() const = 0;
	//소멸자를 반드시 virtual 로 선언해 줘야 메모리 누수가 일어나지 않음
	virtual ~Shape() {}
};

//함수는 굳이 가상함수를 만들고 싶지 않은데 해당 class 를 instance 화 하기 싫다면? (추상 class 로 만들고 싶다면?)
/*
class Shape
{
public:
	double getArea() const;
	virtual ~Shape() = 0;
	//소멸자에 = 0 을 붙이면 된다.
};

//그리고 외부에서 소멸자를 정의할 수 있다.
Shape::~Shape()
{

}
*/


class Circle : public Shape
{
	// getArea() 라는 순수 추상 함수를 overriding 해야 Circle 에서 getArea() 를 사용할 수 있다.
private:
	double _radius;

public:
	Circle(double radius)
		: _radius(radius)
	{

	}

	virtual double getArea() const override
	{
		return _radius * _radius * 3.14;
	}
};

class Rectangle : public Shape
{
private:
	double _width;
	double _height;

public:
	Rectangle(double width, double height)
		:_width(width), _height(height)
	{

	}

	virtual double getArea() const override
	{
		return _width * _height;
	}
};

class AreaAverage
{
private:
	double _total = 0;
	int _size = 0;

public:
	double operator()(Shape & shape)
	{
		// 추상 class 를 parameter 로 받아서 넘겨주면 다양한 class 에 대해서 getArea() 함수를 동일하게 사용할 수 있다.
		_size += 1;
		_total += shape.getArea();
		return _total / _size;
	}
};

int main()
{
	Circle c(10);
	cout << c.getArea() << endl;

	Rectangle r(10, 20);
	cout << r.getArea() << endl;

	Shape* s0 = &c;
	Shape& s1 = r;

	cout << s0->getArea() << endl;
	cout << s1.getArea() << endl;

	AreaAverage aavg;
	cout << aavg(c) << endl;
	cout << aavg(r) << endl;

}