 ///
 /// @file    main.cc
 /// @date    2018-08-06 20:39:48
 ///
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <iostream>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ostream_iterator;

int main(){

	vector<int> v_int{1,2,3,4,5,6,7,8};
	ostream_iterator<int> oit_int(cout," | ");

	std::copy(v_int.begin(),v_int.end(),oit_int);

	ostream_iterator<string> oit_string(cout);
	
	*oit_string++=string("\n------------------------------------------\n");
	
	*oit_int++=999;

	return 0;
}
