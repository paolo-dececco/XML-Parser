#include "xmlcontent.h"

XMLContent::XMLContent() {
    XMLContent("");
}
    
XMLContent::~XMLContent() {

}

XMLContent::XMLContent(string tagName) : _tagName(tagName) {
}

const string XMLContent::getTagName() const {
    return _tagName;
}

void XMLContent::setTagName(string tagName) {
    _tagName = tagName;
}

const string XMLContent::getId() const{
    return _id;
}