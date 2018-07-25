 ///
 /// @file    main.cc
 //
 //

#include <stdio.h>
#include <iostream>

using std::cout;
using std::endl;

#ifdef __cplusplus
extern "C"
{
#endif

	int add(int a,int b){
		return a+b;
	}

#ifdef __cplusplus
}//end of extern "c"
#endif

int add(int a,int b,int c){
	return a+b+c;
}


int main(){
	
	return 0;
}
