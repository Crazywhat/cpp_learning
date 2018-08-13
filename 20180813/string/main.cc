 ///
 /// @file    main.cc
 /// @date    2018-07-31 19:48:24
 ///
#include "string.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int test0(void)
{
	String s1="hello world";
	
	const String s2("good");

	cout << s2[1] << endl;

	cout << s2.size() << endl;

	String s3;

	cout << s2.c_str() << endl;
	cout << s3.c_str() << endl;

//	cout <<( s2 == s3) << endl;
//	cout << (s2 == String("good")) << endl;
//	cout << (s2 != String("good")) << endl;

	
	String s4("a");
	String s5("b");


	cout << "s4 < s5 : " << (s4 < s5) <<endl;
	cout << "s4 <= s5 : " << (s4 <= s5) <<endl;
	cout << "s4 > s5 : " << (s4 > s5) <<endl;
	cout << "s4 >= s5 : " << (s4 >= s5) <<endl;


	cout << "s1: " << s1 << endl << "s3: "<< s3 << endl;
	
	String s6;

	cin >> s6;
	cout << "s6: " << s6 << endl;

	const char* cstr = "hello";

	String s7 = s1 + s6;
	String s8 = s1 + cstr;
	String s9 = cstr + s1;
	//s3 未初始化
	String s10 = (s3 + s1) ;

	cout << "s7: " << s7 << endl;
	cout << "s8: " << s8 << endl;
	cout << "s9: " << s9 << endl;
	cout << "s10: " << s10 << endl;


	return 0;
}


int test1()
{
	String test("test");
	String s0(std::move(test));
	cout << s0 << endl;
	
	s0 = String("fun");

	cout << s0 << endl;

		
	return 0;
}

int main()
{
	test1();
	return 0;
}
