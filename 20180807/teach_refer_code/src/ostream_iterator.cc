 ///
 /// @file    ostream_iterator.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-08-07 11:25:15
 ///
 
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;
using std::copy;
using std::ostream_iterator;
 
int main(void)
{
	vector<int> numbers{1, 2, 3, 4, 5};
	for(auto & elem : numbers) 
	{
		cout << elem << endl;
	}
	//把输出流看成一个容器
	//同样是进行元素的输出，使用输出流迭代器就是换一种方式去达到相同的目标
	//
	//ostream_iterator本身是一个类模板， 我们希望它的操作类似于一个迭代器
	//这个迭代器还是一个输出迭代器, 要重载相应的运算符
	//
	//ostream_iterator是一个设计模式的应用：适配器
	//
	ostream_iterator<int> osi(cout, "\n");
	copy(numbers.begin(), numbers.end(), osi);
	
	return 0;
}
