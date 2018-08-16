 ///
 /// @file    controller.h
 /// @date    2018-08-16 17:55:53
 ///
 
#ifndef __SIMS_CONTROOLER_H__
#define __SIMS_CONTROOLER_H__ 
#include "info.h"
#include <list>
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::list;
using std::string;

class Controller
{
public:
	virtual void modifyById(int) = 0;
	virtual void searchById(int) = 0;
	virtual void searchByName(const string&) = 0;
	virtual void deleteById(int) = 0;	
	virtual void deleteByName(const string&) = 0;	
	virtual void addInfo() = 0;
	virtual void showAll() = 0;
};

class StudentInfoController
:public Controller
{
public:
	StudentInfoController(list<StudentInfo> &students)
		:_students(students){}
	void modifyById(int);
	void searchById(int);
	void searchByName(const string&);
	void deleteById(int);	
	void deleteByName(const string&);	
	void addInfo();
	void showAll();
private:
		list<StudentInfo> _students;
};

class UserInfoController
:public Controller
{
public:
	UserInfoController(list<UserInfo> &users)
			:_users(users){}
	void modifyById(int);
	void searchById(int);
	void searchByName(const string&);
	void deleteById(int);	
	void deleteByName(const string&);	
	void addInfo();
	void showAll();
private:
		list<UserInfo> _users;
};

#endif
