 ///
 /// @file    main.cc
 //
 
#include <stdio.h>
#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

class girl
{

private:
	const char *_name;
	int _age;
	int& _oral_age;
public:
	static int count;
	girl(const char *name, int age ,int& oral_age)
		: _name(name)
		, _age(age)
		, _oral_age(oral_age)
	{
		++count;	
	}
	void show() const
	{
	//	_age=18; read_only
		cout << "name :" << _name << "  age :"<< _age << "  oral_age :" << _oral_age << endl;
	}
		
};

class student
{
private:
	girl _g;
public:
	student(const char *name, int age ,int& oral_age)
		:_g(name,age,oral_age)
	{
	
	}

	void show(){
		_g.show();
	}

};

int girl::count = 0;

int main()
{
	int oral_age=0;
	girl myg("who",20,oral_age);
	oral_age=17;
	myg.show();
	
	student s("xiaohong",20,oral_age);
	
	s.show();
	cout << girl::count << endl;

	return 0;
}
