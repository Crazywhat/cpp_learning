/// @file    words_req.h
/// @date    2018-08-04 16:08:11

#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#define N 1024
using std::map;
using std::set;
using std::string;
using std::vector;

class TextQuery
{
	public:
		void readFile(const string filename);//将文件按行读入line
		void query(const string & word);//查询单词
	private:
		void line_clean(char*);//清理每行中的无关字符
		void put_word_in_dict(string&,int);//将每个单词存入_dict,_word2Line
	private:
		vector<string> _lines;
		map<string, set<int>> _word2Line;
		map<string, int> _dict;
};
