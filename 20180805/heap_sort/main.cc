///
/// @file    main.cc
/// @date    2018-08-06 12:43:43
///
#include "headsort.h"
#include <cmath>
#include <iostream>
#include <string>
using std::ostream;
using std::string;
using std::cout;
using std::endl;

int test0()
{
	int arr[10] = {1,3,2,5,4,7,6,9,8,0};

	HeapSort<int> hint(arr,10);

	hint.sort();

	for(int i=0; i!=10 ; ++i)
		cout << arr[i] << endl;

	return 0;
}


int test1()
{
	string arr[8] = {string("boat"),string("apple"),string("deer"),
		string("ear"),string("hot"),string("cat"),
		string("float"),string("goat")};

	HeapSort<string,std::greater<string> > hint(arr,8);

	hint.sort();

	for(int i=0; i!=8 ; ++i)
		cout << arr[i] << endl;

	return 0;
}

//-----------------------------------------------------------------
class Point
{
	public:
		Point(int x=0,int y=0)
			:_x(x)
			 ,_y(y)
	{
		cout << "construct point" << endl;
	}

		float distance() const
		{
			return sqrt(_x*_x+_y*_y);
		}
		friend bool operator < (const Point &lhs,const Point &rhs);
		friend bool operator > (const Point &lhs,const Point &rhs);
		friend ostream& operator<<(ostream &os,const Point &p);
	private:
		int _x,_y;

};
bool operator < (const Point& lhs,const Point& rhs)
{
	return lhs.distance() < rhs.distance();
}
bool operator > (const Point& lhs,const Point& rhs)
{
	return lhs.distance() > rhs.distance();
}
ostream& operator<<(ostream &os,const Point &p)
{
	os << "( " << p._x << " , " << p._y << " )";
	return os;
}

int test2()
{
	Point arr[8] = {Point(1,3),Point(1,2),Point(2,4),
		Point(2,2),Point(3,3),Point(1,4),
		Point(5,4),Point(1,9)};

	//HeapSort<Point,std::greater<Point> > hint(arr,8);
	HeapSort<Point > hint(arr,8);

	hint.sort();

	for(int i=0; i!=8 ; ++i)
		cout << arr[i] << endl;

	return 0;
}


int main(){

	test2();
	return 0;
}
