 ///
 /// @file    main.cc
 
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using std::sort;
using std::vector;
using std::string;
using std::cout;
using std::endl;

int main(void)
{
	vector<string> v1;
	string ss[5]={"book","good","fun","f*k","apple"};

	for(auto &idx : ss)
		v1.push_back(idx);

	sort(v1.begin(),v1.end());

	cout << v1.at(0) << endl;

	for(auto &idx : v1)
		cout << idx << endl;

	return 0;
}
