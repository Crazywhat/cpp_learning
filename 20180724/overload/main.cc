 ///
 /// @file    main.cc
 //
 
#include <iostream>

using std::cout;
using std::endl;


//call of overloaded ‘add(int, int)’ is ambiguous
//int add(int a,int b,int c=0){
int add(int a,int b,int c){
	return a+b+c;
}

int add(int a,int b){
	return a+b;
}

int main(){


	cout << add(3,2) << endl;

	return 0;
}
