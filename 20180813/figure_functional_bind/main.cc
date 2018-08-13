 ///
 /// @file    main.cc
 /// @date    2018-08-13 13:08:17
 ///
 
#include <cmath>
#include <functional>
#include <iostream>
using std::cout;
using std::endl;
using std::bind;
using std::function;

//基于对象的编程

class Figure
{
	public:
		using Display = function<void()>;
		using Area = function<double()>;
		friend void show_figure(Figure *f);

		void setDisplay(Display && rhs)
		{
			_display = std::move(rhs);
		}
		void setArea(Area && rhs)
		{
			_area = std::move(rhs);
		}
	private:
	Display _display;
	Area _area;
};

class Circle
{
	public:
		Circle(double r)
			:_r(r)
		{
			cout << "Circle()" << endl;
		}
		void i_am_circle(){ cout << "I am a circle .";}
		double circle_area(){ return 3.1415926*_r*_r;}
	private:
		double _r;
};

class Rectangle
{
	public:
		Rectangle(double longth,double width)
			:_longth(longth)
			 ,_width(width)
	{	
		cout << "Rectangle" << endl;
	}
	
		void i_am_rectangle(){ cout << "I am a Rectangle .";}
		double rectangle_area(){ return _width*_longth;}
	private:
		double _longth,_width;
};

class Triangle
{
	public:
		Triangle(double a, double b,double c)
			:_a(a)
			,_b(b)
			,_c(c)
		{
			cout << "Triangle()" << endl;
		}
		void i_am_triangle(){cout << "I am a triangle.";}
		double triangle_area()
		{
			double p = (_a+_b+_c)/2;
			return sqrt(p*(p-_a)*(p-_b)*(p-_c));
		}
	private:
		double _a,_b,_c;
};

void show_figure(Figure *f)
{
	f->_display();
	cout << " area: " << f->_area() << " cm^2" << endl;
}

int main()
{
	Circle c(5);
	Rectangle r(10,2);
	Triangle t(4,3,5);

	cout << "----------------" << endl;
	
	Figure f;
	f.setDisplay(bind(&Circle::i_am_circle,&c));
	f.setArea(bind(&Circle::circle_area,&c));
	show_figure(&f);

	f.setDisplay(bind(&Rectangle::i_am_rectangle,&r));
	f.setArea(bind(&Rectangle::rectangle_area,&r));
	show_figure(&f);
	
	f.setDisplay(bind(&Triangle::i_am_triangle,&t));
	f.setArea(bind(&Triangle::triangle_area,&t));
	show_figure(&f);

	return 0;
}
