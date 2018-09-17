#ifndef ERRORWINDOW_H
#define ERRORWINDOW_H

#include <QDialog>
#include "mainform.h"

namespace Ui {
class ErrorWindow;
}

class ErrorWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ErrorWindow(QWidget *parent = 0, QString error = "");
    ~ErrorWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ErrorWindow *ui;
};

#endif // ERRORWINDOW_H
