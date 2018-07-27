 ///
 /// @file    0main.cc
#include <stdlib.h>

#include <iostream>

using std::cout;
using std::endl;

class person
{
	public:
		person();
		~person();
	private:
		void * operator new (size_t);
		void operator delete(void *);
};

person::person()
{
	cout << "create person " << endl;
}

person::~person()
{
	cout << "destory person " << endl;
}

void * person::operator new (size_t size)
{
	cout << "new" << endl;
	void* paddr = malloc(size);
	return paddr;
}

void person::operator delete(void *paddr)
{
	cout << "delete" << endl;
	free(paddr);
}


int main(void)
{
	person p0;
	
	int *pi = new(int);

//	person *p1 = new(person);

	return 0;
}
