 ///
 /// @file    query.cc
 /// @date    2018-08-14 17:44:33
 ///
 
#include "query.h"
#include <iostream>
#include <iterator>
#include <algorithm>
using std::cout;
using std::endl;
using std::set_intersection;
using std::inserter;

QueryResult AndQuery::eval(const TextQuery &t) const
{
	auto left = _lhs.eval(t),right = _rhs.eval(t);
	//用于存放两个set的并集
	shared_ptr<set<size_t>> ret_lines = std::make_shared<set<size_t>>();
	set_intersection(left.begin(),left.end()
					,right.begin(),right.end()
					,inserter(*ret_lines,ret_lines->begin()));
	return QueryResult(rep(),left.get_file(),ret_lines);
}

QueryResult OrQuery::eval(const TextQuery &t) const
{
	auto left = _lhs.eval(t),right = _rhs.eval(t);
	//用于存放两个set的并集
	shared_ptr<set<size_t>>
	ret_lines = std::make_shared<set<size_t>>(left.begin(),left.end());
	ret_lines->insert(right.begin(),right.end());	
	return QueryResult(rep(),left.get_file(),ret_lines);
}

QueryResult NotQuery::eval(const TextQuery &t) const
{
	auto result = _query.eval(t);
	shared_ptr<set<size_t>>
	ret_lines = std::make_shared<set<size_t>>();
	auto beg = result.begin(),end = result.end();
	auto sz = result.get_file()->size();
	for(size_t n = 0; n != sz ; ++n)
	{
		if(beg == end || *beg != n)
			ret_lines->insert(n);
		else if(beg != end)
			++beg;
	}
	return  QueryResult(rep(),result.get_file(),ret_lines);
}

