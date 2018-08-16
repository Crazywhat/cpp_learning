 ///
 /// @file    main.cc
 /// @date    2018-08-10 12:54:20
 ///

#include "query.h"
#include "text_query.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void runQuery()
{
	ifstream ifs("1.txt");
	TextQuery tq(ifs);

	Query q =  Query("fiery") & Query("bird") | Query("wind");
	
	cout << "Executing Query for:";
	cout << q.rep() << endl;
	print(cout,q.eval(tq));
}


int main()
{
	runQuery();
	return 0;
}
