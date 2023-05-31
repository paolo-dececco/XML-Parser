#include "xmlcontent.h"

XMLContent::XMLContent() : _tagName("") {}

XMLContent::XMLContent(string tagName) : _tagName(tagName) {}

const string XMLContent::getTagName() const {
    return _tagName;
}

void XMLContent::setTagName(string tagName) {
    _tagName = tagName;
}
