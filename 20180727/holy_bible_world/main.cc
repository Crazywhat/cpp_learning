#include <strings.h>
#include <ctype.h>

#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

using std::cout;
using std::endl;
using std::sort;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::stringstream;

class Dictionary
{
	public:
		//将文件读入字串中
		void read(const std::string & filename);
		//将统计结果写入文件中
		void store(const std::string & filename);
	private:
		//剔除无关字符，将大写字母改为小字母
		void except_other(char* all_text);
		//对单词进行排序
		void sort_worlds(char* all_text);
	private:
		//用来储存所有单词
		vector<string> _worlds;
};

void Dictionary::read(const std::string & filename)
{
	ifstream _ifs(filename, std::ios::ate);
	if(!_ifs)
	{
		cout << "_ifs open file error" << endl;
		return ;
	}
	
	size_t pos=_ifs.tellg();

	char entire_txt[pos+1];
	bzero(entire_txt,sizeof(entire_txt));

	_ifs.seekg(std::ios::beg);
	_ifs.read(entire_txt,pos);

	_ifs.close();

	except_other(entire_txt);
	sort_worlds(entire_txt);
}

void Dictionary::except_other(char* all_text)
{
	char *pt=all_text;
	while(*pt){
		if(islower(*pt)||(*pt))
		{
		
		}
		else if(isupper(*pt))
		{
			*pt+=32;
		}
		else
		{
			*pt = ' ';
		}
		++pt;
	}
}

void Dictionary::sort_worlds(char* all_text)
{

	cout << "sort begin " << endl;

	stringstream ss;
	ss << all_text;
	string ts;
	while(ss >> ts)
	{
		_worlds.push_back(ts);
	}
	//排序
	sort(_worlds.begin(),_worlds.end());
}

void Dictionary::store(const std::string & filename)
{
	ofstream ofs(filename);
	if(!ofs)
	{
		cout << "out_file open error " << endl;
		return ;
	}

	string prestr;
	int count = 1;

	prestr=_worlds.at(0);

	for(auto str : _worlds)
	{
		if(prestr == str)
		{
			++count;
		}
		else
		{
			ofs << prestr << "  " << count << endl;
			prestr=str;
			count =1;
		}
	}
	
	ofs.close();
}


int main(int argc, char* argv[])
{
	if(3!=argc)
	{
		cout << "args error " << endl;
		return -1;
	}
	
	//通过参数传入文件路径，转化为string
	string in_file=argv[1];
	string out_file=argv[2];

	Dictionary d;

	d.read(in_file);
	d.store(out_file);
	
	cout << "end" << endl ;

	return 0;
}
