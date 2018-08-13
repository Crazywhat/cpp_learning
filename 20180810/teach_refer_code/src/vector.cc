 ///
 /// @file    vector.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-08-10 09:46:57
 ///
 
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
 
int main(void)
{

	//Point * pt = new Point[10];

	vector<int> numbers;
	numbers.reserve(100);
	cout << numbers.size() << endl;
	cout << numbers.capacity() << endl;

	return 0;
}
