 ///
 /// @file    main.cc
 /// @date    2018-08-11 18:29:54
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//第一类抽象类
class abClass
{
	public:
		//抽象类定义接口，由派生类来实现 
		virtual void display()=0;
		
};

//抽象类的派生类，若未实现接口
//则该派生类也是抽象类
class subClass:public abClass
{
	public:
		void display(){ cout << "display in subClass" << endl; }
};


void test0()
{
	//abClass ab; //error 抽象类无法初始化
	//abClass *pab = new abClass; //error 同样不允许
	abClass *pab1 = NULL;//ok
	abClass *pab2 = new subClass;//ok
	pab2->display();
}
//-----------------------------------------------------------------------

//第二类抽象类
//只定义了protected型的构造函数
//除派生类中，无法创建对象
class abClass2
{
	public:
		void display(){cout << "abClass2 _x = " << _x << endl;}
	protected:
		abClass2(int x)
			:_x(x)
		{
		
		}
	private:
		int _x;
};

class subclass2:public abClass2
{
	public:
		subclass2(int x)
			:abClass2(x)
		{
		}
};
void test1()
{
	//abClass2 ab; //无法构建对象
	abClass2 *pab = new subclass2(9);//ok
	pab->display();

	subclass2 sc2(12);
	sc2.display();
}
//-----------------------------------------------------------------------
//同样可以将构造函数设置为private
//利用static函数进行调用构造函数
class privateConstruct
{
	private:
		privateConstruct(int x)
			:_data(x)
		{
		
		}
	private:
		int _data;
		static privateConstruct *p;
	public:
		void display(){ cout << "data :" << _data << endl;}
		static privateConstruct* getInstance(int x)
		{
			if(!p)
				return p = new privateConstruct(x);
		}
		static void destory()
		{
			if(p)
			{
				delete p;
				p = NULL;
			}
		}
};

privateConstruct* privateConstruct::p = NULL;
void test2()
{
	//privateConstruct pc; //私有构造函数无法访问
	privateConstruct *pc = NULL; //ok
	privateConstruct *pc1 = privateConstruct::getInstance(250);
	pc1->display();
	privateConstruct::destory();
}

//-------------------------------------------------------------------
int main()
{
	//test0();
	//test1();
	test2();
	return 0;
}
