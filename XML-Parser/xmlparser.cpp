#include "xmlparser.h"
#include <fstream>

XMLParser::XMLParser()
{

}

string XMLParser::ReadXML(const string filename){
    string raw_file;
    char c;

    std::ifstream f;
    f.open(filename);
    if (f.is_open()){
        while(f.get(c))
            raw_file+=c;
    } else {
        xml_file_read_exception();
    }
    f.close();
    return raw_file;
}

bool XMLParser::HasChild(const string& raw_xml){
    unsigned int start=0,pos;
    start=raw_xml.find("<",start);
    if (start==string::npos)
        return false;
    pos=raw_xml.find(">",start);
    if (pos==string::npos)
        return false;
    return true;
}

bool XMLParser::HasChildTL(const string& raw_xml, const TextLimit& tl){
    unsigned int start=tl.start,pos;
    start=raw_xml.find("<",start);
    if (start==tl.end)
        return false;
    pos=raw_xml.find(">",start);
    if (pos==tl.end)
        return false;
    return true;
}

stack<string> XMLParser::enumTags(const string& raw_xml) const {
    stack<string> tagStk;
    tagStk.push(getFirstTag(raw_xml));

    return tagStk;
}

string XMLParser::getContent(const string& raw_xml, const string& tag){
    unsigned int start, pos=0;

    //Begin tag
    start=raw_xml.find("<"+tag+">",pos);
    if (start==string::npos)
        throw tag_not_found_exception();
    start=raw_xml.find(">",start);
    start++;

    pos=raw_xml.find("</"+tag+">",start);
    if (pos==string::npos)
        throw bad_xml_exception();
    return raw_xml.substr(start,pos-start);
}

TextLimit XMLParser::getContentLimit(const string& raw_xml, const string& tag){
    unsigned int start, pos=0;

    //Begin tag
    start=raw_xml.find("<"+tag+">",pos);
    if (start==string::npos)
        throw tag_not_found_exception();
    start=raw_xml.find(">",start);
    start++;

    pos=raw_xml.find("</"+tag+">",start);
    if (pos==string::npos)
        throw bad_xml_exception();
    return TextLimit(start,pos);
}

string XMLParser::getFirstTag(const string& text) const{
    unsigned int start = 0, pos;

    start=text.find("<",start);
    if (start==string::npos)
        throw tag_not_found_exception();
    pos=text.find(">",start);
    if (pos==string::npos)
        throw tag_not_found_exception();
    // Posso usare < nel testo normale
    while (text.find("<",start)!=string::npos)
            start=text.find("<",start);
    return text.substr(start,pos-start);

}

XMLElement XMLParser::XMLParse(const string& raw_xml){
    unsigned int pos=0;
    string root_name = getFirstTag(raw_xml);
    TextLimit xml_active = getContentLimit(raw_xml,root_name);
    while ()

}
