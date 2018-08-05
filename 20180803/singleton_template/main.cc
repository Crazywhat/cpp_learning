 ///
 /// @file    main.cc
 /// @date    2018-08-04 08:54:29
 ///
#include "singleton.h" 
#include <cstdio>
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

template <typename Type,typename... Args>
Singleton<Type,Args...>*	Singleton<Type,Args...>::_psingleton=NULL;
template <typename Type,typename... Args>
Type* Singleton<Type,Args...>::_pdata=NULL;


int test0(){
	
	int* pint0=Singleton<int,int>::getInstance(5);
	int* pint1=Singleton<int,int>::getInstance(5);

	printf("p0 addr:%p , *p0:%d\n",pint0,*pint0);
	printf("p1 addr:%p , *p1:%d\n",pint1,*pint1);

	Singleton<int,int>::destory();

	return 0;
}

int test1(){
	
	string* pstring0=Singleton<string,const char*>::getInstance("good morning");
	string* pstring1=Singleton<string,const char*>::getInstance("good morning");

	printf("p0 addr:%p , *p0:%s\n",pstring0,pstring0->c_str());
	printf("p1 addr:%p , *p1:%s\n",pstring1,pstring1->c_str());
	
	*(pstring0)="just for fun.";

	printf("p0 addr:%p , *p0:%s\n",pstring0,pstring0->c_str());
	printf("p1 addr:%p , *p1:%s\n",pstring1,pstring1->c_str());
	
	Singleton<string,const char*>::destory();

	return 0;
}

int main(){
	
	test0();	
	cout << "-----------------------------------------" << endl;
	test1();

	return 0;
}

