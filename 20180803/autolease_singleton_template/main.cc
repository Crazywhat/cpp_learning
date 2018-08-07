 ///
 /// @file    main.cc
 /// @date    2018-08-04 08:54:29
 ///
#include "singleton.h" 
#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

template <typename Type>
Singleton<Type>*	Singleton<Type>::_psingleton=NULL;
template <typename Type>
Type* Singleton<Type>::_pdata=NULL;

template <typename Type>
class Singleton<Type>::AutoRelease Singleton<Type>::_autorelease;

int test0(){
	
	int* pint0=Singleton<int>::getInstance(5);
	int* pint1=Singleton<int>::getInstance(5);

	printf("p0 addr:%p , *p0:%d\n",pint0,*pint0);
	printf("p1 addr:%p , *p1:%d\n",pint1,*pint1);


	return 0;
}

int test1(){
	
	string* pstring0=Singleton<string>::getInstance("good morning");
	string* pstring1=Singleton<string>::getInstance("good morning");

	printf("p0 addr:%p , *p0:%s\n",pstring0,pstring0->c_str());
	printf("p1 addr:%p , *p1:%s\n",pstring1,pstring1->c_str());
	
	*(pstring0)="just for fun.";

	printf("p0 addr:%p , *p0:%s\n",pstring0,pstring0->c_str());
	printf("p1 addr:%p , *p1:%s\n",pstring1,pstring1->c_str());
	

	return 0;
}

int test2()
{
	vector<int>* pv0 = Singleton<vector<int> >::getInstance(10,2);
	vector<int>* pv1 = Singleton<vector<int> >::getInstance(10,2);


	printf("pv0 addr:%p \n",pv0);
	printf("pv1 addr:%p \n",pv1);

	cout << endl;
	
	for(auto idex : *pv0)
		cout << " " << idex;

	return 0;
}


int main(){
	
	test0();	
	cout << "-----------------------------------------" << endl;
	test1();
	cout << "-----------------------------------------" << endl;
	test2();

	return 0;
}

