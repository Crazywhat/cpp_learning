 ///
 /// @file    main.cc


#include <stdlib.h>

#include <iostream>

using std::cout;
using std::endl;

int main(){

	int data=34;

	cout << (double)data << endl;
	cout << double(data) << endl;
	cout << static_cast<double>(data) <<endl;


	double *p=static_cast<double*>(malloc(sizeof(double)));
	*p=23.34;

	cout << *p << endl;

	return 0;
}
