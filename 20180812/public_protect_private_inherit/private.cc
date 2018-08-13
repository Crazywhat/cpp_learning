 ///
 /// @file    public.cc
 /// @date    2018-08-12 18:56:36
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
	public:
		Point(int x,int y)
			:_x(x)
			 ,_y(y)
		{
		
		}
		void print()
		{
			cout << "Point: print()" << endl;
			cout << "(" << _x
				 <<	"," << _y
				<< ")" << endl;
		}
	protected: //将访问权开放给派生类
		int getx () const {return _x;}
		int gety () const {return _y;}
	private:
		int _x,_y;
};

class Point3D
:private Point  //private，实现继承;若不填，默认private
{
	public:
		Point3D(int x,int y,int z)
			:Point(x,y)
			 ,_z(z)	{}
	void display()
	{
		cout << "Point3D:display()" << endl;
		//protected继承，基类非私有成员，在派生类中的访问权限
		//全变为private(即该类的成员和派生类都无法访问其基类的成员)
		cout << "(" << getx()
			 <<	"," << gety()
			 << "," << _z
			 << ")" << endl;
	}
	private:
		int _z;
};

int main()
{
	Point3D p3(1,2,3);
	//p3.print(); //protected,private继承下
				  //创建的对象，无法访问基类的
				  //任何对象
	p3.display();
	return 0;
}
