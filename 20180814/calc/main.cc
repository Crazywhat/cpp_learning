 ///
 /// @file    main.cc
 /// @date    2018-08-16 21:16:28
 ///
#include "node.h" 
#include <iostream>
using std::cout;
using std::endl;

void test()
{
	CalcNode c = CalcNode(2)+CalcNode(6) / -CalcNode(5) + -CalcNode(20);
	cout << "result :" << c.calc() << endl;
}

int main()
{
	test();
	return 0;
}
