 ///
 /// @file    query.h
 /// @date    2018-08-14 17:23:32
 ///
#ifndef  __QUERY_H__
#define  __QUERY_H__

#include "text_query.h"
#include <iostream>
#include <string>
using std::string;
using std::ostream;
using std::cout;
using std::endl;

class Query;

class Query_base
{
	friend class Query;
	protected:
		using line_no = TextQuery::line_no;
		virtual ~Query_base() = default;
	private:
		virtual QueryResult eval(const TextQuery&) const = 0;
		virtual string rep() const = 0;
};

class Query
{
		friend Query operator~(const Query &);
		friend Query operator&(const Query &,const Query &);
		friend Query operator|(const Query &,const Query &);
	public:
		Query(const string &); //构建wordquery
		//接口函数：调用对应的Query_base操作
		QueryResult eval(const TextQuery &t) const
		{	return _q->eval(t);}
		string rep() const
		{	return _q->rep();}
	private:
		Query(shared_ptr<Query_base> query)
			:_q(query){}
		shared_ptr<Query_base> _q;
};


//------------------------------
class WordQuery
:public Query_base
{
	friend class Query;  //Query使用WordQuery的构造函数
	WordQuery(const string &s):_query_word(s){}
	//wordquery实现接口
	QueryResult eval(const TextQuery &t) const
	 {
		return t.query(_query_word);
	 }
	string rep() const
	{
		return _query_word;	
	}
	string _query_word;
};

//----------------------------------------------------------

class NotQuery
:public Query_base
{
	friend Query operator~(const Query&);
	NotQuery(const Query &q)
		:_query(q){}
	//实现接口
	QueryResult eval(const TextQuery &) const;
	string rep() const
	{
		return "~(" + _query.rep() + ")";
	}
	Query _query;
};

//----------------------------------------------------------
class BinaryQuery
:public Query_base
{
	protected:
		BinaryQuery(const Query &l,const Query &r,string s)
			:_lhs(l),_rhs(r),_opSym(s){}
		//只实现rep()
		string rep() const
		{
			return "(" + _lhs.rep() +
				   " " + _opSym +
				   " " + _rhs.rep() +
				   ")";
		}

		Query _lhs,_rhs;
		string _opSym;
};

//----------------------------------------------------------
class AndQuery
:public BinaryQuery
{
	friend Query operator&(const Query &,const Query &);
	AndQuery(const Query &l,const Query &r)
		:BinaryQuery(l,r,"&"){}
	//实现eval接口
	QueryResult eval(const TextQuery &t) const;
};

//----------------------------------------------------------
class OrQuery
:public BinaryQuery
{
	friend Query operator|(const Query&,const Query&);
	OrQuery(const Query &l,const Query &r)
		:BinaryQuery(l,r,"|"){}
	//实现eval接口
	QueryResult eval(const TextQuery &t) const;
};

//Query的输出符
inline ostream& operator<<(ostream &os,Query &q)
{
	os << q.rep();
	return os;
}

//创建WordQuery对象
inline  
Query::Query(const string &query_word)
			:_q(new WordQuery(query_word)){}

//
inline 
Query operator~(const Query &operand)
{
	return shared_ptr<Query_base>(new NotQuery(operand));
}

inline
Query operator&(const Query &lhs,const Query &rhs)
{
	return shared_ptr<Query_base>(new AndQuery(lhs,rhs));
}

inline
Query operator|(const Query &lhs,const Query &rhs)
{
	return shared_ptr<Query_base>(new OrQuery(lhs,rhs));
}

#endif
