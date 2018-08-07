 ///
 /// @file    main.cc
 /// @date    2018-08-06 23:36:14
 /// 
#include <vector>
#include <iostream>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;
using std::for_each;


//for_each , 通过传入的函数对象对每个迭代器操作

//函数对象
//1.普通函数
//2.函数指针
//3.重载了operator()

void display(int num)
{
	cout << num << " | ";
}

int test0()
{
	vector<int> v_int{1,2,3,4,5,6,7,8,9,0};

	for_each(v_int.begin(),v_int.end(),display);

	cout << endl;
	return 0;
}
int test1()
{
	vector<int> v_int{1,2,3,4,5,6,7,8,9,0};

	for_each(v_int.begin(),v_int.end(),[](int& num){num*=2;});
	
	for(auto &elem : v_int)
		cout << elem << " | ";
	cout << endl;
	return 0;
}


int main()
{
	//test0();
	test1();
	return 0;
}
