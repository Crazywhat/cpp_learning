 ///
 /// @file    main.cc
 //
#include <iostream>

using std::cout;
using std::endl;


void exchange(int &a,int &b){
	int temp=a;
	a=b;
	b=temp;
}

int main(){

	int a=3,b=4;

	cout << "before :" <<"a = "<< a <<"; b = " << b <<endl;
	exchange(a,b);	
	cout << "after :" <<"a = "<< a <<"; b = " << b <<endl;
	
	return 0;
}
