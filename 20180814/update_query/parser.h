 ///
 /// @file    parser.h
 /// @date    2018-08-16 12:53:54
 ///
#ifndef __PARSER_H__
#define __PARSER_H__

#include "query.h"
#include <cstring>
#include <stack>
#include <iostream>
#include <string>
#include <memory>
using std::cout;
using std::endl;
using std::stack;
using std::string;
using std::unique_ptr;

class Parser
{
public:
	Parser(string & q)
		:_input(new char[q.size()+1]){
			strcpy(_input.get(),q.c_str());
		}
	Query get_query();
private:
	int priority(char);  //获取符号的优先级
	void operation(char);//根据相应操作符进行操作
	bool is_operator(char);//判断是否为支持的操作符
private:
	stack<char> _opers;
	stack<Query> _querys;
	unique_ptr<char> _input;
};

#endif
