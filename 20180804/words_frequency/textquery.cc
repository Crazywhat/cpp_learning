///
/// @file    textquery.cc
/// @date    2018-08-04 16:27:28
///
#include "textquery.h" 
#include <cctype>
#include <iostream>
#include <fstream>
#include <sstream>
using std::cout;
using std::endl;
using std::stringstream;
using std::ifstream;

void TextQuery::readFile(const string filename)
{
	ifstream ifs(filename);
	if(!ifs.is_open())
	{
		cout << "File load failed." << endl;
		return;
	}
	char lstr[N]="";
	int line_id = 1;
	while(ifs.getline(lstr,N,'\n'))
	{
		_lines.push_back(lstr);
		line_clean(lstr);
		string linestr=lstr;
		put_word_in_dict(linestr,line_id++);
	}
	ifs.close();
}

void TextQuery::line_clean(char* lstr)
{
	char*pt = lstr;
	while(*pt)
	{
		if((0==isspace(*pt))&&(0==islower(*pt))){
			if(isupper(*pt))
			{
				*pt+=32;
			}else
			{
				*pt=' ';
			}
		}
		++pt;
	}
}

void TextQuery::put_word_in_dict(string& ls,int line_id)
{
	stringstream ss;
	ss << ls;
	string word;
	while(ss>>word)
	{
		cout << word << endl;
		if(_dict.count(word))
		{
			++(_dict[word]);
			set<int>& ws = _word2Line[word];
			ws.insert(line_id);
		}else
		{
			_dict.insert(std::pair<string,int>(word,1));
			set<int> ws;
			ws.insert(line_id);
			_word2Line.insert(std::pair<string,set<int>>(word,ws));
		}
	}

}

void TextQuery::query(const string & word)
{
	cout <<  "----------------------------------------------------" << endl;
	if(_dict.count(word))
	{
		cout << "element occurs " << _dict[word] << " times."<< endl;
		set<int> &ws=_word2Line[word];
		for(auto idex: ws)
		{
			cout << "\t(line " << idex << "):" << _lines.at(idex-1) << endl;
		}
	}else
	{
		cout << "This word does not exist." << endl;
	}
	cout <<  "----------------------------------------------------" << endl;
}
