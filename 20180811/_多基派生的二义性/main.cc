 ///
 /// @file    main.cc
 /// @date    2018-08-11 23:15:10
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class A
{
	public:
		virtual void a(){cout << "virtual a() in A" << endl; }
		virtual void b(){cout << "virtual b() in A" << endl; }
		virtual void c(){cout << "virtual c() in A" << endl; }
};
class B 
{
	public:
		virtual void a(){cout << "virtual a() in B" << endl; }
		virtual void b(){cout << "virtual b() in B" << endl; }
		void c(){cout << "c() in B" << endl; }
		void d(){cout << "d() in B" << endl; }
};
class C:public A,public B 
{
	public:
		virtual void a(){cout << "virtual a() in C" << endl; }
		//重写基类A，c()为虚函数
		//隐藏基类B中c()，c()为普通函数
		void c(){cout << "c() in C" << endl; } 
		void d(){cout << "d() in C" << endl; }
};

int main()
{

	C c;
	//c.b(); //二义性，A,B中都有该虚函数
			//解决：c.B::b() 

	A* pa = &c;
	pa->a();//取决于指针指向的对象的类型，调用C::a(),覆盖
	pa->b();//C中未定义，采用静态编译，调用A::b()
	pa->c();//C中定义c()为普通函数，但A中c()为virtual
			//所以无论C中有没有添加virtual，都为虚函数
			//覆盖

	cout << "------------------------" << endl;

	B* pb = &c;
	pb->a();//C::a(),覆盖
	pb->b();//静态编译B::b()
	pb->c();//B中c()为普通函数，C隐藏B中c(),B::c()
			//子类对象不能直接调用到基类的被隐藏的成员数据和成员函数
	pb->d();//B::d()

	cout << "------------------------" << endl;

	C* pc = &c;

	pc->a(); //C::a()
//	pc->b(); //二义性
	pc->c(); //C::c()
	pc->d(); //C::d()
	return 0;
}
