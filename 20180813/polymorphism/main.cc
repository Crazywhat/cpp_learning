 ///
 /// @file    main.cc
 /// @date    2018-08-13 07:50:17
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base 
{
	public:
		Base(double data)
			:_pdata(data)
		{}	
		virtual void show(){cout << "base :" << _pdata << endl;}
		//void show(){cout << "base :" << _pdata << endl;}
		
		//即使通过基类的成员函数来调用虚函数
		//也呈现动态多态
		void callbase0()
		{	
			show();
		}
		void callbase1()
		{
			Base::show();
		}
	private:
		double _pdata;
};
class	Derive
:public Base
{
	public:
		Derive(double data_base,double data)
			:Base(data_base)
			,_pdata(data)
		{}	
		virtual void show(){cout << "Derive :" << _pdata << endl;}
		//void show(){cout << "Derive :" << _pdata << endl;}
	private:
		double _pdata;
};

void display(Base* pb)
{
	pb->show();
}

void test0()
{
	Base b(12.34);
	Derive d(12.34,56.78);
	display(&b);
	display(&d);
}
void test1()
{
	cout << "sizeof(Base) = " << sizeof(Base) << endl;
	cout << "sizeof(Derive) = " << sizeof(Derive) << endl;

}
void test2()
{
	Derive d(1.2,3.4);
	d.callbase0();//调用继承基类的成员函数，也呈现动态多态特性
	d.callbase1();
}

//构造函数为什么不能设置为虚函数?
//因为虚函数的访问是通过对象的虚函数指针来访问的
//对象未创建，无虚函数指针，无法访问虚函数表

int main()
{
	//test0();
	test1();
	//test2();
	return 0;
}
