#ifndef __FILE_LINE_MACRO_H__
#define __FILE_LINE_MACRO_H__
#include <sstream>

inline std::string int2string(int num)
{
	std::ostringstream os;
	os << num;
	return os.str();
}

#define subfix(msg) \
	std::string(msg)\
.append(" ##FILE:").append(__FILE__)\
.append("; FUC: ").append(__func__)\
.append("; LINE: ").append(int2string(__LINE__))\
.append(" ##").c_str()

#define warn(msg) warn(subfix(msg))
#define error(msg) error(subfix(msg))
#define debug(msg) debug(subfix(msg))
#define info(msg) info(subfix(msg))

#endif
