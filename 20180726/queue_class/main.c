///
/// @file    main.c

#include <stdio.h>
#include <stdlib.h>

#include <iostream>

using std::cout;
using std::endl;


class queue
{
	private:
		int _data[10];
		int _front;
		int _back;
		int _empty;
	public:
		queue();
		void push(int);
		void pop();
		int front() const;
		int back() const;
		bool emty() const;
		bool full() const;
};

queue::queue()
	:_front(0)
	 ,_back(0)
	 ,_empty(10)
{

}

void queue::push(int num)
{
	//队列溢出，结束程序
	if(0==_empty)
	{
		cout << "push: The queue is full." << endl;
		exit(0);
	}
	--_empty;
	_data[_back]=num;
	_back=(_back+1)%10;
	cout << num << " into queue " << endl;
}
void queue::pop()
{
	//队列为空，直接返回
	if(10==_empty)
	{
		cout << "pop: The queue is empty" << endl;
		return;
	}
	++_empty;
	cout << _data[_front] << " leave  queue" << endl;
	_front=(_front+1)%10;
}

int queue::front() const
{
	  if(10==_empty)
	  {
		cout << "front :The queue is empty" << endl;
		return -1;
	  }
	return _data[_front];
}

int queue::back() const
{
	  if(10==_empty)
	  {
		cout << "back :The queue is empty" << endl;
		return -1;
	  }
	return _data[0==_back?9:_back-1];
}
bool queue::emty() const
{
	return 10==_empty?true:false;
}

bool queue::full() const
{
	return 0==_empty?true:false;
}

int  main()
{
	queue q;
	
	q.push(10);
	q.push(14);
	q.push(12);
	q.push(14);
	q.push(10);
	q.push(10);
	q.push(12);
	q.push(14);
	q.push(12);
	q.push(14);
	
	cout << " front : " << q.back() << endl;


	q.pop();
	
	cout << "front : " << q.front() << endl;



	return 0;
}
