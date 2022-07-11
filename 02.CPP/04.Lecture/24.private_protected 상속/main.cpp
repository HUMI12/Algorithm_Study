#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//상속을 받았다는 의미는 부모의 변수를 자식도 갖고 있다는 의미
//비록 부모의 변수가 private 여서 접근은 안되지만 갖고는 있다.
//class Queue : private vector<int>
//{
//public:
//	void push(int value)
//	{
//		push_back(value);
//	}
//
//	void pop()
//	{
//		pop_back();
//	}
//
//	int top()
//	{
//		return back();
//	}
//};

//위 class 와 동일한 의미를 갖게 하는 방법 -> private 상속을 쓰지 않고
//왠만하면 private 상속을 쓰지 않는 게 좋다.
//private 상속을 사용하는 경우 : 부모 class 의 protected 멤버 함수를 사용하고 싶을 때 -> 아래와 같은 방법을 사용하면 vector<int> v 의 protected 멤버 함수로 접근할 수 없음.
/*
class Queue : private vector<int>
{
private:
	vector<int> v;
public:
	void push(int value)
	{
		v.push_back(value);
	}

	void pop()
	{
		v.pop_back();
	}

	int top()
	{
		return v.back();
	}
};
*/

class Queue : protected vector<int>
{
public:
	virtual void push(int value)
	{
		push_back(value);
	}

	virtual void pop()
	{
		pop_back();
	}

	virtual int top()
	{
		return back();
	}

	virtual ~Queue()
	{

	}
};

class PriorityQueue : public Queue
{
public:
	virtual void push(int value)
	{
		Queue::push(value);
		push_heap(begin(), end());
	}

	virtual void pop()
	{
		pop_heap(begin(), end());
		Queue::pop();
	}

	virtual int top()
	{
		return front();
	}
};

int main()
{
	//객체 사이의 관계 : is-a 관계 / has-a 관계
	//is-a 관계 : 도형과 사각형이 있을 때 "사각형은 도형이다." 와 같은 관계가 성립하면 is-a 관계라고 한다.
	//has-a 관계 : "사각형은 선분을 갖고 있다." 에서 사각형과 선분은 has-a 관계라고 한다.
	//is-a 관계는 public 상속으로 나타낸다. Shape 를 상속한 Rectangle 은 is-a 관계를 갖는다.
	//Rectangle 내부의 widht 와 height 사이의 관계는 has-a 관계라고 볼 수 있다.
	//has-a 관계는 private 상속일 때 쓴다.
	/*Queue queue;
	queue.push(10);
	cout << queue.top() << endl;

	queue.push(20);
	cout << queue.top() << endl;

	queue.pop();
	cout << queue.top() << endl;*/

	//queue.push_back(1);
	//private 으로 상속 받으면 queue.at(0); queue.back(); 와 같이 부모 class 의 멤버 함수를 바로 사용할 수 없다.

	PriorityQueue pq;
	pq.push(10);
	pq.push(100);
	pq.push(0);

	cout << pq.top() << endl;
	pq.pop();

	cout << pq.top() << endl;
	pq.pop();

	cout << pq.top() << endl;
	pq.pop();
}