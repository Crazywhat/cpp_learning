 ///
 /// @file    main.cc
 
#include <iostream>

using std::cout;
using std::endl;


//声明命名空间B
namespace B
{
	void printB();
};

//定义命名空间A
namespace A {
	int num=23;
	void printA()
	{
		cout<<"namespace A::print"<<endl;
		B::printB();   //使用命名空间B中的函数
	}

};

//定义命名空间B
namespace B
{
	int num_b=10;
	void printB(){
		cout<<"namespace B print"<<endl;
		A::printA(); //使用命名空间A中的函数
	}

};


int main(){

	A::printA();
	B::printB();

	return 0;
}
