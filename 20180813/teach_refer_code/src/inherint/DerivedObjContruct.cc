 ///
 /// @file    DerivedObjContruct.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-08-13 16:24:39
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
	Base() : _dbase(0) 
	{
		cout << "Base()" << endl;	
	}

	Base(double dbase)
	: _dbase(dbase)
	{	cout << "Base(double)" << endl;	}

	~Base(){	cout << "~Base()" << endl;	}
private:
	double _dbase;
};


class Derived
: public Base
{
public:
#if 0
	Derived()
	: Base()
	{
		cout << "Derived()" << endl;
	}
#endif

	void display() const 
	{	cout << "Derived::display()" << endl;	}
};

//派生类对象的构造：有问题的说法( 先调基类的构造函数，再调派生类构造函数)
//1. 首先调用派生类的构造函数
//2. 然后在执行派生类构造函数过程之中，要执行初始化列表；
//3. 再在初始化列表执行的过程中调用了基类的构造函数
 
int main(void)
{
	Derived d;//调用默认构造函数创建对象
	d.display();

	return 0;
}
