#include "documentbuy.h"
#include "ui_documentbuy.h"

DocumentBuy::DocumentBuy(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DocumentBuy)
{
    ui->setupUi(this);
}

DocumentBuy::~DocumentBuy()
{
    delete ui;
}
