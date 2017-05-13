#ifndef QUNGOODS_H
#define QUNGOODS_H

#include <QDialog>
#include "mainform.h"
#include <QObject>
#include <QShortcut>

namespace Ui {
class qungoods;
}

class qungoods : public QDialog
{
    Q_OBJECT

public:
    explicit qungoods(QWidget *parent = 0, QSqlDatabase db1 = QSqlDatabase());
    ~qungoods();
     int fillTable(QTableWidget *tab, QSqlQuery &sq);

private slots:
    void on_pushButton_11_clicked();

    void on_pushButton_9_clicked();

    void onButtonSend(QString text);

    void on_pushButton_clicked();

signals:
   void sendData(QString word);

private:
    Ui::qungoods *ui;
    QSqlDatabase mydb;
    QShortcut       *keyF11;
    QShortcut       *keyF10;

};

#endif // QUNGOODS_H
