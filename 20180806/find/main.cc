 ///
 /// @file    main.cc
 /// @date    2018-08-07 09:06:49
 ///

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::find;
using std::find_if;

void test0()
{
	vector<string> v_s{"good","hello","fine","bye"};
	
	auto the_find = find(v_s.begin(),v_s.end(),"bye");
	auto the_find1 = find(v_s.begin(),v_s.end(),"cat");
	if(the_find != v_s.end()){
		cout << "find it , " << *the_find << endl;
	}else{
		cout << "cannot find it ." << endl;
	}
	if(the_find1 != v_s.end()){
		cout << "find it , " << *the_find << endl;
	}else{
		cout << "cannot find it ." << endl;
	}

}
void test1()
{
	vector<string> v_s{"good","hello","fine","bye"};
	
	std::greater<string> grt;
	std::less<string> les;
	//find_if 返回第一个符合条件的
	//auto the_find = find_if(v_s.begin(),v_s.end(),bind1st(grt,"cat"));
	auto the_find = find_if(v_s.begin(),v_s.end(),bind1st(les,"cat"));
	if(the_find != v_s.end()){
		cout << "find it , " << *the_find << " . \n";
	}else{
		cout << "cannot find it ." << endl;
	}


}

int main()
{
	//test0();
	test1();
	return 0;
}
