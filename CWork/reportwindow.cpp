#include "reportwindow.h"
#include "ui_reportwindow.h"

ReportWindow::ReportWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReportWindow)
{
    ui->setupUi(this);
}

ReportWindow::~ReportWindow()
{
    delete ui;
}
