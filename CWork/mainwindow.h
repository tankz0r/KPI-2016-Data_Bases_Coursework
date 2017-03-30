#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QTableWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QSqlDatabase db;

private:
    Ui::MainWindow *ui;
    QString login;
    QString pw;
    QString ip;
    QString port;
    QSqlTableModel **models;
    int connectUser();
    int checkTable(QString);
    int showLoginWindow();
    QString getRole();
    int initMerchant();
    int initHR();
    int initAdmin();
    int fillTable(QTableWidget *, QString);

private slots:
    int showOrderWindow();
    int showEmployeeWindow();
    int showCommodityWindow();
    int refreshMerch();
    int refreshHR();
    int refreshAdmin(QString tableName = "", QString filter = "");
    int filterAdmin();
    int showFilter();
    int showInfo(int, int);
    int showWoff();
    // int showReportHR();
    // int showReportMerch();
    int addRowAdmin();
    int submitAdmin();
};

#endif // MAINWINDOW_H
