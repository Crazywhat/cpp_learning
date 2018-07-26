 ///
 /// @file    testComputer2.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-25 11:59:17
 ///
 
#include "Computer.h"
#include <iostream>
using std::cout;
using std::endl;
 
int main(void)
{
	Computer com;
	com.setBrand("外星人");
	com.setPrice(10000);
	com.print();

	return 0;
}

