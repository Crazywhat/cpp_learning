#include <string.h>

class Computer{
	private:
		char _brand[20];
		float _price;
	public:
		void set_brand(const char*);
		void set_price(float);
		void show_info();
		Computer()
		{
			_price=0;
		}
		Computer(const Computer &rvl)
			:_price(rvl._price)
		{
			strcpy(_brand,rvl._brand);
		}
};
