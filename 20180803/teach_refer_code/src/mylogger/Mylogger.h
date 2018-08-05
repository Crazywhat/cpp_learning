 ///
 /// @file    Mylogger.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-30 17:15:20
 ///
 
#ifndef _MYLOGGER_H__
#define _MYLOGGER_H__

#include <log4cpp/Category.hh>
#include <string>

using std::string;


class Mylogger
{
public:
	static Mylogger * getInstance();

	static void destroy();

	void warn(const char * msg);

	template <typename... Args>
	void warn(const char * msg, Args... args)
	{
		_category.warn(msg, args...);
	}

	void error(const char * msg);

	template <typename... Args>
	void error(const char * msg, Args... args)
	{
		_category.error(msg, args...);
	}
	void info(const char * msg);

	template <typename... Args>
	void info(const char * msg, Args... args)
	{
		_category.info(msg, args...);
	}

	void debug(const char * msg);

	template <typename... Args>
	void debug(const char * msg, Args... args)
	{
		_category.debug(msg, args...);
	}

private:
	Mylogger();
	~Mylogger();
	
private:
	static Mylogger * _pInstance;
	log4cpp::Category & _category;
};

#define prefix(msg) string("[")\
		.append(__FILE__).append(":")\
		.append(__FUNCTION__).append(":")\
		.append(std::to_string(__LINE__)).append("] ").append(msg).c_str()

#define LogWarn(msg, ...) Mylogger::getInstance()->warn(prefix(msg), ##__VA_ARGS__);
#define LogError(msg, ...) Mylogger::getInstance()->error(prefix(msg), ##__VA_ARGS__);
#define LogInfo(msg, ...) Mylogger::getInstance()->info(prefix(msg), ##__VA_ARGS__);
#define LogDebug(msg, ...) Mylogger::getInstance()->debug(prefix(msg), ##__VA_ARGS__);

#endif

