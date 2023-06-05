#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "xmlparser.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::importXML(QString fileName){
    XMLParser parser;
    try {
    string rawXML = parser.ReadXML(fileName.toStdString());
    }
    catch (...) {
    ui->errorFilePathLabel->text()="File non valido!";
    }
}
