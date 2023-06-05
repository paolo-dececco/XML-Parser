#include <iostream>
#include "xmlparser.h"
#include "xmlelement.h"
#include "mainwindow.h"
#include <QApplication>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    MainWindow win;
    win.show();
    string filePath = "C:\\Users\\dececco\\Documents\\GitHub\\XML-Parser\\XML-Parser\\plant_catalog.xml";
    XMLParser parser;
    string xmlRaw = parser.ReadXML(filePath);
    cout << "Read -> OK" << endl;
    XMLElement xml = parser.XMLParse(xmlRaw);
    cout << "Parse -> OK" << endl;
    cout << xml <<endl;
    return app.exec();
}
