 ///
 /// @file    main.cc
 /// @date    2018-08-01 13:18:11
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Data
{
public:
	Data(int n):_data(n){}
	Data & operator ++();
	Data operator ++(int);
	void dataPrint(){ cout << "data :" << _data << endl;}
private: 
	int _data;
};

Data & Data::operator++()
{
	++_data;
	return *this;
}
Data  Data::operator++(int n)
{
	Data tmep(*this);
	++_data;
	return tmep;
}

int main()
{
	Data d0(9);
	++d0;
	d0.dataPrint();

	(++d0).dataPrint();
	(d0++).dataPrint();
	
	
	d0.dataPrint();

	return 0;
}
