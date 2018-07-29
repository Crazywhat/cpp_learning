#include <iostream>

#include <log4cpp/Category.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/PatternLayout.hh>

using std::cout;

int main(int argc, char* argv[])
{
	log4cpp::OstreamAppender* os_appender = new log4cpp::OstreamAppender("os_logout",&cout);
	
	log4cpp::PatternLayout* test_logout = new log4cpp::PatternLayout();
	test_logout->setConversionPattern("%d %f %l : %p %c %x: %m%n");

	os_appender->setLayout(test_logout);

	log4cpp::Category& root = log4cpp::Category::getRoot();
	
	log4cpp::Category& infoCategory = root.getInstance("infoCategory");
	infoCategory.addAppender(os_appender);

	infoCategory.setPriority(log4cpp::Priority::INFO);

	infoCategory.info("system is running");
	infoCategory.warn("I have a dream , e...  , a warning");
	infoCategory.error("error , error , error ! Do you konw ?!");


	log4cpp::Category::shutdown();

	return 0;
}
