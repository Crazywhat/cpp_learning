 ///
 /// @file    queue.h
 /// @date    2018-08-03 23:04:18
 ///
 
#include <iostream>
#include <deque>
using std::cout;
using std::endl;
using std::deque;

template <typename Type,size_t Capacity=10>
class Queue
{
public:
	Queue();
	Queue(size_t);
	const Type& front() const;
	const Type& back() const;
	void push(Type);
	void pop();
	bool empty() const;
	bool full() const;
private:
	size_t _size;
	deque<Type> _data;
};

template <typename Type, size_t Capacity>
Queue<Type,Capacity>::Queue()
	:_data()
{
	_size=Capacity;
}

template <typename Type, size_t Capacity>
Queue<Type,Capacity>::Queue(size_t size)
	:_data()
{
	_size=size;
}

template <typename Type,size_t Capacity>
const Type& Queue<Type,Capacity>::front() const
{
	return _data.at(0);
}

template <typename Type, size_t Capacity>
const Type& Queue<Type,Capacity>::back() const
{
	return _data.back();
}

template <typename Type,size_t Capacity>
void Queue<Type,Capacity>::push(Type t)
{
	if(!full()){
		_data.push_back(t);
	}else
	{
		cout << "Sorry, the queue is fulled." << endl;
	}
}
template <typename Type,size_t Capacity>	
void Queue<Type,Capacity>::pop()
{
	if(!empty())
	{
		_data.pop_front();
	}else
	{
		cout << "The queue is empty." << endl;
	}
}
template <typename Type,size_t Capacity>
bool Queue<Type,Capacity>::empty() const
{
	return _data.empty();
}
template <typename Type,size_t Capacity>
bool Queue<Type,Capacity>::full() const
{
	return _data.size()==_size;
}
