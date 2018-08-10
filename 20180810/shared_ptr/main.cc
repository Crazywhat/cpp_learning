 ///
 /// @file    main.cc
 /// @date    2018-08-10 08:46:52
 ///
#include <memory> 
#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::shared_ptr;


int test1()
{
	shared_ptr<string> sp(new string("good"));	
	
	cout << "sp addr:" << sp.get() << endl;
	cout << "use count:" << sp.use_count() << endl;

	{
		shared_ptr<string> sp1(sp);
		cout << "sp addr:" << sp.get() << endl;
		cout << "sp1 addr:"<< sp1.get() << endl;
		cout << "use count:" << sp.use_count() << endl;
	}
		cout << "use count:" << sp.use_count() << endl;

	return 0;
}

int main()
{
	test1();
	return 0;
}
