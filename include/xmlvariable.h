#ifndef XMLVARIABLE_H
#define XMLVARIABLE_H

#include "xmlcontent.h"
#include "xmlparser_types.h"
#include <iostream>

class XMLElement;

class XMLVariable : public XMLContent
{
    string _value;
    XMLElement* _parent;
public:
    XML_API XMLVariable();
    XML_API ~XMLVariable();
    XML_API XMLVariable(XMLElement*,string);
    XML_API XMLVariable(XMLElement*,string,string);

    XML_API const XMLElement*  ADDCALL getParent() const;
    XML_API const string ADDCALL getValue() const;
    XML_API void ADDCALL setValue(string);
    XML_API void ADDCALL setParent(XMLElement*);
    XML_API XMLVariable* ADDCALL operator*(void); 
};
std::ostream& operator<<(std::ostream &os,XMLVariable variable);


#endif // XMLVARIABLE_H
