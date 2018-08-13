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
		void show(){cout << "A show()" << endl;}
};
class B
:virtual public A  //虚继承
{
	public:
		void print(){cout << "B print()" << endl;}
};
class C
:virtual public A  //采用虚继承
{};

class D
:public B
,public C
{

};

int main()
{
	D d;
	
	//d.show(); //多重继承产生的二义性：存储空间的二义性
			    //解决方法：采用虚继承	
	d.show();
	return 0;
}
