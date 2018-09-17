#include "move.h"
#include "ui_move.h"

move::move(QWidget *parent, QSqlDatabase db1) :
    QDialog(parent),
    ui(new Ui::move)
{
    ui->setupUi(this);
    mydb = db1;
}

move::~move()
{
    delete ui;
}
