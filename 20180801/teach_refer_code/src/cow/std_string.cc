 ///
 /// @file    std_string.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-08-01 11:24:47
 ///
 
#include <stdio.h>
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
 
int main(void)
{
	string s1 = "hello,world";
	string s2 = s1;
	string s3 = s2;
	cout << "sizeof(string) = " << sizeof(string) << endl;
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	printf("s1'address = %p\n", s1.c_str());
	printf("s2'address = %p\n", s2.c_str());
	printf("s3'address = %p\n\n", s3.c_str());

	s1[0] = 'X';
	cout << "执行修改操作:" << endl;
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	printf("s1'address = %p\n", s1.c_str());
	printf("s2'address = %p\n", s2.c_str());
	printf("s3'address = %p\n\n", s3.c_str());

	return 0;
 
}
