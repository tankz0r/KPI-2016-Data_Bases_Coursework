#include "mainwindow.h"
#include "loginwindow.h"
#include "orderwindow.h"
#include "employeewindow.h"
#include <QApplication>
#include <QDialog>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();
    return a.exec();
}
