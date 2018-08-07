///
/// @file    headsort.h
/// @date    2018-08-06 09:33:38
///

#include <iostream>
using std::cout;
using std::endl;


template <typename T, typename Compare = std::less<T> >
class HeapSort
{
	public:
		 HeapSort(T * arr, int size );        
		void sort();    
	private:
		//传入的函数对象，这样使用
		void heapAdjust(int pos,int len,Compare com = Compare());
	private:
		T* _arr;
		int _size;
};

template <typename T, typename Compare >
HeapSort<T,Compare>::HeapSort(T* arr, int size)
	:_arr(arr)
	,_size(size)
{
}

template <typename T,typename Compare>
void HeapSort<T,Compare>::heapAdjust(int pos, int len,Compare com)//com声明中已默认初始化
{																//此处不用再写			
	int father = pos;
	int son = 2 * father + 1;

	while(son < len)
	{
		//com这样使用
		if(son+1<len&&com(_arr[son],_arr[son+1]))
		{
			++son;	
		}
		if(com(_arr[father],_arr[son]))
		{
			T temp = _arr[father];
			_arr[father] = _arr[son];
			_arr[son] = temp;
		}
		father = son;
		son = 2 * son + 1;
	}
}	
template <typename T,typename Compare>
void HeapSort<T,Compare>::sort()
{
	for(int i=_size/2-1; i >= 0 ; --i )
	{
		heapAdjust(i,_size);
	}

	for(int i=_size -1 ; i !=0 ; --i)
	{
		T temp = _arr[0];
		_arr[0] = _arr[i];
		_arr[i] = temp;
		heapAdjust(0,i);	
	}
}


