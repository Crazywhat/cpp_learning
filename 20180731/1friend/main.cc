 ///
 /// @file    main.cc
 /// @date    2018-07-31 17:55:35
 ///
 
#include <cmath>
#include <iostream>
using std::cout;
using std::endl;


class Point;

class Line
{
public:
	Line(Point &p1,Point &p2);
private:
	double _length;
};

class Point
{
public:
	Point(double x,double y):_x(x),_y(y){ }
	friend Line::Line(Point &p1,Point &p2);
private:
	double _x,_y;
};

Line::Line(Point &p1,Point &p2)
	:_length(sqrt(pow(p1._x-p2._x,2)+pow(p1._y-p2._y,2)))
{
	cout << "Length : " << _length << endl;
}

int main(void)
{
	Point p1(1,2),p2(4,5);
	
	Line l(p1,p2);

	return 0;
}
