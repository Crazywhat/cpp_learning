 ///
 /// @file    line.cc
 /// @date    2018-08-01 09:15:05
 ///
#include "line.h" 
#include <iostream>
using std::cout;
using std::endl;

class Line::LineImpl
{
public:
	LineImpl(){}
	LineImpl(double x,double y):_x(x),_y(y){}
	double _x,_y;
};

Line::Line(int x0,int y0,int x1,int y1)
	:_pimpl(new LineImpl[2])
{
	_pimpl[0]._x=x0;
	_pimpl[0]._y=y0;
	_pimpl[1]._x=x1;
	_pimpl[1]._y=y1;
}
Line::~Line()
{
	delete [] _pimpl;
}

void Line::printLine() const
{
	cout << "(" <<  _pimpl[0]._x << "," <<  _pimpl[0]._y << ")"
		<< "-->"
		<< "(" <<  _pimpl[1]._x << "," <<  _pimpl[1]._y << ")"
		<< endl;
}
