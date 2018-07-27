 ///
 /// @file    Point.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-27 14:50:22
 ///
 
#include <iostream>
using std::cout;
using std::endl;


class Point
{
public:
	explicit // 禁止隐式转换
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int ix =0,int iy=0)" << endl;
	}

	void print()const
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}

private:
	int _ix;
	int _iy;
};
 
int main(void)
{
	Point pt = 1;// 隐式转换
	
	pt.print();

	return 0;
}
