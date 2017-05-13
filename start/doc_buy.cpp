#include "doc_buy.h"
#include "ui_doc_buy.h"

doc_buy::doc_buy(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::doc_buy)
{
    ui->setupUi(this);
}

doc_buy::~doc_buy()
{
    delete ui;
    ui->comboBox->addItem(0);
    ui->comboBox->addItem(5);
    ui->comboBox->addItem(10);
}
