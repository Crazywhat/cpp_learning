 ///
 /// @file    singletonTemplate.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-08-06 11:39:47
 ///
 
#include <iostream>
using std::cout;
using std::endl;


class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{	cout << "Point(int, int)" << endl;	}

	~Point() {	cout << "~Point()" << endl; }

	void print() const 
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}

private:
	int _ix;
	int _iy;
};

template <typename T>
class Singleton
{
	class AutoRelease
	{
	public:
		AutoRelease() {	cout << "AutoReleas()" << endl;	}
		~AutoRelease() {	
			if(_pInstance) {
				delete _pInstance;
			}
			cout << "~AutoRelease()" << endl;
		}
	};
public:
	template <typename... Args>
	static T * getInstance(Args... args)
	{
		if(_pInstance == nullptr) {
			_autoRelease;// 露脸
			_pInstance = new T(args...);
		}
		return _pInstance;
	}

/*
	static void destroy()
	{
		if(_pInstance)
		{
			delete _pInstance;
		}
	}
	*/

private:
	Singleton(){	cout << "Singleton()" << endl;}
	~Singleton() {	cout << "~Singleton()" << endl;	}
	
private:
	static T * _pInstance;
	static AutoRelease _autoRelease;
};

template <typename T>
T * Singleton<T>::_pInstance = NULL;

template <typename T>
class Singleton<T>::AutoRelease Singleton<T>::_autoRelease;

 
int main(void)
{
	Point * pt1 = Singleton<Point>::getInstance(1, 2);
	Point * pt2 = Singleton<Point>::getInstance(1, 2);
	printf("pt1 = %p\n", pt1);
	printf("pt2 = %p\n", pt2);

	Singleton<Point>::getInstance(1, 2)->print();

	//Singleton<Point>::destroy();
	return 0;
}
