 ///
 /// @file    main.cc
 /// @date    2018-08-11 11:38:20
 ///

#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;

class Animal
{
	public:
		virtual void eat() //取决于指针所指对象的类型
		//void eat()     //只取决于指针本身的类型
		{
			cout << "Animal: I eat ." << endl;
		}
		virtual ~Animal(){};
		 //~Animal(){};
};
class Fish:public Animal
{
	public:
		void eat()
		{
			cout << "Fish: I eat ." << endl;
		}
};
class Wolf:public Animal
{
	public:
		void eat()
		{
			cout << "Wolf: I eat ." << endl;
		}
};
class Brid:public Animal
{
	public:
		void eat()
		{
			cout << "Brid: I eat ." << endl;
		}
};

//指针访问虚函数是最主要的方式
int test0()
{
	vector<Animal*> vall;
	vall.push_back(new Animal());
	vall.push_back(new Brid());
	vall.push_back(new Wolf());
	vall.push_back(new Fish());

	for(auto& elem : vall)
	{
		elem->eat();
		delete elem;
	}

	cout << "-------------------------" << endl;

	Animal a;
	Brid b;

	Animal *pa = &a;
	Animal *pab = &b;

	pa->eat();
	pab->eat();

	cout << "----change------" << endl;

	pa = &b;
	pab = & a;

	pa->eat();
	pab->eat();

	return 0;
}

//虚函数的访问
int test1()
{
	Animal a;
	Fish f;
	a.eat();
	f.eat();

	a = f;
	a.eat();

	f.Animal::eat();
	f.Fish::eat();


	return 0;
}

//引用访问虚函数
//引用一经声明后，引用变量本身无论如何改变
//其调用的函数就不会再改变，始终指向其开始定义时的函数
//可以将引用理解成一种“受限制的指针”
int test2()
{	
	Animal a;
	Wolf w;

	Animal& a_refer = a;
	Animal& aw_refer = w;
	Wolf& w_refer = w;

	cout << "a_refer: "; a_refer.eat();
	cout << "aw_refer: "; aw_refer.eat();
	cout << "w_refer: "; w_refer.eat();

	cout << "----------------------" << endl;

	aw_refer = a;
	a_refer = w;
	
	cout << "aw_refer: "; aw_refer.eat();
	cout << "a_refer: "; a_refer.eat();

	return 0;
}

int main()
{
	//test0();
	test1();
	//test2();
	return 0;
}
