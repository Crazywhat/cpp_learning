 ///
 /// @file    main.cc
 /// @date    2018-08-06 08:20:23
 ///
#include <cmath> 
#include <queue>
#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::endl;
using std::priority_queue;
using std::vector;
using std::string;
using std::ostream;
int test0()
{
	int arr[8]={1,5,2,3,8,7,4,6};
	priority_queue<int> pq;

	for(int idex = 0; idex != 8 ; ++idex)
	{
		pq.push(arr[idex]);
		cout << "top : " << pq.top() << endl;
	}
cout << "---------------------------------------" << endl;
	while(!pq.empty())
	{
		cout << "now top : " << pq.top() << endl;
		pq.pop();
	}

	return 0;
}
int test1()
{
	string s_arr[]={string("good"),string("apple"),string("ball"),
	string("cat"),string("double"),string("elephant"),string("food")};
//	priority_queue<string> pq(s_arr,s_arr+7);
	priority_queue<string,vector<string>,std::greater<string> > pq(s_arr,s_arr+7);
	cout << "---------------------------------------" << endl;
	while(!pq.empty())
	{
		cout << "now top : " << pq.top() << endl;
		pq.pop();
	}

	return 0;
}

struct comparator
{
	template <typename Type>
	bool operator()(Type& s1,Type& s2)
	{
		return s1 > s2;
	}
};

int test2()
{
	string s_arr[]={string("good"),string("apple"),string("ball"),
	string("cat"),string("double"),string("elephant"),string("food")};
	cout << "---------------------------------------" << endl;
	priority_queue<string,vector<string>,comparator > pq(s_arr,s_arr+7);
	while(!pq.empty())
	{
		cout << "now top : " << pq.top() << endl;
		pq.pop();
	}

	return 0;
}

class Point
{
	public:
		Point(int x=0,int y=0)
			:_x(x)
			,_y(y)
		{
			cout << "construct point" << endl;
		}

	float distance() const
	{
		return sqrt(_x*_x+_y*_y);
	}
	friend bool operator < (const Point &lhs,const Point &rhs);
	friend bool operator > (const Point &lhs,const Point &rhs);
	friend ostream& operator<<(ostream &os,const Point &p);
	private:
		int _x,_y;

};
bool operator < (const Point& lhs,const Point& rhs)
{
	return lhs.distance() < rhs.distance();
}
bool operator > (const Point& lhs,const Point& rhs)
{
	return lhs.distance() > rhs.distance();
}
ostream& operator<<(ostream &os,const Point &p)
{
	os << "( " << p._x << " , " << p._y << " )";
	return os;
}
int test3()
{
	Point p_arr[5]={Point(12,1),Point(1,2),Point(3,4),Point(2,1),Point(4,5)};
	cout << "---------------------------------------" << endl;
	//priority_queue<Point > pq(p_arr,p_arr+5);
	priority_queue<Point,vector<Point>,comparator> pq(p_arr,p_arr+5);
	while(!pq.empty())
	{
		cout << "now top :" << pq.top() << endl;
		pq.pop();
	}

	return 0;
}



int main()
{	
	//test0();
	//test1();
	//test2();
	test3();
	return 0;
}
