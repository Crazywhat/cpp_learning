 ///
 /// @file    main.cc
 /// @date    2018-08-13 10:39:50
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//由于创建和销毁基类和派生类对象的顺序
//构造函数中对虚函数的调用为静态编译

class A
{
public: 
	A(){
		func1();
	}
	~A(){func1();}
	virtual void func1()
	{
		cout << "A: func1()" << endl;
	}
};
class B
:public A
{
public: 
	B(){
		func1();
	}
	~B(){func1();}
	virtual void func1()
	{
		cout << "B: func1()" << endl;
	}
};

class C 
:public B
{
public: 
	C(){
		func1();
	}
	~C(){func1();}
	virtual void func1()
	{
		cout << "C: func1()" << endl;
	}
};

int main()
{
	C c;
	return 0;
}
