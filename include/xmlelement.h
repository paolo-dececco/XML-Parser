#ifndef XMLELEMENT_H
#define XMLELEMENT_H

#ifdef _WIN32
    #ifdef XMLPARSER_DLL_EXPORT
        #define XML_API __declspec(dllexport)
    #else
        #define XML_API __declspec(dllimport)
    #endif
#else
    #define XML_API
#endif

#include <vector>
#include "xmlcontent.h"
#include "xmlvariable.h"

class XML_API XMLElement : public XMLContent
{
private:
    vector<XMLElement> _childrens;
    vector<XMLVariable> _variables;

public:
    XMLElement();
    XMLElement(string);

    // Gets
    vector<XMLElement> ChildElem() const;
    vector<XMLVariable> Variables() const;

    // Sets
    void AddChildElement(XMLElement& c);
    void AddVariable(XMLVariable& v);
    bool isRoot;
};
XML_API std::ostream& operator<<(std::ostream &os,XMLElement elem);
#endif
