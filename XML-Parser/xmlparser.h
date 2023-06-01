#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <stack>
#include <string>
#include "xmlelement.h"
#include "xmlvariable.h"

using namespace std;

class xml_file_read_exception{};

class tag_not_found_exception{};

class bad_xml_exception{};

struct TextLimit {
    unsigned int start;
    unsigned int end;

    TextLimit(unsigned int &s, unsigned int &e) : start(s),end(e) {};
};

class XMLParser
{
    template<typename T> bool stack_finder(stack<T> stk, T name);
    bool HasChild(const string& raw_xml);
    bool HasChildTL(const string& raw_xml, const TextLimit& tl);
public:
    XMLParser();
    string ReadXML(const string filename);
    string getContent(const string& raw_xml, const string& tag);
    TextLimit getContentLimit(const string& raw_xml, const string& tag);
    stack<string> enumTags(const string& xml) const;
    string getFirstTag(const string& text) const;
    XMLElement XMLParse(const string& raw_xml);
};



#endif // XMLPARSER_H
