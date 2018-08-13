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
	Base()
	{
		cout << "Base()" << endl;
	}
	Base(const char* pdata)
		:_pbdata(new char[strlen(pdata)+1])
	{
		cout << "Base(const char* pdata)" << endl;
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
	void show(){ cout << "Base :" << _pbdata << endl;}
	private:
		char* _pbdata;
};

//派生类中显示定义复制控制函数，且基类中同样有所显示定义
//则派生类对象执行复制控制函数时，
//需要显示调用基类中显示定义的复制控制函数
class Derive
:public Base
{
	public:
		Derive(const char* pdata,const char* pddata)
			:Base(pdata)
			 ,_pddata(new char[strlen(pddata)+1])
		{
			strcpy(_pddata,pddata);
		}
		//须显示调用基类的复制构造函数
		//Base(rhs)
		Derive(const Derive& rhs)
			:Base(rhs)
			,_pddata(new char [strlen(rhs._pddata)+1])
		{
			strcpy(_pddata,rhs._pddata);
			cout << "Derive(const Derive& rhs)" << endl;
		}
		//须显示调用基类的赋值operator=
		//Base::operator=(rhs)
		Derive & operator=(const Derive & rhs)
		{
			Base::operator=(rhs);
			if(this != &rhs)
			{
				delete [] _pddata;
				_pddata = new char[strlen(rhs._pddata)+1];
				strcpy(_pddata,rhs._pddata);
			}
			cout << "Derive & operator=(const Derive & rhs)" << endl;
			return *this;
		}
		void show_in_Derive()
		{
			cout << "--------------------------" << endl;
			show();
			cout << "Derive :" << _pddata << endl;
			cout << "--------------------------" << endl;
		}
	private:
		char* _pddata;
};

int main()
{
	Derive d("hello","world");
	Derive d1 = d;
	d.show_in_Derive();
	d1.show_in_Derive();

	cout << "-----------------------------" << endl;

	Derive d2("good","morning");
	d = d2;
	d.show_in_Derive();

	return 0;
}
