#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

//一般来说，如果类中定义了虚函数
//析构函数也应被定义为虚析构函数
//尤其是类内有申请的动态内存的时候
class abClass
{
	public:
		virtual void display() = 0;
		//~abClass(){ cout << "~abClass()" << endl; }
		virtual ~abClass(){ cout << "~abClass()" << endl; }
};

class subClass:public abClass
{
	public:
		subClass(const char* pstr)
			:_ps(new string(pstr)){}
		~subClass()
		{
			if(_ps)
				delete _ps;
			cout << "~subClass()" << endl;
		}
		void display(){ cout <<  *_ps << endl; }
	private:
		string *_ps;
};


//抽象类析构函数为非virtual时
//delete ab不会去调用subClass的析构函数
//会导致内存泄漏
void test0()
{
	abClass* ab = new subClass("Machine.");
	ab->display();
	delete ab;
}

//将抽象类的析构函数设置virtual后
//subClass对象可正常析构
//分配的内存能正常释放
void test1()
{
	abClass* ab = new subClass("Machine.");
	ab->display();
	delete ab;
}
int main()
{
	//test0();
	test1();
	return 0;
}
