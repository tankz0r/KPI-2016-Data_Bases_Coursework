#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent, QString El) :
    QDialog(parent),
    ui(new Ui::LoginWindow)
{
    setModal(true);
    ui->setupUi(this);
    ui->ErrorLabel->setText(El);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}
QString LoginWindow::getLogin()
{
    return ui->loginField->text();
}
QString LoginWindow::getPw()
{
    return ui->pwField->text();
}
QString LoginWindow::getIP()
{
    return ui->pwField_2->text();
}
QString LoginWindow::getPort()
{
    return ui->pwField_3->text();
}
