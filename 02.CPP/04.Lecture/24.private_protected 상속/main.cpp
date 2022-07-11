#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//����� �޾Ҵٴ� �ǹ̴� �θ��� ������ �ڽĵ� ���� �ִٴ� �ǹ�
//��� �θ��� ������ private ���� ������ �ȵ����� ����� �ִ�.
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

//�� class �� ������ �ǹ̸� ���� �ϴ� ��� -> private ����� ���� �ʰ�
//�ظ��ϸ� private ����� ���� �ʴ� �� ����.
//private ����� ����ϴ� ��� : �θ� class �� protected ��� �Լ��� ����ϰ� ���� �� -> �Ʒ��� ���� ����� ����ϸ� vector<int> v �� protected ��� �Լ��� ������ �� ����.
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
	//��ü ������ ���� : is-a ���� / has-a ����
	//is-a ���� : ������ �簢���� ���� �� "�簢���� �����̴�." �� ���� ���谡 �����ϸ� is-a ������ �Ѵ�.
	//has-a ���� : "�簢���� ������ ���� �ִ�." ���� �簢���� ������ has-a ������ �Ѵ�.
	//is-a ����� public ������� ��Ÿ����. Shape �� ����� Rectangle �� is-a ���踦 ���´�.
	//Rectangle ������ widht �� height ������ ����� has-a ������ �� �� �ִ�.
	//has-a ����� private ����� �� ����.
	/*Queue queue;
	queue.push(10);
	cout << queue.top() << endl;

	queue.push(20);
	cout << queue.top() << endl;

	queue.pop();
	cout << queue.top() << endl;*/

	//queue.push_back(1);
	//private ���� ��� ������ queue.at(0); queue.back(); �� ���� �θ� class �� ��� �Լ��� �ٷ� ����� �� ����.

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