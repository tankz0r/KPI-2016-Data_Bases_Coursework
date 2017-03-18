#include "login.h"
#include <QApplication>

int main(int argc, char *argv[])
{
//ctr+f3
    QApplication a(argc, argv);
    Login w;
    w.show();

    return a.exec();
}
