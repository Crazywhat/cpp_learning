 ///
 /// @file    main.cc
 /// @date    2018-08-08 20:53:42
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class A
{
public:
	A(int){
		cout << "A(int)" << endl;
	}
	A(const A&)
	{
		cout << "A(const & A)" << endl;
	}
};

int main(){

	A a = 10; //未调用复制构造函数
			//进行了copy_elision优化

	return 0;
}
