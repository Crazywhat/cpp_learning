 ///
 /// @file    main.cc
 /// @date    2018-08-12 20:52:39
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class base
{
	public:
		void func(int x)
		{
			cout << "base x = " << x << endl;
			cout << "base func()" << endl;
		}
};

class derived
:public base
{
	public:
		//会将与基类中同名的普通成员函数隐藏
		int func()
		{
			cout << "derived func()" << endl;
			return 0;
		}
};

int main()
{

	derived d;
	d.func();
	//d.func(12); //no matching function , 基类中的func被隐藏
	d.base::func(12);

	return 0;
}
