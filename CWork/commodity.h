#ifndef COMMODITY_H
#define COMMODITY_H

#include <QDialog>
#include <QtSql>
#include <QCompleter>

namespace Ui {
class commodity;
}

class commodity : public QDialog
{
    Q_OBJECT

public:
    explicit commodity(QWidget *parent = 0, QSqlDatabase db1 = QSqlDatabase());
    ~commodity();

private:
    Ui::commodity *ui;
    QSqlDatabase db;
    QStringList slComm;
    bool newMode = true;

private slots:
    int showAdd();
    int showDelete();
    void accept();
    int addComm();
};

#endif // COMMODITY_H
