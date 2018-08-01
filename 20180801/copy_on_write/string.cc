///
/// @file    String.cc
/// @date    2018-08-01 16:36:51
///
#include "string.h"

#include <cstring>
#include <iostream>
using std::cout;
using std::endl;

//String
String::String()
	:_pstr(new char[5]()+4)
{
	set_quote();
}
String::String(String& rhs)
{
	_pstr=rhs._pstr;
	incre_quote();
}
String::String(const char*pstr)
	:_pstr(new char[strlen(pstr)+5]()+4)
{
	set_quote();
	strcpy(_pstr,pstr);
}
String::~String()
{
	release();
}
const char* String::c_str()
{
	return _pstr;
}
String &String::operator=(const String &rhs)
{
	if(this!=&rhs){
		release();
		_pstr=rhs._pstr;
		incre_quote();
	}
	return *this;
}
String & String::operator=(const char*pstr)
{	
	String temp(pstr);
	return (*this)=temp;
}
String::Oper_bracket String::operator[](size_t index)
{
	Oper_bracket temp(*this,index);
	return temp;
}
ostream & operator << (ostream &os,String &rhs)
{
	if(0==strlen(rhs._pstr))
	{
		cout << "The String is empty." << endl;
	}else{
		os  << rhs._pstr;
	}
	return os;
}

void String::set_quote()
{
	*((int*)(_pstr-4))=1;
}
void String::incre_quote()
{
	++(*((int*)(_pstr-4)));
}
void String::decr_quote()
{
	--(*((int*)(_pstr-4)));
}
int String::get_quote()
{
	return *((int*)(_pstr-4));  
}
void String::release()
{
	decr_quote();
	if(get_quote()==0)
		delete [] (_pstr-4);
}

//oper_bracket
String::Oper_bracket::Oper_bracket(String &str,size_t index)
	:_str(str)
	 ,_index(index)
{

}
ostream & operator << (ostream &os,String::Oper_bracket q)
{
	if(q._index < strlen(q._str.c_str()))
	{
		const char *pt = q._str.c_str()+q._index;
		os << *pt;
	}else
	{
		cout << "Invalid index." << endl;
	}
	return os;
}
char  String::Oper_bracket::operator=(const char ch)
{
		if(this->_index < strlen(this->_str._pstr))
		{
			String stemp(this->_str._pstr);
			this->_str.release();
			this->_str._pstr=stemp._pstr;
			this->_str.incre_quote();
			*(this->_str._pstr+_index)=ch;

			return ch;
		}else
		{
			cout << "Invalid Index ." << endl;
			static char nullchar ='\0';
			return nullchar;
		}
}

String::Oper_bracket::operator char()
{
		if(this->_index < strlen(this->_str._pstr))
		{
			char ch=*(this->_str._pstr+_index);
			return ch;
		}else
		{
			cout << "Invalid Index ." << endl;
			static char nullchar ='\0';
			return nullchar;
		}
	
}
