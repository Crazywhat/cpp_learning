 ///
 /// @file    memberTemplate.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-08-03 11:10:32
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
	Point(double dx = 0, double dy = 0)
	: _dx(dx)
	, _dy(dy)
	{}

	//成员函数本身也可以是一个函数模板， 称为成员模板
	template <typename T>
	T typeCast()
	{
		return (T) _dx * _dy;
	}
private:
	double _dx;
	double _dy;
};
 
int main(void)
{
	Point pt(1.1, 3.2);
	cout << pt.typeCast<int>() << endl;
	return 0;
}
