#ifndef XMLELEMENT_H
#define XMLELEMENT_H

#include <vector>
#include "xmlcontent.h"
#include "xmlvariable.h"

class XMLElement : public XMLContent
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
std::ostream& operator<<(std::ostream &os,XMLElement elem);
#endif
