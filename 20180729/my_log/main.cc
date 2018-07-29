#include "mylog.h"
#include "file_line_macro.h"

Mylogger* Mylogger::_mylog=NULL;

int main(void)
{
	Mylogger *my = Mylogger::getInstance();
	
	my->info("hello info");
	my->debug("hello debug");
	my->error("hello error");
	my->warn("hello warn");
	
	my->destory();

	return 0;
}
