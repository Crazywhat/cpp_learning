 ///
 /// @file    main.cc
 /// @date    2018-08-07 08:13:49
 ///
#include <iterator>
#include <vector> 
#include <iostream>
#include <algorithm>
using std::cout;
using std::endl;
using std::ostream_iterator;
using std::vector;
using std::remove;
using std::copy;
using std::unique;
using std::sort;

void test0()
{
	vector<int> v_int{0,99,88,7,66,77,5,55,44,44,77,55};

//	auto it = remove(v_int.begin(),v_int.end(),44);
//	v_int.erase(it,v_int.end());
// 上面两句的惯用手法
	v_int.erase(remove(v_int.begin(),v_int.end(),44),v_int.end());
	copy(v_int.begin(),v_int.end(),ostream_iterator<int>(cout," | "));
	cout << endl;
}

void test1()
{
	vector<int> v_int{0,99,88,7,66,77,5,55,44,44,77,55};

	//unique只能去除相邻重复的	
	sort(v_int.begin(),v_int.end());	
	v_int.erase(unique(v_int.begin(),v_int.end()),v_int.end());
	copy(v_int.begin(),v_int.end(),ostream_iterator<int>(cout," | "));
	cout << endl;
}

void test2()
{
	vector<int> v_int{0,99,88,7,66,77,5,55,44,44,77,55};

	std::greater<int> grt;
	v_int.erase(remove_if(v_int.begin(),v_int.end(),bind1st(grt,10)),v_int.end());
	copy(v_int.begin(),v_int.end(),ostream_iterator<int>(cout," | "));
	cout << endl;
}

int main()
{
//	test0();
//	test1();
	test2();
	return 0;
}
