 ///
 /// @file    main.cc
 /// @date    2018-08-12 16:50:28
 ///
#include <memory> 
#include <iostream>
using std::cout;
using std::endl;
using std::shared_ptr;
using std::unique_ptr;

class Point
:public std::enable_shared_from_this<Point>
{
	public:
		Point(int x,int y)
			:_x(x)
			 ,_y(y)
		{
			cout << "Point()" << endl;	 
		}
		~Point()
		{
			cout << "-------------" << endl;
			print();
			cout << "~Point()" << endl;
			cout << "-------------" << endl;
			
		}
		void print()
		{
			cout <<" (" << _x
				<< "," << _y << ")"
				<<	endl;
		}

		/*//返回Point，仍会使多个智能绑定在一个对象
		Point* add(Point* rhs)
		{
			_x+=rhs->_x;
			_y+=rhs->_y;
			return this;
		}
		*/
	/*	//会产生临时的智能指针，提前将Point析构
		shared_ptr<Point> add(Point* rhs)
		{
			_x+=rhs->_x;
			_y+=rhs->_y;
			return shared_ptr<Point>(this);
		}
	*/
		//继承enable_shared_from_this类
		//return shared_from_this()确保同享智能指针
		shared_ptr<Point> add(Point* rhs)
		{
			_x+=rhs->_x;
			_y+=rhs->_y;
			return shared_from_this();
		}
		
		private:
		int _x,_y;
};

//误用一
//不可将一个对象绑在两个智能指针上
void test0()
{
	Point p(1,2);
	unique_ptr<Point> up(&p);
	unique_ptr<Point> up1(&p);
	
	up->print();
	up1->print();
}

//误用二
//shared_ptr 同样不可
void test1()
{
	Point p(1,2);
	shared_ptr<Point> up(&p);
	shared_ptr<Point> up1(&p);
	
	up->print();
	up1->print();
}

//误用三
void test2()
{
	shared_ptr<Point> sp0(new Point(12,21));
	shared_ptr<Point> sp1(new Point(3,4));

	sp1.reset(sp0.get()); //同样将两个智能
						  //指针绑到了一个对象上
}

void test3()
{
	shared_ptr<Point> sp0(new Point(12,21));
	shared_ptr<Point> sp1(new Point(3,4));

	shared_ptr<Point> sp2(sp0->add(sp0.get()));
}

int main()
{
	//test0();
	//test1();
	//test2();
	test3();
	return 0;
}
