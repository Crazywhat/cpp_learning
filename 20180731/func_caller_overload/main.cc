 ///
 /// @file    main.cc
 /// @date    2018-08-01 12:58:33
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Fco
{
public:
	Fco():_count(0){};
//对函数调用符的重载
int	operator ()(int num0,int num1)
	{
		++_count;
		return num0*num1;
	}
double operator ()(double d0,double d1)
	{
		return d0*d1;
	}
void print_count(){
	cout << "count : " << _count << endl;
}
private:
	int _count;
};

int main()
{
	Fco f1;
////重载了函数调用运算符的类创建的对象，称为 函数对象
////函数对象携带了状态  ==> 闭包  ==> lambda表达式 (匿名函数对象)
	cout << f1(3,4) << endl;
	cout << f1(3.5,4.0) << endl;
	f1.print_count();

	return 0;
}
