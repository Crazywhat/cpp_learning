 ///
 /// @file    string.h
 /// @date    2018-08-01 15:38:51
 //

#include <iostream>
using std::ostream;

class String
{
public:
	//代理类
	//通过重载代理类的赋值号，和 << 实现读写分离
	//重载类型转化operator char()，可以赋值给其它char变量
	class Oper_bracket
	{
	public:
		Oper_bracket(String &,size_t index);
		//重载 = ，实现写
		char  operator=(const char);
		//重载char(),实现赋值给其它char变量
		operator char();
		//重载 << ，实现读
		friend ostream & operator << (ostream &os,String::Oper_bracket q);
	private:
		String &_str;
		size_t _index;
	};
	//构造函数
	String();
	String(String&);
	String(const char*);
	//析构函数
	~String();
	//重载 =
	String &operator=(const char*);
	String &operator=(const String &);
	//重载 []，返回一个代理类对象
	Oper_bracket operator[](size_t index);
	//获取_pstr地址
	const char* c_str();
	//重载 String <<
	friend ostream & operator << (ostream &os,String &rhs);
	//quote都是关于引用的相关操作
	int get_quote();
private:
	void set_quote();
	void incre_quote();
	void decr_quote();
	void release();
private:
	char* _pstr;
};

//String
ostream & operator >> (ostream &os,String &rhs);
//Oper_bracket
ostream & operator >> (ostream &os,String::Oper_bracket &q);
