#ifndef CONTAINER_H
#define CONTAINER_H

#include <QMainWindow>
#include <QDialog>
#include "login.h"

namespace Ui {
class container;
}

class container : public QMainWindow
{
    Q_OBJECT

public:
    QSqlDatabase mydb;
    void connClose()
    {
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);

    }

    bool connOpen()
    {
        QString servername = "happycake.cme8l9aci84u.eu-central-1.rds.amazonaws.com";
        QString dbname = "DenysPart";
        mydb = QSqlDatabase::addDatabase("QPSQL");
        mydb.setConnectOptions();
        mydb.setDatabaseName(dbname);
        mydb.setHostName(servername);
        mydb.setUserName("wolterlw");
        mydb.setPassword("PGhc-wolodzya135");
        if(mydb.open())
        {
             qDebug() << dbname;
             return true;

        }
        else
        {
            qDebug() << "Error " << mydb.lastError().text();
            return false;
        }


    }


public:
    explicit container(QWidget *parent = 0);
    ~container();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::container *ui;
};

#endif // CONTAINER_H
