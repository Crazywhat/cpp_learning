///
/// @file    query.cc
/// @date    2018-08-10 11:23:49
///
#include "text_query.h" 
#include <iostream>
using std::cout;
using std::endl;

TextQuery::TextQuery(ifstream &ifs)
	:_file(new vector<string>)
{
	if(!ifs.is_open())
	{
		cout << "invail ifstream ." << endl;
		exit(-1);
	}
	char reads[4096]="";
	while(ifs.getline(reads,4096,'\n')){
		_file->push_back(string(reads));
		stringstream ss;
		ss << line_clean(reads);
		

		string word;
		while(ss >> word)
		{
			auto& line = _wm[word];
			if(!line)
			{
				line.reset(new set<size_t>);
			}
			line->insert((size_t)(_file->size()));
		}
	}
	cout << "load finished ." << endl;
}

char* TextQuery::line_clean(char* lstr)
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
	return lstr;
}


QueryResult TextQuery::query(const string& queryword) const
{
	static shared_ptr<set<size_t> > nodata(new set<size_t>);
	auto lines = _wm.find(queryword);
	if(lines == _wm.end())
		return QueryResult(queryword,_file,nodata);
	else
		return QueryResult(queryword,_file,lines->second);
}

ostream&  print(ostream &os,const QueryResult qr)
{
	os << "-----------------------------------------------------------------" << endl;
	os  << "[element occurs " <<  qr._lines->size() 
		<< (qr._lines->size() > 1?" times ] ":" time ]") << endl;
	for(auto num : *qr._lines)
	{
		os << "\t(line " << num  <<") "<< *(qr._file->begin() + num -1)<< endl;
	}
	os << "-----------------------------------------------------------------" << endl;

	return os;
}

