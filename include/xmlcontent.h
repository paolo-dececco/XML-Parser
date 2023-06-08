#ifndef XMLCONTENT_H
#define XMLCONTENT_H

#ifdef _WIN32
    #ifdef XMLPARSER_DLL_EXPORT
        #define XML_API __declspec(dllexport)
    #else
        #define XML_API __declspec(dllimport)
    #endif
#else
    #define XML_API
#endif

#include <string>

using namespace std;

class XML_API XMLContent
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
