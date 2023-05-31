#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <stack>
#include <string>

using namespace std;

class xml_file_read_exception{};

class tag_not_found_exception{};

class bad_xml_exception{};

class XMLParser
{
    template<typename T> bool stack_finder(stack<T> stk, T name);
    bool HasChild(const string& raw_xml);
public:
    XMLParser();
    string ReadXML(const string filename);
    stack<string> enumTags(const string& xml) const;
    string isolateTags(const string& text);
};

#endif // XMLPARSER_H
