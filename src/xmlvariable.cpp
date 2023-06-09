#include "xmlvariable.h"
#include "xmlelement.h"

XMLVariable::XMLVariable()
{

}

XMLVariable::XMLVariable(XMLElement* parent, string tag) : _parent(parent),_value("") {
    this->setTagName(tag);
    _id=_parent->getId()+".Var:"+tag;
}

XMLVariable::XMLVariable(XMLElement* parent, string tag,string value) : _parent(parent), _value(value){
    this->setTagName(tag);
    _id=_parent->getId()+".Var:"+tag;
}

const string XMLVariable::getValue() const{
    return _value;
}

void XMLVariable::setValue(string val){
    _value=val;
}

void XMLVariable::setParent(XMLElement* parent) {
    _parent=parent;
}

std::ostream& operator<<(std::ostream &os, XMLVariable variable){
    os << variable.getTagName() << ": " << variable;
    return os;
}

XMLVariable* XMLVariable::operator*(void){
    return this;
}

const XMLElement* XMLVariable::getParent() const{
    return _parent;
}
