 ///
 /// @file    main.cc
 /// @date    2018-08-10 19:13:15
 ///

#include <string>
#include <memory>
#include <iostream>
using std::cout;
using std::endl;
using std::string;
using std::shared_ptr;
using std::weak_ptr;

int test0()
{
	weak_ptr<string> wps; //weak_ptr无法直接访问数据
						  //仅仅起托管作用
						  //同样无法用于初始化
						  //和shared_ptr配合使用
	{
		shared_ptr<string> sps(new string("hello wrold"));
		wps = sps; //托管
		
		cout << "weak_ptr use_cout : " << wps.use_count() << endl;
		
		shared_ptr<string> sps2 = wps.lock(); //将weak_ptr托管提升为shared_ptr
		if(sps2)
		{
			cout << "weak_ptr 提升为 shared_ptr 成功。" << endl;
			cout << "sps2 : " << *sps2 << endl;
		}else{
		
			cout << "weak_ptr 提升失败,托管对象已被销毁" << endl; 
		}
	}

	cout << "---------------out-of--block--------------------" << endl;
		shared_ptr<string> sps2 = wps.lock();
		if(sps2)
		{
			cout << "weak_ptr 提升为 shared_ptr 成功。" << endl;
			cout << "sps2 : " << *sps2 << endl;
		}else{
		
			cout << "weak_ptr 提升失败,托管对象已被销毁" << endl; 
		}


	return 0;
}

int main()
{
	test0();

	return 0;
}
