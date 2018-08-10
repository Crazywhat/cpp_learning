///
/// @file    vector.h
/// @date    2018-08-07 19:03:43
///
#ifndef __MY_VECTOR_H__
#define __MY_VECTOR_H__
#include <memory>
#include <algorithm>
#include <iostream>
using std::cout;
using std::endl;
using std::allocator;

template<typename T>
class Vector
{	
	typedef T* iterator;
	public:
		Vector();
		~Vector();

		void push_back(const T &); 
		void pop_back();    

		int size() const;
		int capacity() const;
		T& operator [](size_t);
		iterator begin(){ return _start;}
		iterator end(){ return _finish;}
		const iterator cbegin(){ return _start;}
		const iterator cend(){ return _finish;}
	private:
		void reallocate();//重新分配内存,动态扩容要用的
		void deallocate_old_mem();
	private:    
		static std::allocator<T> _alloc;

		T * _start;      //指向数组中的第一个元素
		T * _finish; //指向最后一个实际元素之后的那个元素
		T * _end_of_storage;        //指向数组本身之后的位置
};

template <typename T>
Vector<T>::Vector()
{
	_alloc;//
	_start=_finish=_end_of_storage=NULL;
}

template <typename T>
int Vector<T>::size() const
{
	return _finish-_start;	
}
template <typename T>
int Vector<T>::capacity() const
{
	return _end_of_storage-_start;	
}

template <typename T >
void Vector<T>::deallocate_old_mem()
{
	while(_finish!=_start)
	{
		_alloc.destroy(--_finish);
	}
	_alloc.deallocate(_start,capacity());
	_start=_finish=NULL;
}

template <typename T>
Vector<T>::~Vector(){
	if(_start)
	{
		deallocate_old_mem();
		_end_of_storage=NULL;
	}
}

template <typename T>
void Vector< T >::reallocate()
{
	T *new_mem;
	int old_capacity = capacity();
	new_mem = _alloc.allocate(2*old_capacity);

	//将对象拷贝到未构建对象的内存区域
	std::uninitialized_copy(_start,_finish,new_mem);

	deallocate_old_mem();
	_end_of_storage=new_mem+2*old_capacity;
	_start=new_mem;
	_finish=_start+old_capacity;
}

template <typename T >
void Vector<T>::pop_back()
{
	if(_finish>_start)
		_alloc.destroy(--_finish);
}

template <typename T>
void Vector<T>::push_back(const T &data)
{
	if(!_start)
	{
		_start = _alloc.allocate(1);
		_finish=_end_of_storage=_start+1;
		_alloc.construct(_start,data);
	}else
	{
		if(_finish==_end_of_storage)
		{
			reallocate();
		}
		_alloc.construct(_finish++,data);
	}
}

template <typename T>
T& Vector<T>::operator [](size_t idex)
{
	if(idex < _finish - _start){
		return *(_start+idex);
	}else
	{
		cout << "invail idex ." << endl;
		static T null_value;
		return null_value;
	}
}

#endif
