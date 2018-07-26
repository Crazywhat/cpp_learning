 ///
 /// @file    Computer.cc

#include "Computer.h"

#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

void Computer::set_brand(const char* brand)
{
	strcpy(_brand,brand);
}

void Computer::set_price(float price )
{
	_price = price;
}

void Computer::show_info()
{
	cout << "brand :" << _brand << " price :" << _price <<endl ; 
}
