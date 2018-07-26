 ///
 /// @file    testmain.cc
 
#include "Computer.h"

#include <iostream>
#include <string.h>

int main()
{
	Computer com;
	com.set_brand("thinkpad");
	com.set_price(0);
	com.show_info();

	Computer com2=com;
	com2.show_info();

	return 0;
}
