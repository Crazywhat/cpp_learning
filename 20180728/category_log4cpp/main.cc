#include <iostream>

#include <log4cpp/Category.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/RollingFileAppender.hh>
using std::cout;

int main(int argc, char* argv[])
{
	log4cpp::OstreamAppender* os_appender = new log4cpp::OstreamAppender("os_appender",&cout);
	log4cpp::RollingFileAppender* roll_appendder = new log4cpp::RollingFileAppender("roll_appendder","1.txt",1024,true,0644);
	
	log4cpp::PatternLayout* test_logout = new log4cpp::PatternLayout();
	test_logout->setConversionPattern("%d: %p %c %x: %m%n");
	
	os_appender->setLayout(test_logout);
	roll_appendder->setLayout(new log4cpp::BasicLayout());


	log4cpp::Category& root = log4cpp::Category::getRoot();

	log4cpp::Category& sub1 = root.getInstance("sub1");
	log4cpp::Category& sub2 = root.getInstance("sub2");

	sub1.addAppender(roll_appendder);
	sub2.addAppender(os_appender);

	sub1.setPriority(log4cpp::Priority::INFO);
	sub2.setPriority(log4cpp::Priority::INFO);

	sub1.info("system is running");
	sub1.warn("I have a dream , e...  , a warning");
	sub1.error("error , error , error ! Do you konw ?!");
	sub2.info("system is running");
	sub2.warn("I have a dream , e...  , a warning");
	sub2.error("error , error , error ! Do you konw ?!");


	log4cpp::Category::shutdown();

	return 0;
}
