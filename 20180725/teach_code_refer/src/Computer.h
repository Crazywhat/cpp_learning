 ///
 /// @file    Computer.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-25 11:56:19
 ///
 
#ifndef __COMPUTER_H__
#define __COMPUTER_H__

class Computer
{// 类内部
public:// 类对外提供的接口（服务、功能）
	//成员函数
	void setBrand(const char *);
	void setPrice(float);
	void print();
	
private:
	char _brand[20];// m_brand数据成员
	float _price;// price_
};

#endif
