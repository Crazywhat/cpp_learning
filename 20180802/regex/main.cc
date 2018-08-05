#include <iostream>
#include <fstream>
#include <boost/regex.hpp>
#include <string>
using std::string;
using std::cout;
using std::endl;
using std::wstring;
using std::ifstream;
using namespace boost;


void cleanLine(string &ts)
{	
	regex reg0(".*?<.*?</[a-z]{1,10}[0-9]{0,1}>");
	regex reg1("(<[a-z]{1,10}[0-9]{0,1}.*?>)(.*?)(</[a-z]{1,10}[0-9]{0,1}>)");
	regex reg2("<img.*");
	if(regex_match(ts,reg0)){
		while(regex_match(ts,reg0))
		{
			ts=regex_replace(ts,reg1,"$2");
			if(regex_match(ts,reg2))
			{
				ts="";
				break;
			}
		}
	}else
	{
		ts="";
	}
}



int main(void)
{
	
	char s[1024]="";
	string s_all;
	ifstream ifs("1.txt");
	while(ifs.getline(s,1024,'\n'))
	{
		string ts(s);
		cleanLine(ts);
		cout <<"ts:" << ts << endl;
		s_all+=ts+"\n";
	}
	cout << s_all << endl;

	ifs.close();
	return 0;
}
