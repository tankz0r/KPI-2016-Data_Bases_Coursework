#ifndef MAINFORM_H
#define MAINFORM_H

#include <QDialog>
#include "login.h"
#include "counteragent.h"

namespace Ui {
class MainForm;
}

class MainForm : public QDialog
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
    explicit MainForm(QWidget *parent = 0);
    ~MainForm();

private slots:
    void on_pushButton_clicked();

    void on_Button_buy_clicked();

private:
    Ui::MainForm *ui;
};

#endif // MAINFORM_H
