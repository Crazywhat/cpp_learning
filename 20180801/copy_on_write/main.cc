///
/// @file    main.cc
/// @date    2018-08-01 18:23:33
///
#include "string.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
using std::cout;
using std::endl;

void test1(void)
{
	String s1("hello,world");
	//这样赋值会报错，不清楚原因
	//String s1="hello,world";
	String s2 = s1;
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s1 's refcount = " << s1.get_quote() << endl;
	cout << "s2 's refcount = " << s2.get_quote() << endl;
	printf("s1' address = %p\n", s1.c_str());
	printf("s2' address = %p\n", s2.c_str());

	cout << endl;
	String s3("shenzhen");
	printf("s3' address = %p\n", s3.c_str());
	cout << "s3 = " << s3 << endl;
	s3 = s1;
	cout << endl << " >> 执行赋值运算符操作:" << endl;
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	cout << "s1 's refcount = " << s1.get_quote() << endl;
	cout << "s2 's refcount = " << s2.get_quote() << endl;
	cout << "s3 's refcount = " << s3.get_quote() << endl;
	printf("s1' address = %p\n", s1.c_str());
	printf("s2' address = %p\n", s2.c_str());
	printf("s3' address = %p\n", s3.c_str());


	cout << endl;
	s3[0] = 'X';
	cout << "执行修改操作:" << endl;
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	cout << "s1 's refcount = " << s1.get_quote() << endl;
	cout << "s2 's refcount = " << s2.get_quote() << endl;
	cout << "s3 's refcount = " << s3.get_quote() << endl;
	printf("s1' address = %p\n", s1.c_str());
	printf("s2' address = %p\n", s2.c_str());
	printf("s3' address = %p\n", s3.c_str());

	cout << endl;
	cout << "s1[0] = " << s1[0] << endl;
	cout << "对 s1进行读操作" << endl;
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	cout << "s1 's refcount = " << s1.get_quote() << endl;
	cout << "s2 's refcount = " << s2.get_quote() << endl;
	cout << "s3 's refcount = " << s3.get_quote() << endl;
	printf("s1' address = %p\n", s1.c_str());
	printf("s2' address = %p\n", s2.c_str());
	printf("s3' address = %p\n", s3.c_str());

	char ch = s3[5];
	cout << "ch =" << ch << endl;
}


int main(){
	
	test1();

	return 0;
}
