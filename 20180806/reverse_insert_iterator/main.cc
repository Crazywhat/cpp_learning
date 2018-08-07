 ///
 /// @file    main.cc
 /// @date    2018-08-06 21:46:45
 ///
 
#include <set>
#include <list>
#include <vector>
#include <forward_list>
#include <iterator>
#include <iostream>
#include <algorithm>
using std::set;
using std::cout;
using std::endl;
using std::copy;
using std::list;
using std::vector;
using std::forward_list;
using std::reverse_iterator;
using std::ostream_iterator;
using std::insert_iterator;
using std::back_insert_iterator;
using std::front_insert_iterator;


//reverse_iterator
int test0()
{
	vector<int> v_int{1,2,3,4,5,6,7,8};
	reverse_iterator<vector<int>::iterator> ri_int = v_int.rbegin();
	for(;ri_int != v_int.rend(); ++ri_int)
	{
		cout << (*ri_int) << " | "; 
	}
	cout << endl;
	return 0;
}

int test1()
{
	vector<int> v_int{1,2,3,4,5,6,7,8};
	list<int> l_int;
	//back_insert_iterator 适合有push_back操作的容器
	copy(v_int.rbegin(),v_int.rend(),back_insert_iterator<list<int> >(l_int));
	copy(l_int.begin(),l_int.end(),ostream_iterator<int>(cout," | "));	
	cout << endl ;
	return 0;
}

int test2()
{
	vector<int> v_int{1,2,3,4,5,6,7,8};
	forward_list<int> fl_int;
	//front_insert_iterator 适合有push_front操作的容器
	copy(v_int.rbegin(),v_int.rend(),front_insert_iterator<forward_list<int> >(fl_int));
	copy(fl_int.begin(),fl_int.end(),ostream_iterator<int>(cout," | "));	
	cout << endl ;
	return 0;
}

int test3()
{
	vector<int> v_int{1,8,3,4,6,5,7,2};
	set<int> s_int;
	//insert_iterator 适合所有insert插入操作的容器
	copy(v_int.rbegin(),v_int.rend(),insert_iterator<set<int> >(s_int,s_int.begin()));
	copy(s_int.begin(),s_int.end(),ostream_iterator<int>(cout," | "));	
	cout << endl ;
	return 0;
}
int test4()
{
	vector<int> v_int{1,8,3,4,6,5,7,2};
	list<int> l_int{999,888};
	copy(v_int.rbegin(),v_int.rend(),insert_iterator<list<int> >(l_int,++(l_int.begin())));
	copy(l_int.begin(),l_int.end(),ostream_iterator<int>(cout," | "));	
	cout << endl ;
	return 0;
}

#if 0
int test5()
{
	vector<int> v_int{1,2,3,4,5,6,7,8};
	vector<int> test_v_int;
	//front_insert_iterator 适合有push_front操作的容器
	//vector 没有push_front操作，编译出错
	copy(v_int.rbegin(),v_int.rend(),front_insert_iterator<vector<int> >(test_v_int));
	copy(test_v_int.begin(),test_v_int.end(),ostream_iterator<int>(cout," | "));	
	cout << endl ;
	return 0;
}
#endif
int main()
{
	
	//test0();
	//test1();
	//test2();
	//test3();
	test4();
	//test5();

	return 0;
}

