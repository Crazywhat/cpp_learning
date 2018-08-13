 ///
 /// @file    main0.cc
 /// @date    2018-08-12 21:57:02
 ///
 
#include <cstring>
#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
	Base(const char* pdata)
		:_pbdata(new char[strlen(pdata)+1])
	{
		cout << "  Base(const char* pdata)" << endl;
		strcpy(_pbdata,pdata);
	}
	Base(const Base& rhs)
		:_pbdata(new char[strlen(rhs._pbdata)+1])
	{
		strcpy(_pbdata,rhs._pbdata);
		cout << "Base(const Base& rhs)" << endl;
	}
	Base& operator=(const  Base& rhs)
	{
		if(this!=&rhs)
		{
			delete [] _pbdata;
			_pbdata = new char[strlen(rhs._pbdata)+1];
			strcpy(_pbdata,rhs._pbdata);
		}
		cout << "Base& operator=(const  Base& rhs)" << endl;
		return *this;
	}
	void show(){ cout << _pbdata << endl;}
	private:
		char* _pbdata;
};

//派生类中未显示定义复制控制函数，而基类中有所显示定义
//则派生类对象执行默认复制控制函数时，
//会自动调用基类中显示定义的复制控制函数
class Derive
:public Base
{
	public:
		Derive(const char* pdata)
			:Base(pdata)
		{
		
		}
};

int main()
{
	Derive d("hello");
	Derive d1 = d;
	d.show();
	d1.show();

	cout << "-----------------------------" << endl;

	Derive d2("world");
	d = d2;
	d.show();

	return 0;
}
