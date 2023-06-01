#ifndef XMLVARIABLE_H
#define XMLVARIABLE_H

#include "xmlcontent.h"
#include <iostream>

class XMLVariable : public XMLContent
{
    string _value;
public:
    XMLVariable();
    XMLVariable(string);
    XMLVariable(string,string);
    const string getValue() const;
    void setValue(string);
};
std::ostream& operator<<(std::ostream &os,XMLVariable variable);


#endif // XMLVARIABLE_H
