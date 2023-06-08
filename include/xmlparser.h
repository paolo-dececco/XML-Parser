
#ifdef _WIN32
    #ifdef XMLPARSER_DLL_EXPORT
        #define XML_API __declspec(dllexport)
    #else
        #define XML_API __declspec(dllimport)
    #endif
#else
    #define XML_API
#endif

/* Define calling convention*/
#define ADDCALL __cdecl

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

    TextLimit() : start(0),end(0) {}
    TextLimit(unsigned int &s, unsigned int &e) : start(s),end(e) {}
    TextLimit operator+(int pos) {return TextLimit(start+=pos,end+=pos); }
};


class XMLParser
{
    bool HasChild(const string& raw_xml);
    bool HasChildTL(const string& raw_xml, const TextLimit& tl);
    string getStringFromTL(const string& raw_xml, const TextLimit tl);
    XMLElement _XMLParserHelper(const string raw_xml,const string tagName);
    string getContent(const string& raw_xml, const string& tag);
    TextLimit getTLContent(const string& raw_xml, const string& tag);
    stack<string> enumTags(const string& xml) const;
    string getFirstTag(const string& text) const;
    string getFirstTagfromPos(const string& text,const unsigned int pos) const;
public:
    XML_API XMLParser();
    XML_API string ReadXML(const string filename);
    XML_API XMLElement XMLParse(const string& raw_xml);
};
#endif // XMLPARSER_H
