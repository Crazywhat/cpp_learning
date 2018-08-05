
//1.用配置文件log4cpp.config,进行配置
//  能同时输出到终端和文件
//  采用滚动文件，文件名为roll.log，允许最大为10*1024*1024,最多两个

//2.封装的头文件和实现文件分别为mylog.h和mylog.cc

//3.用宏实现显示文件名，函数名，行号，实现在file_line_macro.h

//4.可用main.cc进行测试

编译时连接 -llog4cpp
