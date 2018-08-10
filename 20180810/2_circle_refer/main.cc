 ///
 /// @file    main.cc
 /// @date    2018-08-10 16:04:16
 ///
 
#include <memory>
#include <iostream>
using std::cout;
using std::endl;
using std::shared_ptr;
using std::weak_ptr;

class Child;

class Parent
{
	public:
		//shared_ptr 循环引用，会导致内存泄漏
		Parent(){cout << "Parent()" << endl; }
		~Parent(){cout << "~Parent()" << endl;}
		weak_ptr<Child> _pChild; //weak_ptr能解决shared_ptr循环引用的问题
								 //weak_ptr只能知道对象是否存在
								 //不能直接访问
};

class Child
{
	public:
		Child(){cout << "Child()" << endl; }
		~Child(){cout << "~Chilid()" << endl; }
		shared_ptr<Parent> _pParent;
};

int main()
{
	shared_ptr<Parent> p(new Parent);
	shared_ptr<Child> c(new Child);
	p->_pChild=c; //弱化的引用智能指针
				  //复制或者赋值不会导致引用计数加1
	c->_pParent=p;


	cout << "p's use_count :" << p.use_count() << endl;
	cout << "c's use_count :" << c.use_count() << endl;

	return 0;
}
