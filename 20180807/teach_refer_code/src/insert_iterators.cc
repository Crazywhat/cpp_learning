 ///
 /// @file    insert_iterators.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-08-07 15:58:13
 ///
 
#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;
using std::list;
using std::copy;
using std::ostream_iterator;
using std::back_insert_iterator;
using std::front_insert_iterator;
using std::insert_iterator;

 
int main(void)
{
	vector<int> vec{1, 2, 3};
	list<int> li{4, 5, 6};

	//在尾部添加元素的迭代器，内部会调用 push_back方法， 使用的容器有vector, deque, list
	copy(vec.begin(), vec.end(), back_insert_iterator<list<int>>(li));//
	copy(li.begin(), li.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	//在头部添加元素的迭代器，内部会调用 push_front方法， 使用的容器有deque, list
	copy(vec.begin(), vec.end(), front_insert_iterator<list<int>>(li));
	copy(li.begin(), li.end(), ostream_iterator<int>(cout, " "));
	cout << endl;


	//在任意位置添加元素的迭代器，内部会调用insert方法，基本上所有的容器都适用
	//但是vector,deque不推荐使用
	auto lit = li.begin(); ++lit; ++lit;
	copy(vec.begin(), vec.end(), insert_iterator<list<int>>(li, lit));
	copy(li.begin(), li.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	return 0;
}
