 ///
 /// @file    query.h
 /// @date    2018-08-10 10:42:16
 ///

#ifndef __TEXT_QUERY__
#define __TEXT_QUERY__

#include <cstdlib>
#include <set>
#include <map>
#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>
#include <memory>
#include <string>
using std::cout;
using std::endl;
using std::set;
using std::map;
using std::vector;
using std::string;
using std::ostream;
using std::stringstream;
using std::ifstream;
using std::shared_ptr;

class QueryResult;

class TextQuery
{
	public:
		 using line_no = size_t;
		 TextQuery(ifstream &ifs);
		 QueryResult query(const string&) const;
	private:
		 char* line_clean(char* lstr);
	private:
		shared_ptr<vector<string> > _file;
		map<string,shared_ptr<set<size_t> > > _wm; 
};

class QueryResult
{
	public:
		QueryResult(string queryWord
			,shared_ptr< vector<string> > file
			,shared_ptr<set<size_t> > lines)
			:_queryWord(queryWord)
			 ,_file(file)
			 ,_lines(lines)
		{
		}
		QueryResult(string&& queryWord
			,shared_ptr<vector<string>>&&file
			,shared_ptr<set<size_t>>&&lines)
			:_queryWord(queryWord)
			 ,_file(file)
			 ,_lines(lines)
		{
		}
		friend ostream&  print(ostream &os,QueryResult qr);
		set<size_t>::iterator begin() const
		{
			return _lines->begin();
		}
		set<size_t>::iterator end() const
		{
			return _lines->end();
		}
		shared_ptr<vector<string>>& get_file()
		{
			return _file;
		}
	private:
		string _queryWord;
		shared_ptr<vector<string> > _file;
		shared_ptr<set<size_t> > _lines;
};

ostream&  print(ostream &os,const QueryResult qr);

#endif
