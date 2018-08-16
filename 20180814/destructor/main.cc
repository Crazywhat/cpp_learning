 ///
 /// @file    main.cc
 /// @date    2018-08-14 22:06:21
 ///
#include <cstring> 
#include <iostream>
using std::cout;
using std::endl;

class Base 
{
	public:
		Base(){cout << "Base()" << endl;}
		virtual ~Base(){cout << "~Base()" << endl;}
};
class Derived
:public Base
{
	public:
		Derived(const char* pstr)
			:_pstr(new char[strlen(pstr)+1])
		{
			strcpy(_pstr,pstr);
			cout << "Derived()" << endl;
		}
		~Derived()
		{
			delete [] _pstr;
			cout << "~Derived()" << endl
		;}
	private:
		char* _pstr;
};

int main()
{
	Base *pb = new Derived("hello");

	delete pb;

	return 0;
}
