#ifndef MAINFORM_H
#define MAINFORM_H


#include <QDialog>
#include <QDesktopWidget>
#include "login.h"
#include "ui_documbuy.h"
#include "documbuy.h"
#include "counteragent.h"
#include "movedoc.h"
#include "qungoods.h"
#include "errorwindow.h"
#include "enhancedtablewidget.h"

#include <fstream>
#include <iostream>


namespace Ui {
class MainForm;
}

class MainForm : public QDialog
{
    Q_OBJECT


public:
    QSqlDatabase mydb;
    void connClose();
    bool connOpen();
    int fillTable(QTableWidget *tab, QString query);
    int fillTable(QTableWidget *tab, QSqlQuery &sq);
    void centerwindow();


public:
    explicit MainForm(QWidget *parent = 0, QString login = "admin");
    ~MainForm();


public slots:
    void userclicked();

private slots:
    void on_pushButton_2_clicked();
    void on_Button_buy_clicked();

    void on_pushButton_11_clicked();

    void on_Button_add_CA_3_clicked();

    void on_pushButton_13_clicked();

    //void on_pushButton_12_clicked();

    //void on_pushButton_clicked();

    //void on_pushButton_6_clicked();

    void on_Button_add_CA_4_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_9_clicked();

    void on_tableWidget_4_itemDoubleClicked(QTableWidgetItem *item);

    void on_pushButton_clicked();

private:
    Ui::MainForm *ui;
    int initcash();
    int initmanager();
    QString getRole(QString login);
};

#endif // MAINFORM_H
