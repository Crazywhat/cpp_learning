 ///
 /// @file    main.cc
 /// @date    2018-08-07 09:26:36
 ///

#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
using std::copy;
using std::cout;
using std::endl;
using std::vector;
using std::replace;
using std::replace_if;

//replace
void test0()
{
	vector<int> v_int{1,2,3,4,5,6,7,8,9};

	replace(v_int.begin(),v_int.end(),6,666);
	replace(v_int.begin(),v_int.end(),8,888);

	copy(v_int.begin(),v_int.end(),std::ostream_iterator<int>(cout," | "));
	
	cout << endl;
}
//replace_if
void test1()
{
	vector<int> v_int{1,2,3,4,5,6,7,8,9};
	
	std::less_equal<int> les_eq;
	replace_if(v_int.begin(),v_int.end(),bind1st(les_eq,5),666);

	copy(v_int.begin(),v_int.end(),std::ostream_iterator<int>(cout," | "));
	
	cout << endl;
}
int main()
{
	//test0();
	test1();
	return 0;
}
