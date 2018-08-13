 ///
 /// @file    main.cc
 /// @date    2018-08-13 23:44:19
 ///
 
#include <iostream>
using std::cout;
using std::endl;

#pragma pack(push)
#pragma pack(4)
class Cell
{
	public:
		Cell()
			:_e(_c)
		{}
		virtual void display(){}
	private:
		int _a;
		char _b;
		double _c;
		short _d[5];
		double & _e;
		static int num;
};
#pragma pack(pop)

void test0(){
	//8字节对齐
	// |vir_ptr		|	
	// |a    |b|    |
	// |c			|
	// |d0-d3		|
	// |d4|			|
	// |e			|
	cout << "sizeof(Cell) = " << sizeof(Cell) << endl;
}

void test1()
{
	//4字节对齐
	//|vir_ptr     |
	//|vir_ptr     |
	//|a	       |
	//|b|		   |
	//|c	       |
	//|c           |
	//|d0-d1       |
	//|d2-d3       |
	//|d4          |
	//|e           |
	//|e           |
	cout << "sizeof(Cell) = " << sizeof(Cell) << endl;
}

int main()
{
//	test0();
	test1();
	return 0;
}
