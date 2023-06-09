#include "xmlelement.h"

XMLElement::XMLElement()
{
    static unsigned int current_xmlel_id=0;
    _parent=nullptr;
    setTagName("");
    _id+="XMLel-"+std::to_string(current_xmlel_id++);
}

XMLElement::~XMLElement(){
    clear();
}

XMLElement::XMLElement(string tag)
{
    static unsigned int current_xmlel_id=0;
    _parent=nullptr;
    setTagName(tag);
    _id+="XMLel-"+std::to_string(current_xmlel_id++);
}

XMLElement::XMLElement(XMLElement* parent, string tag) {
    _parent=this;
    setTagName(tag);
    _id+="XMLel-"+(this->getId()+"_"+std::to_string(this->getChildrenCount()+1));
}

vector<XMLElement> XMLElement::ChildElem() const {
    return _childrens;
}

vector<XMLVariable> XMLElement::getVariables() const{
    return _variables;
}

void XMLElement::AddChildElement(XMLElement& c){
    c.setParent(this);
    _childrens.push_back(c);
}

const unsigned int XMLElement::getChildrenCount() const{
    return static_cast<unsigned int>(_childrens.size());
}


unsigned int XMLElement::getVariablesCount() const{
    return static_cast<unsigned int>(_variables.size());
}

void XMLElement::AddVariable(XMLVariable& v){
    v.setParent(this);
    _variables.push_back(v);
}

std::ostream& operator<<(std::ostream &os,XMLElement elem){
    os << elem.getTagName() << ": [" << endl;

    for (XMLElement& c : elem.ChildElem()) {
        os << "\t " << c << endl;
    }

    for (XMLVariable& v : elem.getVariables()) {
        os << "\t " << v.getTagName() << ": "<< v.getValue() << endl;
    }
    os <<"]";
    return os;
}

void XMLElement::setParent(XMLElement* parent){
    _parent=parent;
}

bool XMLElement::isRoot() {
    return (_parent==nullptr);
}

XMLElement* XMLElement::operator*(void){
    return this;
}

XMLElement* XMLElement::FindById(string id){
    if (_id==id)
        return this;
    else {
        XMLElement* ptr=nullptr;
        for (XMLElement& c : _childrens) {
            ptr=c.FindById(id);
            if (ptr!=nullptr)
                return ptr;
        }
        return ptr;
    }
}

bool XMLElement::hasChild() const{
    return (_childrens.size()==0);
}


XMLVariable* XMLElement::FindVariableById(string id){
    for (XMLVariable& v : _variables) {
        if (v.getId()==id)
            return &v;
    }
    XMLVariable* ptr=nullptr;
    if (hasChild()) {
        for (XMLElement& c : _childrens) {
            ptr=c.FindVariableById(id);
            if (ptr!=nullptr)
                return ptr;
        }
    }
    return ptr;
}

const XMLElement* XMLElement::getParent() const{
    return _parent;
}

void XMLElement::clear(){
    _childrens.clear();
    _variables.clear();
    _parent=nullptr;
    setTagName("");
}