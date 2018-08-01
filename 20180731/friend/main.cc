 ///
 /// @file    main.cc
 /// @date    2018-07-31 15:39:15
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//前置申明
class Area;
class Line;

//定义Perimeter
//show_perimeter的实现放在Line类后
//不然即使设置了友元，也无法访问Line的_length
class Perimeter
{
	public:
		void show_perimeter(Line &l1, Line &l2);
};


class Line
{
public:
	Line(double len):_length(len){}
	//其他类成员函数的友元函数
	friend void Perimeter::show_perimeter(Line &l1, Line &l2);
	//友元类，可以使用所有的成员
	friend class Area;
private:
	//友元函数放在private，public中皆可	
	friend void get_line_length(Line & l);
	void show(){ cout << "line_length : " << _length << endl;}
private:
	double _length;
};

//普通友元函数
void get_line_length(Line & l)
{
	l.show();
}

//友元类
class Area
{
public:
	Area(Line& l1,Line& l2)
		:_l1(l1)
		 ,_l2(l2)
		,_area(_l1._length * _l2._length)
	{
		cout << "Area : " << _area << endl;
	}

private:
	Line &_l1,&_l2;
	double _area;
	
};

//show_perimeter的实现
void Perimeter::show_perimeter(Line &l1, Line &l2)
{
	cout << "Perimeter : " << 2 * l1._length + 2 * l2._length << endl;
}

int test0(){
	Line l(30.2);
	get_line_length(l);

	return 0;
}

int main(void)
{
	Line l1(45),l2(56);

	Area a(l1,l2);
	
	Perimeter p;
	p.show_perimeter(l1,l2);

	return 0;
}




