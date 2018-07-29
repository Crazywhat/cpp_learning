#ifndef __MY__LOG__H
#define __MY__LOG__H

#include <stdlib.h>
#include <log4cpp/Category.hh>
#include <log4cpp/PropertyConfigurator.hh>
#include <iostream>
#include <string>



class Mylogger
{
	public:
		void warn(const char * msg);
		void error(const char * msg);
		void debug(const char * msg);
		void info(const char * msg);
		static Mylogger* getInstance();
		void destory();
	private:
		Mylogger();
		~Mylogger();
		static void load_config();
	private:
		static Mylogger* _mylog;
		log4cpp::Category& _logCategory;
};



#endif
