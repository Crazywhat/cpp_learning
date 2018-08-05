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

int main(int argc,char* argv[])
{
	regex reg0(".*?<.*?");
	regex reg1("(<[a-z]{1,10}[0-9]{0,1}.*?>)(.*?)(</[a-z]{1,10}[0-9]{0,1}>)");
	
	string ts(argv[1]);
	string s_all;

	cout << "ts:" << ts << endl;
	if(regex_match(ts,reg0))
		s_all+=regex_replace(ts,reg1,"$2");
	cout << s_all << endl;

	return 0;
}
