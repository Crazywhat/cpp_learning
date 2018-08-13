 ///
 /// @file    main.cc
 /// @date    2018-08-11 16:30:45
 ///
 
#include <iostream>
using std::cout;
using std::endl;


class Null
{

};

class A
{
	public:
		virtual void print(){ cout << "0" << endl; };
		virtual void print1(){ cout << "1" << endl;};
};
class B
{
	public:
		int num;
		virtual void print(){ cout << "0" << endl; };
};
class C:public B
{
};
class D:public B
{
	public:
		virtual void print(){ cout << "0" << endl; };
};
class E:public B
{
	public:	
		virtual void print(){ cout << "0" << endl; };
		virtual void printE0(){ cout << "0" << endl; };
		virtual void printE1(){ cout << "0" << endl; };
};

int main()
{
	Null n;
	A a;
	B b;
	C c;
	D d;
	E e;
	cout <<  "n size: " << sizeof(n) << endl;
	cout <<  "a size: " << sizeof(a) << endl;
	cout <<  "b size: " << sizeof(b) << endl;
	cout <<  "c size: " << sizeof(c) << endl;
	cout <<  "d size: " << sizeof(d) << endl;
	cout <<  "e size: " << sizeof(e) << endl;

	return 0;
}

