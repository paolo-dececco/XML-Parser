#include "xmlelement.h"

XMLElement::XMLElement()
{

}

XMLElement::XMLElement(string tag)
{
    setTagName(tag);
}

vector<XMLElement> XMLElement::ChildElem() const {
    return _childrens;
}
vector<XMLVariable> XMLElement::Variables() const{
    return _variables;
}

void XMLElement::AddChildElement(XMLElement& c){
    _childrens.push_back(c);
}
void XMLElement::AddVariable(XMLVariable& v){
    _variables.push_back(v);
}

std::ostream& operator<<(std::ostream &os,XMLElement elem){
    os << elem.getTagName() << ": [" << endl;

    for (XMLElement& c : elem.ChildElem()) {
        os << "\t " << c << endl;
    }

    for (XMLVariable& v : elem.Variables()) {
        os << "\t " << v.getTagName() << ": "<< v.getValue() << endl;
    }
    os <<"]";
    return os;
}
