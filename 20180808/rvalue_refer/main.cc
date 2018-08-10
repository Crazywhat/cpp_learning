 ///
 /// @file    main.cc
 /// @date    2018-08-08 16:02:57
 ///
#include <cstring>
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class String
{
	public:
		String()
			:_pstr(NULL)
		{}
		String(const char* pstr)
			:_pstr(new char[strlen(pstr)+1]())
		{
			strcpy(_pstr,pstr);
			cout << "String(const char* pstr)" << endl;
		}
		//复制构造函数
		String(const String& rhs)
			:_pstr(new char[strlen(rhs._pstr)+1]())
		{
			strcpy(_pstr,rhs._pstr);
			cout << "String(const String& rhs)" << endl;
		}
		//转移构造函数
		//当右值传入的时候，会优先调用转移构造函数
		//当无转移构造函数的时候，才会调用复制构造函数
		String(String&& rhs)
			:_pstr(rhs._pstr)
		{
			rhs._pstr = NULL;
			cout << "String(const String&& rhs)" << endl;
		}
		~String()
		{
			if(_pstr)
				delete [] _pstr;
			cout << " ~String()" << endl;
		}
		String& operator=(const String& rhs)
		{
			cout << "operator= (String& rhs)" << endl;
			 if(_pstr)
				 delete [] _pstr;
			 _pstr = new char[strlen(rhs._pstr)+1];
			 strcpy(_pstr,rhs._pstr);
			 return *this;
		}
		String& operator= (String&& rhs)
		{
			cout << "operator= (String&& rhs)" << endl;
			 if(_pstr)
				 delete [] _pstr;
			 _pstr = rhs._pstr;
			 rhs._pstr = NULL;
			 return *this;
		}
		const char* c_str()
		{
			return _pstr;
		}
		friend std::ostream& operator << (std::ostream &os, const String &rhs);
	private:
		char* _pstr;
};

std::ostream& operator << (std::ostream &os, const String &rhs)
{
	cout << rhs._pstr;
	return os;
}

int test0()
{
	vector<String> v;
	String s = "hello";	
	//v.push_back("hello");
	//s = "goodbye";
	cout << s << endl;

	//v.push_back(s);
	//std::move() ,将左值转变为右值(本质上是类型强制转化)
	v.push_back(std::move(s));

	cout << s << endl;
	
	cout << "--------end_line------" << endl;

	return 0;
}

int test1()
{
	//右值引用，本身也是一种类型
	//也存在左值右值的情况
	//一般有名字为左值，无名字为右值
	String&& s_ref = "hello world";
	
	vector<String> vs;


	String s = s_ref; //ok , 调用复制构造String(const String& rhs)
						//可见s_ref 本身是一个左值
	String s2 = "fun";
	s2 = s_ref;        //ok, 调用operator= (String& rhs)
						//可见s_ref 本身是一个左值					

	vs.push_back(s_ref);//ok 

	cout << s_ref << endl;


	return 0;
}

int main()
{ 


	test1();

	return 0;
}
