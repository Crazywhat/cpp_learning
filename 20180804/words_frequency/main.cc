 ///
 /// @file    main.cc
 /// @date    2018-08-04 17:26:02
 ///
 
#include "textquery.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main(int argc , char* argv[])
{
	TextQuery tq;
	tq.readFile(argv[1]);

	string query_word;
	while(cin >> query_word)
	{
		tq.query(query_word);
	}
	return 0;
}
