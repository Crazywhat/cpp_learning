///
/// @file    string.cc

#include <string.h>

#include <iostream>

using std::cout;
using std::endl;

class String
{
	public:
		String();
		String(const char *pstr);
		String(const String & rhs);
		String & operator=(const String & rhs);
		~String();

		void print();

	private:
		char * _pstr;
};

String::String()
{
	cout << "construction null" << endl;
	_pstr=NULL;
}

String::String(const char *pstr)
{
	cout << "construction by pstr " << endl;
	_pstr=new char[strlen(pstr)+1];
	strcpy(_pstr,pstr);
}

String::String(const String & rhs):_pstr(new char[strlen(rhs._pstr)+1])
{
	cout << "copy_construction " << endl;
	strcpy(_pstr,rhs._pstr);
}

String & String::operator=(const String & rhs)
{

	cout << "operator =" << endl;

	if(this==&rhs) return *this;

	delete [] _pstr;
	_pstr= new char[strlen(rhs._pstr)+1];
	strcpy(_pstr,rhs._pstr);

	return *this;

}

String::~String()
{
	cout << "~String" << endl;
	if(_pstr)
		delete[] _pstr;
}

void String::print()
{
	if(_pstr)
		cout << _pstr << endl;
}

String func(String & str){
	cout << "func" << endl;
	return str;
}

int main(){

	cout << "str1 :" << endl;
	
	String str1;
	str1.print();
		
	cout << endl;

	String str2 = "Hello,world";
	String str3("wangdao");

	cout << "str2 :" << endl;
	str2.print();		
	cout << "str3 :" << endl;
	str3.print();	

	cout << endl;

	String str4 = str3;
	 cout << "str4 :" << endl;
	str4.print();

	cout << endl << "str4 = str2 :" << endl; 
	str4 = str2;
	str4.print();

	cout << endl;

	func(str4);

	return 0;
}
