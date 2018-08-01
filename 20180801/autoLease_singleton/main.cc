 ///
 /// @file    main.cc
 /// @date    2018-08-01 10:40:58
 ///
#include <cstdio> 
#include <iostream>
using std::cout;
using std::endl;

class Autorelease
{
public:
	Autorelease();
	~Autorelease();
};

class Singleton
{
public:
friend class Autorelease;
static	Singleton* getInstance(){
		if(!_psingleton)
		{
			_psingleton = new Singleton;
		}
		return _psingleton;
	}
private:
	Singleton(){cout << "singleton create" << endl;}
	~Singleton(){cout << "~singleton" << endl;}
private:
	static Singleton *_psingleton;
	static Autorelease _at;
};

Autorelease::Autorelease(){
	cout << "autorelease create" << endl;
}
Autorelease::~Autorelease()
{
	if(Singleton::_psingleton)
	{
		cout << "delete _psingleton" << endl;
		delete Singleton::_psingleton;
	}
	cout << "~auto" << endl;	
}

Singleton* Singleton::_psingleton=NULL;
Autorelease Singleton::_at;
int main(){
	
	Singleton *p0 = Singleton::getInstance();
	Singleton *p1 = Singleton::getInstance();
	
	printf("p0 : %p\n",p0);
	printf("p1 : %p\n",p1);

	return 0;
}
