 ///
 /// @file    main.c
 //
 
#include <stdio.h>
#include <iostream>

using std::cout;
using std::endl;


class singleton
{
private:
	static singleton* _psingleton;
	int _data;
	singleton(int data)
		:_data(data)
	{
		cout << "create instance " << endl;
	};
	~singleton()
	{
		cout << "destory instance " << endl;
	};
public:
	static singleton* setInstance(int data)
	{	
		if(NULL == _psingleton)
			_psingleton=new singleton(data);
		else
			_psingleton->_data=data;
		return _psingleton;
	}
	static void destory()
	{
		delete _psingleton;
	}
	void show_data() const
	{
		cout << "data :" << _data << endl;
	}
};

singleton* singleton::_psingleton=NULL;

int main(){
	
	singleton *p1=singleton::setInstance(666);
	p1->show_data();
	
	
	singleton *p2=singleton::setInstance(888);
	p2->show_data();

	printf("\np1:%p \np2:%p \n",p1,p2);

	singleton::destory();
	
	return 0;
}
