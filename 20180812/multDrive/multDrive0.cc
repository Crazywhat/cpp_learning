 ///
 /// @file    multDrive0.cc
 /// @date    2018-08-12 19:49:05
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class A
{
	public:
		void print(){cout << "A print()" << endl;}
};
class B 
{
	public:
		void print(){cout << "B print()" << endl;}
};
class C
:public A
,public B
{};

int main()
{
	C c;
	//c.print(); //成员名冲突的二义性
	//解决,作用域限定符
	c.A::print();
	c.B::print();
	
	
	return 0;
}
