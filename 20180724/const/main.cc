 ///
 /// @file    main.c
 //
 //
 #include <iostream>

using std::cout;
using std::endl;

int main(){

	int a=10;
	int b=5;
	const int *p0=&a;

	//指向对象的值不能改变
	//	*p=b;      assignment of read-only location ‘* p’
	//	可以
	cout<<*p0<<endl;
	p0=&b;
	cout<<*p0<<endl;

	//同上
	int const *p1=&a;
	//*p1=b;        assignment of read-only location ‘* p1’
	p1=&b;

	//指向的对象不能变
	//assignment of read-only variable ‘p2’
	int* const  p2=&a;
	*p2=5;
//	p2=&b;





	return 0;
}
