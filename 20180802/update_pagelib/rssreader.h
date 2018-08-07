///
/// @file    rssitem.h
/// @date    2018-08-02 15:42:36
///

#ifndef __RSSREADER_H__
#define __RSSREADER_H__

#include "tinyxml2.h"
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using namespace tinyxml2;

typedef struct
{
	string title;
	string link;
	string content;
}RssItem;

class RssReader
{
	public:
		RssReader(const char* xml_path);
		void dump(const char* lib_path);//输出
	private:
		void load_xml(const char* xml_path);//加载rss文件
		void clean_content(string&);//清理content内容
		void clean_content_line(string&);//逐行清理content内容
		int create_pagelib(const char*);//创建写入的xml文件
		void parseRss(XMLDocument &doc);//解析
	private:
		vector<RssItem> _rss;
};   

#endif
