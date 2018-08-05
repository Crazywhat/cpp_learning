 ///
 /// @file    Test.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-30 16:47:13
 ///
 
#include "Mylogger.h"
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

int test0(void)
{
	cout << __FUNCTION__ << endl;
	cout << __FILE__ << endl;

	cout << __LINE__ << endl;
	return 0;
}


void test1(void)
{
	Mylogger::getInstance()->warn("this is warn message");
	Mylogger::getInstance()->error("this is warn message");
	Mylogger::getInstance()->info("this is warn message");
	Mylogger::getInstance()->debug("this is warn message");
}

void test2(void)
{
	Mylogger::getInstance()->warn(prefix("this is warn message"));
	Mylogger::getInstance()->error(prefix("this is warn message"));
	Mylogger::getInstance()->info(prefix("this is warn message"));
	Mylogger::getInstance()->debug(prefix("this is warn message"));
}

void test3(void)
{
	int a = 10;
	double b = 1.1;
	const char * pstr = "hello,";
	LogWarn("this is warn message, %d, %s, %f\n", a, b, pstr);
	LogWarn("this is warn message");
	LogError("this is error message");
	LogInfo("this is info message");
	LogDebug("this is debug message");
}

int main(void)
{
	//test0();
	//test1();
	//test2();
	test3();
	return 0;
}
