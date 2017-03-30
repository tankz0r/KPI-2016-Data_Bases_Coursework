#ifndef EMPLOYEEWINDOW_H
#define EMPLOYEEWINDOW_H

#include <QDialog>
#include <QtSql>
#include <QCompleter>
#include <QTableWidget>

namespace Ui {
class EmployeeWindow;
}

class EmployeeWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EmployeeWindow(QWidget *parent = 0, QSqlDatabase db = QSqlDatabase());
    ~EmployeeWindow();

private:
    Ui::EmployeeWindow *ui;
    QSqlDatabase db;
    QStringList slEmp;
    int fillTable(QTableWidget *tab, QString query);

private slots:
    int refreshPosition();
    void accept();
    int showAdd();
    int showRefresh();
    int refreshEmpl();
    int chooseEmpl(int, int);
};

#endif // EMPLOYEEWINDOW_H
