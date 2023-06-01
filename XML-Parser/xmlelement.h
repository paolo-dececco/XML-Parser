#ifndef XMLELEMENT_H
#define XMLELEMENT_H

#include <vector>
#include "xmlcontent.h"
#include "xmlvariable.h"

class XMLElement : XMLContent
{
private:
    vector<XMLElement> _childrens;
    vector<XMLVariable> _variables;

public:
    XMLElement();
    void AddChildElement();
    void AddVariable();

    // Gets
    vector<XMLElement> ChildElem() const;
    vector<XMLVariable> Variables() const;

    // Sets
    void appendChild(XMLElement& c);
    void appendVar(XMLVariable& v);
    bool isRoot;

};
#endif
