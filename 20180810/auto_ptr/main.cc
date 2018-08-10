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
using std::auto_ptr;

int main()
{


	auto_ptr<vector<string> > pvs(new vector<string>);

	pvs->push_back("good morning.");

	cout << (*pvs)[0] << endl;

	auto_ptr<vector<string> > pvs1 = pvs; //进行赋值
										  //底层所有权转移了
										  //auto_ptr存在缺陷

	cout << "pvs1 :" << (*pvs1)[0] << endl;
	cout << "pvs  :" << (*pvs)[0]  << endl; //转移后，访问直接崩溃

	return 0;
}
