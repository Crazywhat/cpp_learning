 ///
 /// @file    main.cc
 /// @date    2018-08-13 23:18:19
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class A
{
	public:
		virtual void a(){ cout << "A::a()" << endl;}
		virtual void b(){ cout << "A::b()" << endl;}
		virtual void c(){ cout << "A::c()" << endl;}
};
class B 
{
	public:
		virtual void a(){ cout << "B::a()" << endl;}
		virtual void b(){ cout << "B::b()" << endl;}
		void c(){ cout << "B::c()" << endl;}
		void d(){ cout << "B::d()" << endl;}
};
class C
:public A
,public B
{
	public:
		virtual void a(){ cout << "C::a()" << endl;}
		void c(){ cout << "C::c()" << endl;}
		void d(){ cout << "C::d()" << endl;}
};

void test0()
{
	C c;
	cout << "&c :" << &c << endl;
	A *pa = &c;
	cout << "pa :" << pa << endl;
	B *pb = &c;
	cout << "pb :" << pb << endl;

	cout << "sizeof(A) = " << sizeof(A) << endl;
	cout << "sizeof(B) = " << sizeof(B) << endl;
	cout << "sizeof(C) = " << sizeof(C) << endl;

}

void test1()
{
	C c;
	c.a();//C
//	c.b(); //error 成员名二义性
	c.c();//C
	c.d();//C
	cout << "------------------" << endl;

	A *pa = &c;
	pa->a();//C
	pa->b();//A
	pa->c();//C

	cout << "------------------" << endl;
	B *pb = &c;
	pb->a();//C
	pb->b();//B
	pb->c();//B 静态编译

	cout << "------------------" << endl;
	C *pc = &c;
	pc->a();//C
//	pc->b(); //error
	pc->c();//C
	pc->d();//C

}

int main()
{
	test0();
	//test1();
	return 0;
}
