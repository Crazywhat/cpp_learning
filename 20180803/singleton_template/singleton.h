 ///
 /// @file    singleton.cc
 /// @date    2018-08-04 08:21:55
 ///
#include <pthread.h> 
#include <cstdlib>
#include <iostream>
using std::cout;
using std::endl;

template <typename Type,typename... Args>
class Singleton
{
public:
static Type* getInstance(Args... args);
static void destory();
private:
	Singleton(){}
	~Singleton(){}
private:
	static Singleton* _psingleton;
	static Type* _pdata;
};

template <typename Type,typename... Args>
Type* Singleton<Type,Args...>::getInstance(Args... args)
{
	if(!_psingleton)
	{
		_psingleton = new Singleton();
		_pdata = new Type(args...);
	}
	return _pdata;
}
template <typename Type,typename... Args>
void Singleton<Type,Args...>::destory()
{
	if(_psingleton)
	{
		delete _psingleton;
		delete _pdata;
		_psingleton=NULL;
		_pdata=NULL;
	}
}

