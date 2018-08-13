 ///
 /// @file    main.cc
 /// @date    2018-08-13 19:32:07
 ///
 
#include <iostream>
using std::cout;
using std::endl;


class Circle
{
	public:
		Circle()
			:_radius(0)
		{
			cout << "Circle()" << endl;
		}
		Circle(double r)
			:_radius(r)
		{
			cout << "Circle(double radius)" << endl;
		}
		double getArea() const
		{
			return Pi*_radius*_radius;	
		}
		double getPerimeter() const
		{
			return 2*Pi*_radius;
		}
		void show() const
		{
			cout << "[circle] " << endl
					<<"\tradius :" << _radius
					<<" cm;\n\tPerimeter :" << getPerimeter()
					<< " cm;\n\tArea :" << getArea() 
					<< " cm^2;" << endl;
		}
	private:
		static double Pi;
		double _radius;
};
double Circle::Pi = 3.1415926;

class Cylinder
:public Circle
{
	public:
		Cylinder(double r,double h)
			:Circle(r)
			 ,_high(h)
		{
			cout << "Cylinder(double r,double h)" << endl;
		}
		double getVolume() const
		{
			return getArea()*_high;
		}
		void showVolume() const
		{
			cout << "[Cylinder]" << endl
				 << "\tvolume :" << getVolume() 
				 << " cm^3;" << endl;
		}
	private:
		double _high;
};

int main()
{
	Cylinder c(3,5);
	c.show();
	c.showVolume();
	return 0;
}
