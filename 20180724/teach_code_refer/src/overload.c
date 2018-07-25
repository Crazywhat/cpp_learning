 ///
 /// @file    overload.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-24 15:02:14
 ///
 
//C语言不支持函数重载

#include <stdio.h>

int add(int x, int y)
{
	return x + y;
}

int add(int x, int y, int z)
{
	return x + y + z;
}
 
int main(void)
{
	int a = 3, b = 4, c = 5;
	printf("a + b = %d\n", add(a, b));
	printf("a + b +c = %d\n", add(a, b, c));

	return 0;
}
