#ifndef ORDERWINDOW_H
#define ORDERWINDOW_H

#include <QDialog>
#include <QtSql>
#include <QCloseEvent>
#include <QCompleter>
namespace Ui {
class OrderWindow;
}

class OrderWindow : public QDialog
{
    Q_OBJECT

public:
    explicit OrderWindow(QWidget *parent = 0, QSqlDatabase db = QSqlDatabase());
    ~OrderWindow();

private:
    Ui::OrderWindow *ui;
    QSqlDatabase db;
    int refreshCA();
    int clearCA();

private slots:
    void accept();
    int showCA();
    int showPE();
    int showLE();
    int addCA();
    int submitComm();
};

#endif // ORDERWINDOW_H
