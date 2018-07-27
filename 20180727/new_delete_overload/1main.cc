///
/// @file    1main.cc
#include <stdlib.h>

#include <iostream>

using std::cout;
using std::endl;

class person
{
	private:
		~person();
	public:
		person();
		void * operator new (size_t);
		void operator delete(void *);
		void clean_person();
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



void person::clean_person()
{
	delete this;
}


int main(void)
{
	//	person p0;

	person *p1 = new person;

	p1->clean_person();

	return 0;
}
