#ifndef MOVEDOC_H
#define MOVEDOC_H

#include <QDialog>
#include "mainform.h"
#include <QMessageBox>

namespace Ui {
class movedoc;
}

class movedoc : public QDialog
{
    Q_OBJECT

public:
    explicit movedoc(QWidget *parent = 0, QSqlDatabase db1 = QSqlDatabase());
    ~movedoc();
     int number =0;

public slots:
    void recieveDataQuan(QString word);
    //void userclicked();

private slots:
    void on_pushButton_2_add_next_commodity_clicked();

    void on_tableWidget_itemDoubleClicked(QTableWidgetItem *item);

    void on_addButton_clicked();

    void on_pushButton_ok_clicked();

private:
    Ui::movedoc *ui;
    QSqlDatabase mydb;
    //int n = 0;
};

#endif // MOVEDOC_H
