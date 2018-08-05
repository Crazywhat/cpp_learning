 ///
 /// @file    main.cc
 /// @date    2018-08-03 23:42:40
 ///
#include "queue.h" 
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

int test0()
{
	Queue<int> q0(2);

	if(q0.empty()) cout << "q0 is empty ." << endl;

	q0.push(0);
	q0.push(1);

	cout << "q0.front() = " << q0.front() << endl;
	cout << "q0.back() = " << q0.back() << endl;

	if(q0.full()) cout << "q0 is full. " << endl;

	q0.push(2);

	q0.pop();
	cout << "q0.front() = " << q0.front() << endl;
	q0.pop();
	q0.pop();
	

	return 0;
}

int test1()
{
	Queue<string> q0(3);

	if(q0.empty()) cout << "q0 is empty ." << endl;

	q0.push("good");
	q0.push("morning");
	q0.push("bye");

	cout << "q0.front() = " << q0.front() << endl;
	cout << "q0.back() = " << q0.back() << endl;

	if(q0.full()) cout << "q0 is full. " << endl;

	q0.push("fine");

	q0.pop();
	cout << "q0.front() = " << q0.front() << endl;
	q0.pop();
	q0.pop();
	q0.pop();
	

	return 0;
}

int main(void)
{
	test0();
	cout << "------------------------------------------"<< endl;
	test1();
	return 0;
}
