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
    size_t start=0,pos;
    start=raw_xml.find("<",start);
    if (start>raw_xml.size())
        return false;
    pos=raw_xml.find(">",start);
    if (pos>raw_xml.size())
        return false;
    return true;
}

bool XMLParser::HasChildTL(const string& raw_xml, const TextLimit& tl){
    size_t start=tl.start,pos;
    start=raw_xml.find("<",start);
    if (start>=tl.end)
        return false;
    pos=raw_xml.find(">",start);
    if (pos>=tl.end)
        return false;
    return true;
}
// -----! NOT IMPLEMENTED ----
stack<string> XMLParser::enumTags(const string& raw_xml) const {
    stack<string> tagStk;
    tagStk.push(getFirstTag(raw_xml));

    return tagStk;
}

string XMLParser::getContent(const string& raw_xml, const string& tag){
    TextLimit TL=getTextLimit(raw_xml,tag);
    cout << TL.toString(raw_xml) << endl;
    return TL.toString(raw_xml);
}

TextLimit XMLParser::getTextLimit(const string& raw_xml, const string& tag){
    size_t start, pos=0;

    //Begin tag
    start=raw_xml.find("<"+tag+">",pos);
    if (start>raw_xml.size()) {// Tag not found
        cout << " get Text Limit start" << endl;
        throw tag_not_found_exception();}
    start=raw_xml.find(">",start);
    start++;

    pos=raw_xml.find("</"+tag,start);
    if (pos>raw_xml.size()) {//if pos==string::npos> 
            cout << "get Text Limit pos" << endl;
        throw bad_xml_exception();}
    return TextLimit(start,pos);
}

string XMLParser::getFirstTag(const string& text) const{
    return getNextTag(text,0);
}

string XMLParser::getNextTag(const string& text,const size_t pos) const{
    size_t start = pos, posix;

    start=text.find("<",start);
    start++;
    if (start>text.size()) {
                cout << "get Next Tag start" << endl;
            throw tag_not_found_exception();}
    posix=text.find(">",start);
    if (posix>text.size()) {
                        cout << "get next tag pos" << endl;
            throw tag_not_found_exception();}
    return text.substr(start,posix-start);
}

XMLElement XMLParser::XMLParse(const string& raw_xml){
    size_t pos=0;
    if (raw_xml.find("<?",pos)<=raw_xml.size())   //skip xmlVersion
        pos=raw_xml.find("?>",pos)+2;
    string tag_name = getNextTag(raw_xml,pos);
    XMLElement root_Elem = _XMLParserHelper(getContent(raw_xml,tag_name), tag_name);
    return root_Elem;
}

XMLElement XMLParser::_XMLParserHelper(const string& raw_xml,const string tagName){
    // Used for building XMLElement
    cout << "start _XMLParserHelper for tag:" << tagName << endl;

    XMLElement root(tagName);

    size_t pos=0;
    string tag_name; 
    TextLimit xml_content;
    while ( pos<raw_xml.size() && FindFirstTag(raw_xml.substr(pos))!=string::npos) {
        tag_name = getNextTag(raw_xml,pos);
        cout << tag_name << endl;
        xml_content=getTextLimit(raw_xml.substr(pos),tag_name)+pos;
        if (HasChildTL(raw_xml,xml_content)) {
            XMLElement child_elem = _XMLParserHelper(xml_content.toString(raw_xml),tag_name);
            root.AddChildElement(child_elem);
        }
        else {
            XMLVariable variable_elem(*root,tag_name,getContent(raw_xml.substr(pos),tag_name));
            root.AddVariable(variable_elem);
        }

        pos=raw_xml.find(">",xml_content.end)+1;
        cout << pos << endl;
    }
    cout << "exit _XMLParserHelper for tag:" << tagName << endl;
    return root;
}

size_t XMLParser::FindFirstTag(const string& raw_xml) {
    size_t start=0, posix;

    start=raw_xml.find("<",start);

    posix=raw_xml.find(">",start);
    if (posix!=string::npos)
        return start;
    return posix;
}
