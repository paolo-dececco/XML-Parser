#ifndef XMLCONTENT_H
#define XMLCONTENT_H

#include <string>

using namespace std;

class XMLContent
{
protected:
    string _tagName;
    string _id;
public:
    XMLContent();
    XMLContent(string tagName);
    const string getTagName() const;
    void setTagName(string);
};

#endif // XMLCONTENT_H
