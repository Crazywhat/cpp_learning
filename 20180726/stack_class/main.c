///
/// @file    main.c

#include <stdio.h>
#include <stdlib.h>

#include <iostream>

using std::cout;
using std::endl;


class stack
{
	private:
		int _data[10];
		int _top;
		int _empty;
	public:
		stack();
		void push(int);
		void pop();
		int top() const;
		bool emty() const;
		bool full() const;
};

stack::stack()
	:_top(0)
	 ,_empty(10)
{

}

void stack::push(int num)
{
	//栈溢出，结束程序
	if(0==_empty)
	{
		cout << "push: The stack is full." << endl;
		exit(0);
	}
	--_empty;
	_data[_top++]=num;
	cout << num << " into stack " << endl;
}
void stack::pop()
{
	//数组为空，直接返回
	if(10==_empty)
	{
		cout << "pop: The stack is empty" << endl;
		return;
	}
	++_empty;
	--_top;
	cout << _data[_top] << " leave  stack" << endl;
}

int stack::top() const
{
	  if(10==_empty)
	  {
		cout << "top :The stack is empty" << endl;
		return -1;
	  }
	return _data[_top-1];
}

bool stack::emty() const
{
	return 10==_empty?true:false;
}

bool stack::full() const
{
	return 0==_empty?true:false;
}

int  main()
{
	stack s;
	
	s.push(10);
	s.push(12);
	s.push(14);
	
	cout << " top : " << s.top() << endl;


	s.pop();
	
	cout << "top : " << s.top() << endl;



	return 0;
}
