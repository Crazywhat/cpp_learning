 ///
 /// @file    rsstest.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-08-06 10:08:05
 ///
 

#include "tinyxml2.h"
#include <iostream>
#include <string>

#include <boost/regex.hpp>
using std::cout;
using std::endl;
using std::string;
using namespace tinyxml2;

void test0(void)
{
	XMLDocument doc;
	doc.LoadFile("coolshell.xml");
	if(doc.ErrorID()) {
		cout << " XMLDocument LoadFile error!" << endl;
	}
	
	XMLElement * itemNode = doc.FirstChildElement("rss")
		->FirstChildElement("channel")
		->FirstChildElement("item");

	int cnt = 5;
	while(itemNode) {
		XMLElement * titleNode = itemNode->FirstChildElement("title");
		XMLElement * linkNode = itemNode->FirstChildElement("link");
		XMLElement * descriptionNode = itemNode->FirstChildElement("description"); XMLElement * contentNode = itemNode->FirstChildElement("content:encoded");
		
		string title(titleNode->GetText());
		string link(linkNode->GetText());
		string description(descriptionNode->GetText());
		string content(contentNode->GetText());

		cout << "title: --> " << title << endl;
		cout << "link: --> " << link << endl;
		cout << "description: --> " << description << endl;
	
		//cout << "content: --> " << content << endl;
		//learning by doing 
		//正则表达式
		
		//拼凑一个正则表达式，能够匹配所有的html的标签
		boost::regex re("</?[^>]+>");

		string result = boost::regex_replace(content, re, string(""));
		cout << "result: " << result << endl;
		cout << " >>> cnt =" << cnt << endl;
		--cnt;
		if(cnt) {
			itemNode = itemNode->NextSiblingElement("item");
		} else
			break;
	}
}
 
int main(void)
{
	test0();
	return 0;
}
