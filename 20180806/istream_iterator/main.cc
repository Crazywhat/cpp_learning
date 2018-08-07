 ///
 /// @file    main.cc
 /// @date    2018-08-06 20:52:43
 ///

#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::istream_iterator;
using std::ostream_iterator;
int main()
{
//	istream_iterator<int> ini_int(cin);
	
	vector<int> v_int{1,2,3,4,9,5,6,7,8,9,0};
	
//	std::copy(ini_int,istream_iterator<int>(),ostream_iterator<int>(cout," | "));
	std::copy(istream_iterator<string>(cin),istream_iterator<string>(),ostream_iterator<string>(cout,"\n-------------------- \n"));

	return 0;
}
