 ///
 /// @file    main.cc
 /// @date    2018-08-02 15:12:45
 ///

#include "rssreader.h"
#include <iostream>
using std::cout;
using std::endl;
using namespace tinyxml2;

int main()
{
	RssReader r("coolshell.xml");

	r.dump("pagelib.dat");

	return 0;
}
