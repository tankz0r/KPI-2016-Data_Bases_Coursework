#ifndef INFORMATIONWINDOW_H
#define INFORMATIONWINDOW_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class InformationWindow;
}

class InformationWindow : public QDialog
{
    Q_OBJECT

public:
    explicit InformationWindow(QWidget *parent = 0, QSqlDatabase db = QSqlDatabase(),
                               QString caName= "");
    ~InformationWindow();

private:
    Ui::InformationWindow *ui;
};

#endif // INFORMATIONWINDOW_H
