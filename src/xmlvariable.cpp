#include "xmlvariable.h"

XMLVariable::XMLVariable()
{

}

XMLVariable::XMLVariable(string tag) : _value("") {
    this->setTagName(tag);
}

XMLVariable::XMLVariable(string tag,string value) : _value(value){
    this->setTagName(tag);
}

const string XMLVariable::getValue() const{
    return _value;
}

void XMLVariable::setValue(string val){
    _value=val;
}

std::ostream& operator<<(std::ostream &os,XMLVariable variable){
    os << variable.getTagName() << ": " << variable;
    return os;
}
