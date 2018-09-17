#ifndef DOCUMENTBUY_H
#define DOCUMENTBUY_H

#include <QDialog>

namespace Ui {
class DocumentBuy;
}

class DocumentBuy : public QDialog
{
    Q_OBJECT

public:
    explicit DocumentBuy(QWidget *parent = 0);
    ~DocumentBuy();

private:
    Ui::DocumentBuy *ui;
};

#endif // DOCUMENTBUY_H
