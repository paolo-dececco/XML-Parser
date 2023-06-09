#ifndef XMLVARIABLE_H
#define XMLVARIABLE_H

#ifdef _WIN32
    #ifdef XMLPARSER_DLL_EXPORT
        #define XML_API __declspec(dllexport)
    #else
        #define XML_API __declspec(dllimport)
    #endif
#else
    #define XML_API
#endif

#include "xmlcontent.h"
#include <iostream>

class XMLElement;

class XML_API XMLVariable : public XMLContent
{
    string _value;
    XMLElement* _parent;
public:
    XMLVariable();
    XMLVariable(XMLElement*,string);
    XMLVariable(XMLElement*,string,string);

    const XMLElement* getParent() const;
    const string getValue() const;
    void setValue(string);
    void setParent(XMLElement*);
    XMLVariable* operator*(void); 
};
XML_API std::ostream& operator<<(std::ostream &os,XMLVariable variable);


#endif // XMLVARIABLE_H
