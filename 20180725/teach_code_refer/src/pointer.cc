 ///
 /// @file    pointer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-25 09:49:18
 ///
 
#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;

int * p1;

int func1()
{
	int num = 10;
	return num;
}
 
int test0(void)
{
	int * p2;//野指针
	*p2 = 10;
	printf("p1 = %p\n", p1);
	printf("p2 = %p\n", p2);
	return 0;
}

int main(void)
{
	int a = func1();
	printf("&a = %p\n", &a);

	//&func1();//右值
	//int & ref = func1();//非const引用不能绑定到右值 (不能取地址的变量)
	const int & ref = 10;//const引用可以绑定到右值
	const int & ref1 = func1();

	return 0;
}
