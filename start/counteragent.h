#ifndef COUNTERAGENT_H
#define COUNTERAGENT_H

#include <QDialog>
#include "mainform.h"

namespace Ui {
class CounterAgent;
}

class CounterAgent : public QDialog
{
    Q_OBJECT

public:
    explicit CounterAgent(QWidget *parent = 0);
    ~CounterAgent();

private slots:
    void on_Load_clicked();

private:
    Ui::CounterAgent *ui;
};

#endif // COUNTERAGENT_H
