#include "mylog.h"

using std::cout;
using std::endl;

//加载配置文件
void Mylogger::load_config()
{
	try
	{
		log4cpp::PropertyConfigurator::configure("./log4cpp.config");
	}
	catch(log4cpp::ConfigureFailure& f)
	{
		cout << "Configure Problem " << f.what() << endl;
		exit(-1);
	}
}

//单例初始化
Mylogger* Mylogger::getInstance()
{
	if(!_mylog)
	{
		load_config();
		_mylog = new Mylogger;
	}
	return _mylog;
}

//销毁日志对象
void Mylogger::destory()
{
	if(_mylog)
	{
		delete _mylog;
	}
	log4cpp::Category::shutdown();
}
//构造函数
Mylogger::Mylogger()
	:_logCategory(log4cpp::Category::getInstance("rootCategory"))
{

}
//析构函数
Mylogger::~Mylogger()
{

}
//记录警告信息
void Mylogger::warn(const char * msg)
{
	_logCategory.warn(msg);
}
//记录错误信息
void Mylogger::error(const char * msg)
{
	_logCategory.error(msg);
}
//记录调试信息
void Mylogger::debug(const char * msg)
{
	_logCategory.debug(msg);
}
//记录通知信息
void Mylogger::info(const char * msg)
{
	_logCategory.info(msg);

}
Mylogger* Mylogger::_mylog=NULL;
