 ///
 /// @file    namespace1.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-24 09:47:28
 ///
 
#include <iostream>
using namespace std;// using编译指令, 会把命名空间std中的所有实体一次性全部引进来, 有可能造成二义性问题

namespace A
{

void displayA()
{
	cout << "A::displayA() " << endl;
}

}//end of namespace A

using namespace A;

void cout() 
{
	
}


int main(void)
{
	displayA();
	cout();
	return 0;
}
