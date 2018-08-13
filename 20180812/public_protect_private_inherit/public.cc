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
:public Point  //public，接口继承;若不填，默认private
{
	public:
		Point3D(int x,int y,int z)
			:Point(x,y)
			 ,_z(z)	{}
	void display()
	{
		cout << "Point3D:display()" << endl;
		//public继承，基类非私有成员，在派生类中访问权限不变
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
	//p3.getx(); //protected ,对象无法访问
	p3.print();
	p3.display();
	return 0;
}
