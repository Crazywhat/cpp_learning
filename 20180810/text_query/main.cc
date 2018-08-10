 ///
 /// @file    main.cc
 /// @date    2018-08-10 12:54:20
 ///

#include "query.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;


void runQuery()
{

	ifstream ifs("1.txt");
	TextQuery tq(ifs); 

	string queryword; 
	while(1)
	{
		cout << "enter word to look for, or q to quit: ";
		cin >> queryword;
		if(queryword == "q")
			return;
		print(cout,tq.query(queryword));
	}

}

int main()
{

	runQuery();
	return 0;
}
