#include "xmlvariable.h"

XMLVariable::XMLVariable()
{

}

XMLVariable::XMLVariable(XMLElement* parent, string tag) : _parent(parent),_value("") {
    this->setTagName(tag);
    _id=_parent->getId()+tag;
}

XMLVariable::XMLVariable(XMLElement* parent, string tag,string value) : _parent(parent), _value(value){
    this->setTagName(tag);
    _id=_parent->getId()+tag;
}

const string XMLVariable::getValue() const{
    return _value;
}

void XMLVariable::setValue(string val){
    _value=val;
}

string XMLVariable::getId(){
    return _id;
}

void XMLVariable::setParent(XMLElement* parent) {
    _parent=parent;
}

std::ostream& operator<<(std::ostream &os,XMLVariable variable){
    os << variable.getTagName() << ": " << variable;
    return os;
}

XMLVariable* XMLVariable::operator*(void){
    return this;
}
