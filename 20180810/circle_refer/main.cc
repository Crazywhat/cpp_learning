 ///
 /// @file    main.cc
 /// @date    2018-08-10 16:04:16
 ///
 
#include <memory>
#include <iostream>
using std::cout;
using std::endl;
using std::shared_ptr;

class Child;

class Parent
{
	public:
		//shared_ptr 循环引用，会导致内存泄漏
		Parent(){cout << "Parent()" << endl; }
		~Parent(){cout << "~Parent()" << endl;}
		shared_ptr<Child> _pChild;
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
	p->_pChild=c;
	c->_pParent=p;

	return 0;
}
