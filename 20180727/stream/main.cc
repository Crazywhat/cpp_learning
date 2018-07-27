 ///
 /// @file    main.c
 //
 //
#include <strings.h> 

#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::endl;

using std::ifstream;

using std::string;

void test_read(){

	ifstream ifs("1.txt",std::ios::ate);
	if(!ifs)
	{
		cout << "open ifs error " << endl;
		return ;
	}
	size_t len=ifs.tellg();
		cout << "len :" << len << endl;
	
	ifs.seekg(std::ios_base::beg);

	char fstr[len+1];
	bzero(fstr,sizeof(fstr));

	ifs.read(fstr,len+1);

	cout << fstr << endl;

	ifs.close();
}

int main()
{

	test_read();

	return 0;
}
