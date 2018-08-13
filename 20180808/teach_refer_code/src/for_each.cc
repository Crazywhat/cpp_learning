 ///
 /// @file    for_each.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-08-08 10:17:19
 ///
 
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::for_each;

void display(int num)
{
	cout << num << " ";
}

struct Displayer
{
	void operator()(int num) {
		cout << num << " ";
	}
};
 
int test0(void)
{
	vector<int> numbers{1, 2, 3, 4, 5, 6};
	int a = 10;

	for_each(numbers.begin(), numbers.end(), display);
	cout << endl;
	for_each(numbers.begin(), numbers.end(), Displayer());
	cout << endl;
	//lambda表达式 ==> 函数闭包 ==> 匿名函数
	for_each(numbers.begin(), numbers.end(), [&a](int num){
		cout << "a = " << a << endl;
		cout << num << " ";		
	});
	cout << endl;

	return 0;
}

void test1(void)
{
	//string是可以看出一个容器的  vector<char>
	string s1 = "hello,world,hello,shenzhen";
	string s2 = "world";

	//查找子串
	auto it = std::search(s1.begin(), s1.end(), s2.begin(), s2.end());
	for(; it != s1.end(); ++it)
	{
		cout << *it;
	}
	cout << endl;

}

int main(void)
{
	test1();
	return 0;
}
