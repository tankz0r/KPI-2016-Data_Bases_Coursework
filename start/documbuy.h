#ifndef DOCUMBUY_H
#define DOCUMBUY_H

#include <QDialog>
#include "mainform.h"
#include <QObject>
#include <QShortcut>

namespace Ui {
class documbuy;
}

//Ui::documbuy* doc;


class documbuy : public QDialog
{
    Q_OBJECT

public:
    explicit documbuy(QWidget *parent = 0, QSqlDatabase db1 = QSqlDatabase(), QString nname = "");
    //static QString statVar ;
    ~documbuy();
    int number =0;


public slots:
    void on_pushButton_2_add_next_commodity_clicked();
    void on_pushButton_clicked();
    void recieveData(QString word);
    void recieveDataQuan(QString word);
    //void userclicked();

private slots:
    void on_tableWidget_itemDoubleClicked(QTableWidgetItem *item);
    void on_pushButton_ok_clicked();

    void on_addButton_clicked();

private:
    Ui::documbuy *ui;
    QSqlDatabase mydb;
    QShortcut       *keyF11;


};

//QString documbuy::statVar = "";



#endif // DOCUMBUY_H
