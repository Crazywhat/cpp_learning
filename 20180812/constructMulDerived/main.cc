 ///
 /// @file    main.cc
 /// @date    2018-08-12 20:41:09
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class A
{
public:
	A(){cout << "A()" << endl;}
	~A(){cout << "~A()" << endl;}
};

class B
{
public:
	B(){cout << "B()" << endl;}
	~B(){cout << "~B()" << endl;}
};


class X
{
public:
	X(int data):_data(data){cout << "X(int data) "<< _data << endl; }
	X(){cout << "X()" << endl; }
	~X(){cout << "~X()" << endl; }
private:
	int _data;
};

class C
:public A
,public B
{
public:
	C():A(),B(){cout << "C()" << endl;}
	~C(){cout << "~C()" << endl;}
private:
	X _x;
};

class D 
:public B
,public A
{
public:
	D(int data):_x(data),A(),B(){cout << "D()" << endl;}
	~D(){cout << "~D()" << endl;}
private:
	X _x;
};

int test0()
{
	C c;
	return 0;
}
int test1()
{
	D d(9);
	return 0;
}

int main()
{
	test0();
	cout << "---------------" << endl;
	test1();
	return 0;
}
