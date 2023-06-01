#include "xmlelement.h"

XMLElement::XMLElement()
{

}

vector<XMLElement> XMLElement::ChildElem() const {
    return _childrens;
}
vector<XMLVariable> XMLElement::Variables() const{
    return _variables;
}

void XMLElement::appendChild(XMLElement& c){
    _childrens.push_back(c);
}
void XMLElement::appendVar(XMLVariable& v){
    _variables.push_back(v);
}
