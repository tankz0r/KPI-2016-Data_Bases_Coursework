#ifndef MAINFORM_H
#define MAINFORM_H

#include <QDialog>
#include "login.h"
#include "counteragent.h"

namespace Ui {
class MainForm;
}

class MainForm : public QDialog
{
    Q_OBJECT


public:
    QSqlDatabase mydb;
    void connClose();
    bool connOpen();


public:
    explicit MainForm(QWidget *parent = 0, QString role = "admin");
    ~MainForm();

private slots:
    void on_pushButton_2_clicked();
    void on_Button_buy_clicked();

private:
    Ui::MainForm *ui;
    int initHR();
    int initadmin();
};

#endif // MAINFORM_H
