#ifndef DOC_BUY_H
#define DOC_BUY_H

#include <QWidget>

namespace Ui {
class doc_buy;
}

class doc_buy : public QWidget
{
    Q_OBJECT

public:
    explicit doc_buy(QWidget *parent = 0);
    ~doc_buy();

private:
    Ui::doc_buy *ui;
};

#endif // DOC_BUY_H
