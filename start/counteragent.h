#ifndef COUNTERAGENT_H
#define COUNTERAGENT_H

#include <QDialog>
#include "mainform.h"

namespace Ui {
class CounterAgent;
}

class CounterAgent : public QDialog
{
    Q_OBJECT

public:
    explicit CounterAgent(QWidget *parent = 0,  QSqlDatabase db1 = QSqlDatabase());
    ~CounterAgent();

private slots:
    void on_pushButton_3_clicked();

private:
    Ui::CounterAgent *ui;
    QSqlDatabase mydb;
};

#endif // COUNTERAGENT_H
