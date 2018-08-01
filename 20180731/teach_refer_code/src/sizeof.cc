 ///
 /// @file    sizeof.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-31 10:03:45
 ///
 
#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;
 
int main(void)
{
	int a = 10;
	printf("sizeof(a) = %d\n", sizeof a);
	printf("sizeof(a) = %d\n", sizeof(int));

	return 0;
}
