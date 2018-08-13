 ///
 /// @file    test.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-08-06 10:04:36
 ///
 
#include <iostream>
using std::cout;
using std::endl;

void test0(void)
{
	static const char * xml = 
		"<?xml version ?>"
		"<PLAY>"
		"</PLAY>";

	cout << xml << endl;
}
 
int main(void)
{
	test0();
	return 0;
}
