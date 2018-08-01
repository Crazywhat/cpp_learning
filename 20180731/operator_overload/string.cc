///
/// @file    string.cc
/// @date    2018-07-31 19:26:24
/// 
#include "string.h"

#include <cstdio>
#include <cstring>
#include <iostream>
#include <limits>

#define N 1024

using std::cout;
using std::endl;

//缺省构造
String::String()
{
	_pstr=NULL;
}

//char*构造
String::String(const char *pstr)
{
	if(!pstr || !strlen(pstr))
	{
		_pstr=NULL;
	}
	else
	{	
		_pstr = new char[strlen(pstr)+1] ;
		strcpy(_pstr,pstr);
	}
}

//string构造
String::String(const String & rsh)
{
	if(!rsh._pstr){
		_pstr=NULL;
	}
	else
	{
		_pstr=new char[strlen(rsh._pstr)+1];
		strcpy(_pstr,rsh._pstr);
	}
}

//析构
String::~String()
{
	if(_pstr)
		delete[] _pstr;
}

//重载 =
String & String::operator=(const String & rhs)
{
	if(this==&rhs) return *this;
	
	if(_pstr)
		delete [] _pstr;
	_pstr= new char[strlen(rhs._pstr)+1];
	strcpy(_pstr,rhs._pstr);

	return *this;
}

String &  String::operator=(const char *pstr)
{
	String st = String(pstr);
	return *this=st;
}

//重载 +=
String& String::operator+=(const String & rhs)
{
	if(rhs._pstr)
	{
		
		if(!_pstr)
		{
			*this=rhs;	
		}else
		{
			char*pt= new char [strlen(_pstr)+strlen(rhs._pstr)+1];
			sprintf(pt,"%s%s",_pstr,rhs._pstr);
			delete [] _pstr;
			_pstr=pt;
		}
	}
	return *this;
}

String & String::operator+=(const char *pstr)
{
	String rhs(pstr);
	return *this+=rhs;
}


//重载 []
char & String::operator[](std::size_t index)
{
	if(index >= strlen(_pstr))
	{
		cout << "invalid index " << endl;
		static char nullchar = '\0';
		return nullchar;
	}
	return *(_pstr+index); 
}
// const String 时调用
const char & String::operator[](std::size_t index) const
{
	if(index >= strlen(_pstr))
	{
		cout << "invalid index " << endl;
		static char nullchar = '\0';
		return nullchar;
	}
	return *(_pstr+index); 
}

//成员函数 size
std::size_t String::size() const
{
	if(!_pstr)
	{
		return 0;
	}else
	{
		return strlen(_pstr);
	}
}

//成员函数 c_str
const char* String::c_str() const
{
	if(!_pstr){
		cout << "# String is empty. #" << endl;
		static const char* nullstr = "";
		return nullstr;
	}
	return _pstr;
}

//重载 == !=
bool operator==(const String &lsh, const String &rsh)
{
	if(!lsh._pstr || !rsh._pstr)
	{
		cout << "# == :String cannot be empty. #" << endl;
		return false;
	}

	return 0==strcmp(lsh._pstr,rsh._pstr)?true:false;
}

bool operator!=(const String &lsh, const String &rsh)
{
	if(!lsh._pstr || !rsh._pstr)
	{
		cout << "# != :String cannot be empty. #" << endl;
		return false;
	}
	return 0!=strcmp(lsh._pstr,rsh._pstr)?true:false;
}

//重载 < <= > >=
bool operator<(const String &lsh, const String &rsh)
{
	if(!lsh._pstr || !rsh._pstr)
	{
		cout << "# < :String cannot be empty. #" << endl;
		return false;
	}
	return strcmp(lsh._pstr,rsh._pstr)<0 ?true:false;
}
bool operator>(const String &lsh, const String &rsh)
{
	if(!lsh._pstr || !rsh._pstr)
	{
		cout << "# > :String cannot be empty. #" << endl;
		return false;
	}
	return strcmp(lsh._pstr,rsh._pstr)>0 ?true:false;
}
bool operator<=(const String &lsh, const String &rsh)
{
	if(!lsh._pstr || !rsh._pstr)
	{
		cout << "# <= :String cannot be empty. #" << endl;
		return false;
	}
	return strcmp(lsh._pstr,rsh._pstr)<=0?true:false;
}
bool operator>=(const String &lsh, const String &rsh)
{
	if(!lsh._pstr || !rsh._pstr)
	{
		cout << "# >= :String cannot be empty. #" << endl;
		return false;
	}
	return strcmp(lsh._pstr,rsh._pstr)>=0 ?true:false;

}

//重载 << 
std::ostream &operator<<(std::ostream &os, const String &s)
{
	if(!s._pstr)
		os << "# << : String is empty.  #";
	else
		os << s._pstr;
	return os;
}

//重载 >> , 限定最大输入为 N=1024
std::istream &operator>>(std::istream &is, String &s)
{	
	static char temp[N] = "";

	
	cout << "Please input the String :";
	while(is.getline(temp,N,'\n'))
	{

		if(is.bad())
		{
			cout << "# istream is breaken !" << endl;
		}
		else if(is.fail())
		{
			is.clear();
			is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Please input the String :";
			continue;
		}
		break;
	}
	s=String(temp);
	return is;
}
//重载 +
String operator+(const String & lsh, const String & rsh)
{
	String temp(lsh);
	return temp+=rsh;
}
String operator+(const String & lsh, const char *pstr)
{
	String temp(lsh);
	return temp+=pstr;
}
String operator+(const char *pstr, const String &rsh)
{
	String temp(pstr);
	return temp+=rsh;
}

