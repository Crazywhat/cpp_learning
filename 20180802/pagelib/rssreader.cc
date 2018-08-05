///
/// @file    rssitem.cc
/// @date    2018-08-02 15:46:14
///

#include "rssreader.h"
#include "tinyxml2.h"
#include <boost/regex.hpp>
#include <cstdlib>
#include <iostream>
#include <sstream>
using std::cout;
using std::endl;
using std::stringstream;
using namespace tinyxml2;
using namespace boost;

//类构造函数
RssReader::RssReader(const char* xml_path)
{
	load_xml(xml_path);
}
//打开xml文件
void RssReader::load_xml(const char* xml_path)
{
	XMLDocument doc;
	if(0!=doc.LoadFile(xml_path))
	{
		cout << "load xml file failed ." << endl;
		exit(-1);
	}
	parseRss(doc);	
}
//解析xml文件
void RssReader::parseRss(XMLDocument &doc)
{	
	XMLElement *root = doc.RootElement();
	XMLElement *channelNode=root->FirstChildElement("channel");
	if(NULL== channelNode){ cout << "find channelNode error." << endl; return;}
	XMLElement *itemNode=channelNode->FirstChildElement("item");
	while(NULL!=itemNode)
	{
		RssItem rt;
		rt.title=itemNode->FirstChildElement("title")->GetText();
		rt.link=itemNode->FirstChildElement("link")->GetText();
		rt.content=itemNode->FirstChildElement("content:encoded")->GetText();
		clean_content(rt.content);
		_rss.push_back(rt);
		itemNode=itemNode->NextSiblingElement();
	}
}
//逐行清理content内容
void RssReader::clean_content_line(string& lstr)
{
	regex reg0(".*?<[a-z]{1}.*?</[a-z]{1,10}[0-9]{0,1}>");
	regex reg3(".*?<.*?</[a-z]{1,10}[0-9]{0,1}>");
	regex reg1("(<[a-z]{1,10}[0-9]{0,1}.*?>)(.*?)(</[a-z]{1,10}[0-9]{0,1}>)");
	regex reg2("<img.*");
	if(regex_match(lstr,reg0)){
		while(regex_match(lstr,reg3))
		{
			lstr=regex_replace(lstr,reg1,"$2");
			if(regex_match(lstr,reg2))
			{
				lstr="";
				break;
			}
		}
	}else
	{
		lstr="";
	}

}

//清理content内容
void RssReader::clean_content(string& cstr)
{
	stringstream ss;
	ss << cstr;
	char s[1024]="";
	string s_all;
	while(ss.getline(s,1024,'\n'))
	{
		string ts(s);
		clean_content_line(ts);
		if(ts.size()!=0)
			s_all+=ts+"\n";
	}
	cstr=s_all;
}

//创建xml文件
int RssReader::create_pagelib(const char* lib_path)
{
	XMLDocument doc;
	XMLDeclaration *declaration=doc.NewDeclaration();
	doc.InsertFirstChild(declaration);

	XMLElement *root=doc.NewElement("lib");
	doc.InsertEndChild(root);
	
	return doc.SaveFile(lib_path);
}

//写入文件
void RssReader::dump(const char* lib_path)
{
	int ret=create_pagelib(lib_path);
	if(ret)
	{
		cout << "Failed to create pagelib.dat ." << endl;
		return;
	}
	XMLDocument doc;
	ret = doc.LoadFile(lib_path);
	if(ret)
	{
		cout << "load file pagelib.dat failed." << endl;
		return ;
	}

	XMLElement *rootNode = doc.RootElement();
	
	for(size_t i=0;i!=_rss.size();++i)
	{
		XMLElement *docNode=doc.NewElement("doc");
		rootNode->InsertEndChild(docNode);

		XMLElement *docIdNode=doc.NewElement("docid");
		stringstream idss;
		idss << i;
		XMLText *docidText=doc.NewText(idss.str().c_str());
		docIdNode->InsertEndChild(docidText);
		docNode->InsertEndChild(docIdNode);
		
		XMLElement *docTitleNode=doc.NewElement("title");
		XMLText *docTitleText=doc.NewText(_rss.at(i).title.c_str());
		docTitleNode->InsertEndChild(docTitleText);
		docNode->InsertEndChild(docTitleNode);
	
		XMLElement *docLinkNode=doc.NewElement("link");
		XMLText *docLinkText=doc.NewText(_rss.at(i).link.c_str());
		docLinkNode->InsertEndChild(docLinkText);
		docNode->InsertEndChild(docLinkNode);
	
		XMLElement *docContentNode=doc.NewElement("Content");
		XMLText *docContentText=doc.NewText(_rss.at(i).content.c_str());
		docContentNode->InsertEndChild(docContentText);
		docNode->InsertEndChild(docContentNode);
	}

	if(!doc.SaveFile(lib_path))
		cout << "dump sucessful!!" << endl;
	else
		cout << "failed to dump" << endl;

}
