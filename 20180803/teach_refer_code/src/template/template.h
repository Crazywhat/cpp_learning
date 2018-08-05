 ///
 /// @file    template.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-08-03 10:55:02
 ///
 
#ifndef __TEMPLATE_H__
#define __TEMPLATE_H__

//模板的实现是可以分成声明和实现的;
//但是在include头文件的时候，必须要看到模板的全部实现;
//否则编译不通过
template <typename Type>
Type add(Type x, Type y);

#include "template.txx"

#endif

