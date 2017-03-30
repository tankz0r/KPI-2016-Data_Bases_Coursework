#ifndef FILTERWINDOW_H
#define FILTERWINDOW_H

#include <QDialog>
#include <QDebug>
#include <QTableWidget>
#include <QtSql>

namespace Ui {
class FilterWindow;
}

class FilterWindow : public QDialog
{
    Q_OBJECT

public:
    explicit FilterWindow(QWidget *parent = 0, QString tableName1 = "",
                          QSqlDatabase db = QSqlDatabase(),
                          QTableWidget *table = new QTableWidget());
    ~FilterWindow();

private:
    Ui::FilterWindow *ui;
    QString tableName;
    QSqlDatabase db;
    QTableWidget *table;
private slots:
    void accept();
};

#endif // FILTERWINDOW_H
