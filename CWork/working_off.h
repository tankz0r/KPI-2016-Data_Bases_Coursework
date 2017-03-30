#ifndef WORKING_OFF_H
#define WORKING_OFF_H

#include <QDialog>
#include <QtSql>
#include <QCompleter>

namespace Ui {
class working_off;
}

class working_off : public QDialog
{
    Q_OBJECT

public:
    explicit working_off(QWidget *parent = 0, QSqlDatabase db = QSqlDatabase());
    ~working_off();

private:
    Ui::working_off *ui;
    QSqlDatabase db;
    QStringList slEmp;
private slots:
    void accept();
};

#endif // WORKING_OFF_H
