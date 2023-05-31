#ifndef XMLVARIABLE_H
#define XMLVARIABLE_H

#include "xmlcontent.h"

class XMLVariable : XMLContent
{
    string _value;
public:
    XMLVariable();
    XMLVariable(string);

};

#endif // XMLVARIABLE_H
