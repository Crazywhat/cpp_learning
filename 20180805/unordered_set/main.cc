///
/// @file    main.cc
/// @date    2018-08-06 15:52:00
///

#include <cmath>
#include <iostream>
#include <vector>
#include <unordered_set>
using std::cout;
using std::endl;
using std::vector;
using std::ostream;
using std::unordered_set;

int test()
{
	int arr[10]={5,24,12,2,1,61,79,98,9,0};
	unordered_set<int> us_int(arr,arr+10);

	for(auto & elem : us_int)
	{
		cout << elem << " ";
	}
	cout << endl;

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
		int get_x() const { return _x;}
		int get_y() const { return _y;}
		friend bool operator < (const Point &lhs,const Point &rhs);
		friend bool operator > (const Point &lhs,const Point &rhs);
		friend bool operator == (const Point &lhs,const Point &rhs);
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

bool operator == (const Point &lhs,const Point &rhs)
{
	return (lhs._x==rhs._x)&&(lhs._y==rhs._y);
}
ostream& operator<<(ostream &os,const Point &p)
{
	os << "( " << p._x << " , " << p._y << " )";
	return os;
}

//标准库特例化
namespace std{
	template<>
	struct hash<Point>
	{
		size_t operator()( Point const& p) const
		{
			return (std::hash<int>()(p.get_x()) >> 1)
			 ^ (std::hash<int>()(p.get_y()) << 1);
		}
	};

}


//自定义哈希生成
struct PointHash
{
	size_t operator()( Point const& p) const
	{
		return (std::hash<int>()(p.get_x()) >> 1)
		 ^ (std::hash<int>()(p.get_y()) << 1);
	}
};

int test1()
{
	Point arr[10]={Point(1,3),Point(2,4),Point(3,6),
					Point(5,4),Point(4,4),Point(7,4),
					Point(2,0),Point(2,4),Point(7,4),
					Point(8,8),};
//	unordered_set<Point,PointHash> us_int; //使用自定义生成hash
	unordered_set<Point> us_int;           //使用特例化的标准库hash

	for(int i=0; i!=10; ++i)
	{
		us_int.insert(arr[i]);
	}


	for(auto & elem : us_int)
	{
		cout << elem << endl;
	}
	cout << endl;

	return 0;
}

int main()
{	
	test1();
	return 0;
}
