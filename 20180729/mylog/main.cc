#include "mylog.h"

int main(void)
{
	const char* pstr = "\\(*=*)/";	
	logInfo("hello info,%d,%lf,%s",10,23.45,pstr);
	logDebug("hello debug,%s,%lf,%d",pstr,34.56,12);
	logError("hello error,%lf,%s,%d",89.78,pstr,12);
	logWarn("hello warn,%lf,%d,%s",123.4,89,pstr);
	

	return 0;
}
