 ///
 /// @file    testAdd.cc   
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-24 16:19:40
 ///
 

//一个.cc文件就是一个单独的模块
#include "add.h"   

#include <iostream>
using std::cout;
using std::endl;
 
int main(void)
{
	int a = 3, b = 4;
	cout << add(a, b) << endl;

	return 0;
}
