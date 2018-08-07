 ///
 /// @file    main.cc
 /// @date    2018-08-07 10:40:49
 ///
#include <string>
#include <functional> 
#include <iostream>
using std::cout;
using std::endl;
using std::string;
using std::bind;
using std::function;

template <typename T>
void display(T t)
{
	cout << t << endl;
}

void test0()
{
	function<void(string)> f = bind(display<string>,std::placeholders::_1);
	f("fun");
}

typedef void (*funp)(string);

void test1()
{
	funp f_display=display<string>;
	function<void(string)> f = bind(f_display,std::placeholders::_1);
	f("fun");
}

template <typename T>
struct DisPlay
{
	void operator()(T t)
	{
		cout << t << endl;
	}
	static	T add(T t0,T t1)
	{
		return t0+t1;
	}
	static	T megre(T t0,T t1,T t2)
	{
		return t0+t1+t2;
	}
	T add_no_static(T t0,T t1)
	{
		return t0+t1;
	}
};
void test2()
{
	function<void(string)> f = bind(DisPlay<string>(),std::placeholders::_1);
	f("good morning");

	function<string(string,string)> f1 = bind((DisPlay<string>::add),std::placeholders::_1,std::placeholders::_2);
	cout << f1("what hell !"," Just` eat it .") << endl;

	function<int(int,int)> f2 = bind(DisPlay<int>::megre,std::placeholders::_1,888,std::placeholders::_2);
	cout << f2(2,110) << endl;

	//调用非静态成员函数
	//须定义一个对象，并占第一位
	//调用时，将对象传入
	DisPlay<int> e;
	DisPlay<string> es;
	function<int(DisPlay<int>*,int)> f3 = bind(&DisPlay<int>::add_no_static,std::placeholders::_1,888,std::placeholders::_2);
	cout << f3(&e,110) << endl;
	function<string(DisPlay<string>,string)> f4 = bind(&DisPlay<string>::add_no_static,std::placeholders::_1," good ",std::placeholders::_2);
	cout << f4(es,"very") << endl;
}

int main()
{
	test0();
	test1();
	test2();
	return 0;
}
