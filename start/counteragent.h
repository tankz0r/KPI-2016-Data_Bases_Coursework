#ifndef COUNTERAGENT_H
#define COUNTERAGENT_H

#include <QDialog>
#include "mainform.h"
#include <QStandardItemModel>
#include <QStandardItem>
#include <QObject>

namespace Ui {
class CounterAgent;
}

class CounterAgent : public QDialog
{
    Q_OBJECT

public:
    //QString b;
    explicit CounterAgent(QWidget *parent = 0,  QSqlDatabase db1 = QSqlDatabase());
    //QString cname;
    int fillTable(QTableWidget *tab, QString query);
    ~CounterAgent();

private slots:
    //void Myg();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

    //void on_pushButton_clicked();

    void onButtonSend(QString text);

signals:
   void sendData(QString word);




private:
    Ui::CounterAgent *ui;
    QSqlDatabase mydb;
};

#endif // COUNTERAGENT_H
