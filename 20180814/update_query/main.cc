///
/// @file    main.cc
/// @date    2018-08-10 12:54:20
///

#include "query.h"
#include "parser.h"
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

void runQuery1()
{
	ifstream ifs("1.txt");
	TextQuery tq(ifs);

	string query_input;
	
	cout << "Please input your query ('q' to exit):" << endl; 

	while(getline(cin,query_input))
	{
		if(query_input == "q")
			return;

		Parser p(query_input);

		Query q = p.get_query();

		cout << "Executing Query for:";
		cout << q.rep() << endl;
		print(cout,q.eval(tq));
		cout << "Please input your query ('q' to exit):" << endl; 
	}
}

int main()
{
	runQuery1();
	return 0;
}
