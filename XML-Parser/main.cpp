#include <iostream>
#include "xmlparser.h"
#include "xmlelement.h"

using namespace std;

int main()
{
    string filePath = "C:\\Users\\dececco\\Documents\\GitHub\\XML-Parser\\XML-Parser\\cd_catalog.xml";
    XMLParser parser;
    string xmlRaw = parser.ReadXML(filePath);
    XMLElement xml = parser.XMLParse(xmlRaw);
    cout << "Parse -> OK" << endl;
    cout << xml <<endl;
    return 0;
}
