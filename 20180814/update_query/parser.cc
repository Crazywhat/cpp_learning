 ///
 /// @file    parser.cc
 /// @date    2018-08-16 12:52:48
 ///
#include "parser.h"
#include <cctype>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

int Parser::priority(char oper)
{
	switch(oper)
	{
		case '#': return -1; break;
		case '|': return  0; break;
		case '&': return  1; break;
		case '~': return  2; break;
		case '(': return  3; break;
	}
	return -1;
}

bool Parser::is_operator(char oper)
{
	string operators = "|#&~";
	return string::npos  == operators.find(oper) ? false:true;
}

void Parser::operation(char oper)
{
	if('~' == oper )
	{
		Query _q = _querys.top();
		_querys.pop();
		_querys.push(~_q);
	}else if('&' == oper)
	{
		Query _q0 = _querys.top();
		_querys.pop();
		Query _q1 = _querys.top();
		_querys.pop();
		_querys.push(_q1 & _q0);
	}else if('|' == oper)
	{
		Query _q0 = _querys.top();
		_querys.pop();
		Query _q1 = _querys.top();
		_querys.pop();
		_querys.push(_q1 | _q0);
	}
}

Query Parser::get_query(){
	char* p_query = _input.get();

	cout << p_query << endl;

	_opers.push('#');

	while(*p_query)
	{	
	
		if(isalpha(*p_query))
		{
			string query_world;
			while(isalpha(*p_query))
			{
				query_world+=*p_query;
				++p_query;
			}
			_querys.push(Query(query_world));
			//cout << "world push:" << query_world << endl;
		}
		else{ 
			if(')'== *p_query)
				{
				while(_opers.top() != '(')
				{
					operation(_opers.top());
					_opers.pop();
				}
				_opers.pop();
			}
			else if(is_operator(*p_query))
			{
				while(priority(_opers.top()) > priority(*p_query))
				{
					operation(_opers.top());
					_opers.pop();
				}
				_opers.push(*p_query);
			//	cout << "_pers.push " << *p_query << endl;
			}
			++p_query;
		}

	}

	while(_opers.top()!='#')
	{
		operation(_opers.top());
		_opers.pop();
	}

	return _querys.top();
}
