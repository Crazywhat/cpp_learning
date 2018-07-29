///
/// @file    main.cc
/// @date    2018-07-29 13:31:36
///

#include <iostream>
using std::cout;
using std::endl;

#include<stdio.h>

int main()
{
	char file[16];
	char func[16];
	sprintf(file,__FILE__); //文件名
	sprintf(func,__FUNCTION__);//函数名
	printf("file=%s\n",__FILE__);
	printf("func=%s\n",func);
	printf("%05d\n",__LINE__);//行号 
	return 0;
}

