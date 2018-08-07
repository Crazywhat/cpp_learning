 ///
 /// @file    main.cc
 /// @date    2018-08-07 14:56:58
 ///
 
#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>
using std::cout;
using std::endl;
using std::vector;
using std::mem_fn;
using std::for_each;
using std::remove;

class Number
{
	public:
		Number(int num)
			:_num(num){}
		
		void display()
		{
			cout << _num << " | ";
		}

		bool is_even() const
		{
			return !(_num%2);
		}
		bool is_prime() const
		{
			if(1==_num) return false;
			for(int idex = 2; idex <= _num/2; ++ idex)
			{
				if(0==_num%idex)
					return false;
			}
			return true;
		}
	private:
		int _num;
};

int main()
{
	vector<Number> v{1,2,3,4,5,6,7,8,9,10};

	for_each(v.begin(),v.end(),mem_fn(&Number::display));
	cout << endl;

	v.erase(
			remove_if(v.begin(),v.end(),mem_fn(&Number::is_even))
			,v.end());
		
	for_each(v.begin(),v.end(),mem_fn(&Number::display));
	cout << endl;
	
	v.erase(
			remove_if(v.begin(),v.end(),mem_fn(&Number::is_prime))
			,v.end());
	for_each(v.begin(),v.end(),mem_fn(&Number::display));
	cout << endl;

	return 0;
}
