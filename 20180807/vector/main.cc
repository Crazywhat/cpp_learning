///
/// @file    main.cc
/// @date    2018-08-07 22:07:21
///
#include "vector.h" 
#include <iostream>
#include <string>
using std::allocator;
using std::cout;
using std::endl;
using std::ostream;
using std::string;

template <typename T>
allocator<T> Vector<T>::_alloc;

int test0()
{
	int arr[10] = {1,2,3,4,5,6,7,8,9,0};
	Vector<int> my_v;
	for(int i=0; i != 10; ++i)
	{
		my_v.push_back(arr[i]);	
		cout << "my_v[" << i << "] = " << my_v[i] 
			<< "; size: "  << my_v.size() 
			<< "; capacity: " << my_v.capacity()
			<< endl;
	}
	for(int i=0; i != 10; ++i)
	{
		my_v.pop_back();
		cout << "vector["<< 9-i << "] = " << my_v[9-i] 
			<<"; size :" << my_v.size() << endl;

	}

	return 0;
}

int test1()
{
	string arr[6]{"good","bad","enjoy","touch",
		"like","house"};
	Vector<string> my_v;
	for(int i=0; i != 6; ++i)
	{
		my_v.push_back(arr[i]);	
		cout << "my_v[" << i << "] = " << my_v[i] 
			<< "; size: "  << my_v.size() 
			<< "; capacity: " << my_v.capacity()
			<< endl;
	}
	for(int i=0; i != 6; ++i)
	{
		my_v.pop_back();
		cout << "vector["<< 5-i << "] = " << my_v[5-i] 
			<<"; size :" << my_v.size() << endl;

	}

	return 0;
}

class Point
{
	public:
		Point(int x=0,int y=0)
			:_x(x)
			 ,_y(y)
	{
	}
		friend ostream& operator<<(ostream &os,const Point &p);
	private:
		int _x,_y;

};

ostream& operator<<(ostream &os,const Point &p)
{
	os << "( " << p._x << " , "
		<< p._y << " )";
	return os;
}
int test2()
{
	Point arr[6]{Point(1,1),Point(2,2),Point(3,4),Point(4,4),
				Point(5,5),Point(6,6)};
	Vector<Point> my_v;
	for(int i=0; i != 6; ++i)
	{
		my_v.push_back(arr[i]);	
		cout << "my_v[" << i << "] = " << my_v[i] 
			<< "; size: "  << my_v.size() 
			<< "; capacity: " << my_v.capacity()
			<< endl;
	}
	for(int i=0; i != 6; ++i)
	{
		my_v.pop_back();
		cout << "vector["<< 5-i << "] = " << my_v[5-i] 
			<<"; size :" << my_v.size() << endl;

	}

	return 0;
}

int main(){
	test0();
	cout << "---------------------------------" << endl;
	test1();
	cout << "---------------------------------" << endl;
	test2();
	return 0;
}
