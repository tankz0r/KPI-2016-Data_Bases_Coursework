#ifndef DOCBUY_H
#define DOCBUY_H

#include <QDialog>

namespace Ui {
class docbuy;
}

class docbuy : public QDialog
{
    Q_OBJECT

public:
    explicit docbuy(QWidget *parent = 0);
    ~docbuy();

private:
    Ui::docbuy *ui;
};

#endif // DOCBUY_H
