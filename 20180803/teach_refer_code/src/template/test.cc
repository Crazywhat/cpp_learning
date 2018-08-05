 ///
 /// @file    test.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-08-03 10:56:32
 ///
 
#include "template.h"  //先从当前路劲查找，然后再从系统路径查找

#include <iostream> // 只会从系统路劲查找, 不会查找当前路径
using std::cout;
using std::endl;
 
template <typename Type>
Type add(Type x, Type y);

int main(void)
{
	int a = 3, b = 4;
	cout << add(a, b) << endl;

	return 0;
}
