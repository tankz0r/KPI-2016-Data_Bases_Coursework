#ifndef MOVE_H
#define MOVE_H

#include <QDialog>
#include "mainform.h"

namespace Ui {
class move;
}

class move : public QDialog
{
    Q_OBJECT

public:
    explicit move(QWidget *parent = 0, QSqlDatabase db1 = QSqlDatabase());
    ~move();

private:
    Ui::move *ui;
    QSqlDatabase mydb;
};

#endif // MOVE_H
