

#ifndef XMLELEMENT_H
#define XMLELEMENT_H

#include <vector>
#include "xmlparser_types.h"
#include "xmlcontent.h"
#include "xmlvariable.h"

class XMLElement : public XMLContent
{
private:
    vector<XMLElement> _childrens;
    vector<XMLVariable> _variables;
    XMLElement* _parent;
    static unsigned int current_xmlel_id;

public:
    XML_API XMLElement();
    XML_API ~XMLElement();
    XML_API XMLElement(string);
    XML_API XMLElement(XMLElement*,string);

    // Gets
    XML_API vector<XMLElement> ADDCALL ChildElem() const;
    XML_API vector<XMLVariable> ADDCALL getVariables() const;

    // Sets
    XML_API void ADDCALL AddChildElement(XMLElement& c);
    XML_API void ADDCALL AddVariable(XMLVariable&);

    XML_API const unsigned int ADDCALL getChildrenCount() const;
    XML_API unsigned int ADDCALL getVariablesCount() const;

    XML_API const ADDCALL XMLElement* getParent() const;
    XML_API void ADDCALL setParent(XMLElement*);

    XML_API bool ADDCALL hasChild() const;
    XML_API bool ADDCALL isRoot();
    XML_API void ADDCALL clear();

    XML_API XMLElement* ADDCALL FindById(string);
    XML_API XMLVariable* ADDCALL FindVariableById(string);
    XML_API XMLElement* ADDCALL operator*(void); 
};
std::ostream& operator<<(std::ostream &os,XMLElement elem);
#endif
