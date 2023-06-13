#ifndef XMLCONTENT_H
#define XMLCONTENT_H

#include "xmlparser_types.h"
#include <string>


using namespace std;

class XMLContent
{
protected:
    string _tagName;
    string _id;
    
public:
    XML_API XMLContent();
    XML_API ~XMLContent();
    XML_API XMLContent(string tagName);
    XML_API const ADDCALL string getTagName() const;
    XML_API const ADDCALL string getId() const;
    XML_API void ADDCALL setTagName(string);
};

#endif // XMLCONTENT_H
