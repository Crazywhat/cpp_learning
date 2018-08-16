 ///
 /// @file    main.cc
 /// @date    2018-08-14 08:26:18
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base
{
	public:
		Base(int data)
			:_baseData(data)
		{	}
		virtual void print0(){	cout << "Base::print0()" << endl;}
		virtual void print1(){	cout << "Base::print1()" << endl;}
		virtual void print2(){	cout << "Base::print2()" << endl;}
	private:
		long _baseData;
};
class Derived
:public Base
{
	public:
		Derived(int basedata,int der_data)
			:Base(basedata)
			,_derivedData(der_data)
		{	}
		virtual void print0(){	cout << "Derived::print0()" << endl;}
		virtual void print1(){	cout << "Derived::print1()" << endl;}
		virtual void print2(){	cout << "Derived::print2()" << endl;}
	private:
		long _derivedData;
};

int test0()
{
	//可证明虚数表的存在
	Derived d(99,56);

	long *pd = (long*)&d;

	//直接访问_baseData
	cout << pd[1] << endl;
	//直接访问_derivedData
	cout << pd[2] << endl;

	typedef void(*func)();

	//获取虚数表地址
	long *pfunc = (long*)*pd;
	//调用Derived各虚函数	
	(func(pfunc[0]))();
	(func(pfunc[1]))();
	(func(pfunc[2]))();
	
	return 0;
}

int test1()
{
	//可证明虚数表的存在
	Base b(999);

	long *pb = (long*)&b;

	//直接访问_baseData
	cout << pb[1] << endl;

	typedef void(*func)();

	//获取虚数表地址
	long *pfunc = (long*)*pb;
	//调用Derived各虚函数	
	(func(pfunc[0]))();
	(func(pfunc[1]))();
	(func(pfunc[2]))();

	return 0;
}

int main()
{
	test0();
	cout << "------------------------------" << endl;
	test1();
	return 0;
}
