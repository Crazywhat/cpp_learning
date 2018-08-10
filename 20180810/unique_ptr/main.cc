 ///
 /// @file    main.cc
 /// @date    2018-08-10 08:46:52
 ///
#include <memory> 
#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::unique_ptr;

int test0()
{

	unique_ptr<vector<string> > pvs(new vector<string>);
	pvs->push_back("good morning.");
	cout << (*pvs)[0] << endl;

	//unique_ptr(const unique_ptr&) = delete;
	//unique_ptr没有复制构造函数
	//unique_ptr<vector<string> > pvs1(pvs); //所以编译不通过
	
	unique_ptr<vector<string> > pvs1(std::move(pvs)); //但unique_ptr支持移动语义
	
	return 0;
}

int test1()
{
	string *ss = new string("good"); 
	unique_ptr<string> ps(ss);

	cout << "p : " << ss << endl;
	//.get(),获得原生“裸”指针
	cout << "ps.get() : " << ps.get() << endl;


	vector<unique_ptr<string>> vps;

	//vps.push_back(ps); //无复制构造函数，操作不通过
	vps.push_back(std::move(ps)); //支持移动语义

	cout << *(vps[0]) << endl;

	//底层控制权已转移，报错
	//cout << "push back after, ps : " << *ps << endl;
	
	//重置
	ps.reset(new string("new one"));
	cout << "reset after, ps : " << *ps << endl;

	return 0;
}

int main()
{
	test0();
	test1();
	return 0;
}
