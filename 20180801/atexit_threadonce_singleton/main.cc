 ///
 /// @file    main.cc
 /// @date    2018-08-01 10:40:58
 ///
#include <stdlib.h>
#include <pthread.h>
#include <cstdio> 
#include <iostream>
using std::cout;
using std::endl;

class Singleton
{
public:
	static	Singleton* getInstance(){
			pthread_once(&_once,routine);	
			return _psingleton;
		}
private:
	Singleton(){cout << "singleton create" << endl;}
	~Singleton(){cout << "~singleton" << endl;}
	static void destroy(){
		cout << "destroy" << endl;
		delete _psingleton;
	}
	static void routine()
	{
		_psingleton = new Singleton;
		atexit(destroy);
	}
private:
	static Singleton *_psingleton;
	static pthread_once_t _once;
};

Singleton* Singleton::_psingleton = NULL;
pthread_once_t Singleton::_once =  PTHREAD_ONCE_INIT;

int main(void){
	
	Singleton *p0 = Singleton::getInstance();
	Singleton *p1 = Singleton::getInstance();
	
	printf("p0 : %p\n",p0);
	printf("p1 : %p\n",p1);

	return 0;
}
