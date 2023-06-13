#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <stack>
#include <string>
#include "xmlparser_types.h"
#include "xmlelement.h"
#include "xmlvariable.h"

using namespace std;

class xml_file_read_exception{};

class tag_not_found_exception{};

class bad_xml_exception{};

// size_t = unsigned int

struct TextLimit {
    size_t start;
    size_t end;

    TextLimit() : start(0),end(0) {}
    TextLimit(size_t &s, size_t &e) : start(s),end(e) {}
    TextLimit operator+(int pos) {return TextLimit(start+=pos,end+=pos); }
    inline string toString(const string& text) {return text.substr(start,end-start);}
};


class XMLParser
{
    bool HasChild(const string& raw_xml);
    size_t FindFirstTag(const string& raw_xml);
    bool HasChildTL(const string& raw_xml, const TextLimit& tl);
    XMLElement _XMLParserHelper(const string& raw_xml,const string tagName);
    string getContent(const string& raw_xml, const string& tag);
    TextLimit getTextLimit(const string& raw_xml, const string& tag);
    stack<string> enumTags(const string& xml) const;
    string getFirstTag(const string& text) const;
    string getNextTag(const string& text,const size_t pos) const;
public:
    XML_API ADDCALL XMLParser();
    XML_API string ADDCALL ReadXML(const string filename);
    XML_API XMLElement ADDCALL XMLParse(const string& raw_xml);
};
#endif // XMLPARSER_H
