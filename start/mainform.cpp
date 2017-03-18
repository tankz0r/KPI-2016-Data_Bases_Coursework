#include "mainform.h"
#include "ui_mainform.h"

MainForm::MainForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainForm)
{
    ui->setupUi(this);
//    if (connOpen())
//        qDebug() << "work";
//    connClose();
}

MainForm::~MainForm()
{
    delete ui;
}

void MainForm::on_Button_buy_clicked()
{
    CounterAgent ca;
    ca.setModal(true);
    ca.exec();
}
