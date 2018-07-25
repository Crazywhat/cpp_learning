 ///
 /// @file    namespace1.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-24 09:47:28
 ///
 
#include <iostream>

namespace A
{

void displayA()
{
	std::cout << "A::displayA() " << std::endl;// 作用域限定符
}

}//end of namespace A

using namespace A;

void cout() 
{
	std::cout << "cout() " << std::endl;
}

int main(void)
{
	displayA();
	cout();
	return 0;
}
