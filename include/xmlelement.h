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
    XMLElement* _parent;
    static unsigned int current_xmlel_id;

public:
    XMLElement();
    XMLElement(string);
    XMLElement(XMLElement*,string);

    // Gets
    vector<XMLElement> ChildElem() const;
    vector<XMLVariable> getVariables() const;

    // Sets
    void AddChildElement(XMLElement& c);
    const unsigned int getChildrenCount() const;
    unsigned int getVariablesCount() const;
    void setParent(XMLElement*);
    void AddVariable(XMLVariable&);
    bool hasChild() const;
    bool isRoot();
    XMLElement* FindById(string);
    XMLVariable* FindVariableById(string);
    XMLElement* operator*(void); 
};
XML_API std::ostream& operator<<(std::ostream &os,XMLElement elem);
#endif
