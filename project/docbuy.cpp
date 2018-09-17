#include "docbuy.h"
#include "ui_docbuy.h"

docbuy::docbuy(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::docbuy)
{
    ui->setupUi(this);
}

docbuy::~docbuy()
{
    delete ui;
    ui->comboBox->addItem(0);
    ui->comboBox->addItem(5);
    ui->comboBox->addItem(10);
}
