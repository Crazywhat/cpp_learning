 ///
 /// @file    main.cc
 /// @date    2018-08-10 23:25:00
 ///

//普通指针如何处理
//如文件指针

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::shared_ptr;
using std::unique_ptr;
struct fileDeleter
{
	void operator()(FILE* f)
	{
		if(f)
		{
			fclose(f);
		}
		cout << "fileDeleter" << endl;
	}
};


int test0(){

	shared_ptr<FILE> spf(fopen("1.txt","w+"),fileDeleter());

	char str[100]="good";

	fwrite(str,1,strlen(str),spf.get());	

	return 0;
}

int test1(){

	unique_ptr<FILE,fileDeleter> spf(fopen("1.txt","w+"),fileDeleter());

	char str[100]="good";

	fwrite(str,1,strlen(str),spf.get());	

	return 0;
}

int main()
{
//	test0();
	test1();
	return 0;
}
