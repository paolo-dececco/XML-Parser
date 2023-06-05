#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "xmlelement.h"
#include "xmlvariable.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    XMLElement ActiveFile;
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void importXML(QString);
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
