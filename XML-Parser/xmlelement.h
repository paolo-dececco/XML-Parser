#ifndef XMLELEMENT_H
#define XMLELEMENT_H

#include <vector>
#include "xmlcontent.h"
#include "xmlvariable.h"

class XMLElement : XMLContent
{
private:
    std::vector<XMLElement> _childrens;
    std::vector<XMLVariable> _variables;

public:
    XMLElement();
    void AddChildElement();
    void AddVariable();

    // Gets
    vector<XMLElement> ChildElem();
    vector<XMLVariable> Variables();


};
