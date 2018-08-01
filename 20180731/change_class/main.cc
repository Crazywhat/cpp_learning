 ///
 /// @file    main.cc
 /// @date    2018-08-01 08:39:08
 ///
 
#include <iostream>
using std::ostream;
using std::cout;
using std::endl;


class Point
{
public:
	Point(double x,double y):_x(x),_y(y){}
	//类型转化
	//无返回值，却要返回一个相应类型
	//无形参
	//提供Point转double的方法
	operator double();
//	friend ostream & operator <<(ostream &,Point &);
private:
	double _x,_y;
};

//简单返回两者的乘积
Point::operator double()
{
	return _x*_y;
}
/*
ostream & operator <<(ostream &os,Point &p)
{
	os << "( " << p._x << "," << p._y << " )"<< endl;
	return os;
}*/

int main()
{

	Point p(12.3,13);

	//会自动转化成double类型
	cout << p << endl;

	return 0;
}
