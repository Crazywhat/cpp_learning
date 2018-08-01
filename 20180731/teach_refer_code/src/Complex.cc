 ///
 /// @file    Complex.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-31 10:08:06
 ///
 
#include <iostream>
#include <limits>

using std::cout;
using std::endl;


class Complex
{
public:
	Complex(double dreal = 0, double dimag = 0)
	: _dreal(dreal)
	, _dimag(dimag)
	{
		cout << "Complex(double, double)" << endl;
	}

	void display() const
	{	//欧拉公式    i^2 = -1
		cout << _dreal;
		if(_dimag > 0)
			cout << " + " << _dimag << "i" << endl;
		else if(_dimag < 0)
			cout << " - " << (-1) * _dimag << "i" << endl;
		else 
			cout << endl;
	}

	//复合赋值运算符推荐以成员函数形式重载
	Complex & operator+=(const Complex & rhs)
	{
		_dreal += rhs._dreal;
		_dimag += rhs._dimag;
		return *this;
	}

	//前置++ 的执行效率要比后置++ 高
	Complex & operator++()
	{
		++_dreal;
		++_dimag;
		return *this;
	}

	//后置++ , 这里的int只是用来与前置++做区分的，并不是真的传递参数
	Complex operator++(int)
	{
		Complex temp(*this);
		++_dreal;
		++_dimag;
		return temp;//调用复制构造函数
	}

	//inline函数
	//double getReal() const {	return _dreal;	}
	//double getImage() const {	return _dimag;	}
	
	//如果以成员函数形式重载输出流运算符,左操作数必然是对象本身
	//而输出流运算符左操作数要求是流对象, 输出流运算符不能以成员函数形式进行重载
	//static std::ostream & operator<<(std::ostream & os, const Complex & rhs);
	friend std::ostream & operator<<(std::ostream & os, const Complex & rhs);
	friend std::istream & operator>>(std::istream & is, Complex & rhs);

private:
	double _dreal;
	double _dimag;
};

#if 0
// 运算符重载时，其参数必须是自定义类类型或者是枚举类型
int operator+(int x, int y)
{
	return x - y;
}
#endif

std::ostream & operator<<(std::ostream & os, const Complex & rhs)
{
	os << rhs._dreal;
	if(rhs._dimag > 0)
		os << " + " << rhs._dimag << "i";
	else if(rhs._dimag < 0)
		os << " - " << (-1) * rhs._dimag << "i";
	return os;
}

void readDouble(std::istream & is, double & num)
{
	cout << "pls input a double number:" << endl;
	while(is >> num, !is.eof())
	{
		if(is.bad()) 
		{
			cout << "istream is breaken!" <<endl;
			return;
		} else if(is.fail()) {
			is.clear();
			is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "pls input a double number:" << endl;
			continue;
		}
		break;
	}
}

std::istream & operator>>(std::istream & is, Complex & rhs)
{
	readDouble(is, rhs._dreal);
	readDouble(is, rhs._dimag);
	return is;
}

//普通函数
Complex operator+(const Complex & lhs, const Complex & rhs)
{
	Complex temp(lhs);
	temp += rhs;// 利用已经实现的+= 运算符完成的
	return temp;
	//return Complex(lhs.getReal() + rhs.getReal(),
	//			   lhs.getImage() + rhs.getImage());
}

 
int test0(void)
{
	int a = 3, b = 4;
	int c = a + b;

	//a += b;// a = a + b;

	//&(++a);//a = 4
	//&(a++);//4, a = 5  error
	cout << " ++a = "  << (++a) << " , a = " << a << endl;
	cout << "a++  = " << (a++)  << " , a = " << a << endl;

	//多用前置
	for(size_t idx = 0; idx != 10; ++idx)
	{
	
	}

	Complex c1(1, 2);
	Complex c2(-3, -6);
	c2.display();

	Complex c3 = c1 + c2;
	c3.display();
	cout << endl;

	cout << "c1变化之前的值:";
	c1.display();
	cout << "前置++:";
	(++c1).display();
	cout << "c1的值:";
	c1.display();
	cout << endl;

	&(++c1);//ok
	//&c1++;//error
	
	cout << "后置++:";
	(c1++).display();
	cout << "c1的值:";
	c1.display();
	cout << endl;

	Complex c4 = 5 + c1;
	cout << "c4 = ";
	c4.display();

	return 0;
}

void test1(void)
{
	Complex c1(1, 2);
	cout << "c1 = " << c1 << endl;
	Complex c2(0, 0);
	cout << "c2 = " << c2 << endl;
	Complex c3(-1, -2);
	cout << "c3 = " << c3 << endl;

	cout << "通过终端输入:" << endl;
	std::cin >> c3;
	cout << "c3 = " << c3 << endl;
}

int main(void)
{
	test1();
	return 0;
}
