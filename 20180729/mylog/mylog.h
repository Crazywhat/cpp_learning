#ifndef __MY__LOG__H
#define __MY__LOG__H

#include <cstdlib>
#include <log4cpp/Category.hh>
#include <log4cpp/PropertyConfigurator.hh>
#include <iostream>
#include <string>
#include <sstream>

class Mylogger
{
	public:
		void warn(const char * msg);
		void error(const char * msg);
		void debug(const char * msg);
		void info(const char * msg);
		template <typename... Args>
		void warn(const char * msg,Args... args)
		{
			_logCategory.warn(msg,args...);
		}
		template <typename... Args>
		void error(const char * msg,Args... args)
		{
			_logCategory.error(msg,args...);
		}
		template <typename... Args>
		void debug(const char * msg,Args... args)
		{
			_logCategory.debug(msg,args...);
		}
		template <typename... Args>
		void info(const char * msg,Args... args)
		{
			_logCategory.info(msg,args...);
		}
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

inline std::string int2string(int num)
{
	std::ostringstream os;
	os << num;
	return os.str();
}

#define prefix(msg) \
	std::string("[ FILE:").append(__FILE__)\
.append("; FUC: ").append(__func__)\
.append("; LINE: ").append(int2string(__LINE__))\
.append(" ]: ").append(msg).c_str()

#define logWarn(msg, ...) Mylogger::getInstance()->warn(prefix(msg), ##__VA_ARGS__)
#define logError(msg, ...) Mylogger::getInstance()->error(prefix(msg), ##__VA_ARGS__)
#define logDebug(msg, ...) Mylogger::getInstance()->debug(prefix(msg), ##__VA_ARGS__)
#define logInfo(msg, ...) Mylogger::getInstance()->info(prefix(msg), ##__VA_ARGS__)

#endif
