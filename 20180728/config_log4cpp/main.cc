 ///
 /// @file    main.cc
 /// @date    2018-07-29 11:22:11
 ///
 
#include <iostream>
#include <string>

#include <log4cpp/Category.hh>
//#include <log4cpp/OstreamAppender.hh>
//#include <log4cpp/Priority.hh>
#include <log4cpp/PropertyConfigurator.hh>
//#include <log4cpp/RollingFileAppender.hh>

using std::cout;
using std::endl;
using std::string;

using namespace log4cpp;

int main(int argc, char* argv[])
{
	try
	{
		log4cpp::PropertyConfigurator::configure("./log4cpp.config");
	}
	catch(log4cpp::ConfigureFailure& f)
	{
		cout << "Configure Problem " << f.what() << endl;
		return -1;
	}

	log4cpp::Category& rootCategory = log4cpp::Category::getRoot();
	
	
	for(int i=0; i!=20 ; ++i )
	  rootCategory.info("mylogger's log");
	  rootCategory.alert("mylogger's log");


	return 0;
}
