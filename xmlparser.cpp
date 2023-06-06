#include "xmlparser.h"
#include <fstream>
#include <iostream>


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
    std::cout << "Reading -> OK" << endl;
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
    if (start>=tl.end)
        return false;
    pos=raw_xml.find(">",start);
    if (pos>=tl.end)
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

string XMLParser::getStringFromTL(const string& raw_xml, const TextLimit tl){

    return raw_xml.substr(tl.start,tl.end-tl.start-2);
}

TextLimit XMLParser::getTLContent(const string& raw_xml, const string& tag){
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
    return TextLimit(start,--pos);
}

string XMLParser::getFirstTag(const string& text) const{
    unsigned int start = 0, pos;

    start=text.find("<",start);
    start++; // Skip <
    if (start==string::npos)
        throw tag_not_found_exception();
    pos=text.find(">",start);
    if (pos==string::npos)
        throw tag_not_found_exception();
    // Posso usare < nel testo normale
    while (text.find("<",start)==string::npos)
            start=text.find("<",start);
    return text.substr(start,pos-start);

}

string XMLParser::getFirstTagfromPos(const string& text,const unsigned int pos) const{
    unsigned int start = pos, posix;

    start=text.find("<",start);
    start++;
    if (start==string::npos)
            throw tag_not_found_exception();
    posix=text.find(">",start);
    if (posix==string::npos)
            throw tag_not_found_exception();
    // Posso usare < nel testo normale
    while (text.find("<",start)==string::npos)
            start=text.find("<",start);
    return text.substr(start,posix-start);

}

XMLElement XMLParser::XMLParse(const string& raw_xml){
    unsigned int pos=0;
    string tag_name = getFirstTag(raw_xml);
    if (tag_name.find("?",pos)!=string::npos)   //skip xmlVersion
            pos=tag_name.length()+2;
    tag_name = getFirstTagfromPos(raw_xml,pos);
    XMLElement root_Elem(tag_name);
    TextLimit root_xml_content = getTLContent(raw_xml,tag_name);
    pos=root_xml_content.start;
    TextLimit xml_content;
    while (pos<root_xml_content.end) {
        tag_name = getFirstTagfromPos(raw_xml,pos);
        xml_content=getTLContent(raw_xml.substr(pos),tag_name)+pos;
        if (HasChildTL(raw_xml,xml_content)) {
            XMLElement child_elem = _XMLParserHelper(getStringFromTL(raw_xml,xml_content),tag_name);
            root_Elem.AddChildElement(child_elem);
        }
        else {
            XMLVariable variable_elem(tag_name,getContent(raw_xml.substr(pos),tag_name));
            root_Elem.AddVariable(variable_elem);
        }
        pos=xml_content.end+tag_name.length()+4;
    }
    return root_Elem;
}

XMLElement XMLParser::_XMLParserHelper(const string raw_xml,const string tagName){
    // Used for building XMLElement
    unsigned int pos=0;
    XMLElement root(tagName);
    string tag_name;
    TextLimit xml_content;
    while (pos<raw_xml.length()) {
        tag_name = getFirstTagfromPos(raw_xml,pos);
        xml_content=getTLContent(raw_xml.substr(pos),tag_name)+pos;
        if (HasChildTL(raw_xml,xml_content)) {
            XMLElement child_elem = _XMLParserHelper(getStringFromTL(raw_xml,xml_content),tag_name);
            root.AddChildElement(child_elem);
        }
        else {
            XMLVariable variable_elem(tag_name,getContent(raw_xml.substr(pos),tag_name));
            root.AddVariable(variable_elem);
        }
        pos=xml_content.end+tag_name.length()+4;
    }
    return root;
}
