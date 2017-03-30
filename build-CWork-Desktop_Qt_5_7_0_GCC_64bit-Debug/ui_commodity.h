/********************************************************************************
** Form generated from reading UI file 'commodity.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMODITY_H
#define UI_COMMODITY_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_commodity
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label_black_star;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *widget_add;
    QLineEdit *lineEdit_widget_add_commodity_article;
    QLabel *label_5;
    QComboBox *comboBox_widget_add_commodity_measurements_units;
    QLabel *label_3;
    QLabel *label_2;
    QLineEdit *lineEdit_widget_add_commodity_name;
    QComboBox *comboBox_widget_add_commodity_type_commodity;
    QLabel *label_4;
    QLabel *label_6;
    QLineEdit *lineEdit_widget_add_commodity_quantity;
    QPushButton *pushButton_3;
    QLabel *ErrorLabel_commodity;
    QWidget *widget_delete;
    QLabel *label_10;
    QLineEdit *lineEdit_widget_delete_commodity_name;
    QLabel *label_12;
    QLineEdit *lineEdit_widget_delete_commodity_quantity;

    void setupUi(QDialog *commodity)
    {
        if (commodity->objectName().isEmpty())
            commodity->setObjectName(QStringLiteral("commodity"));
        commodity->resize(490, 400);
        commodity->setMinimumSize(QSize(490, 400));
        commodity->setMaximumSize(QSize(490, 400));
        buttonBox = new QDialogButtonBox(commodity);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(-260, 370, 741, 20));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label_black_star = new QLabel(commodity);
        label_black_star->setObjectName(QStringLiteral("label_black_star"));
        label_black_star->setGeometry(QRect(220, 10, 61, 25));
        QFont font;
        font.setPointSize(15);
        label_black_star->setFont(font);
        pushButton = new QPushButton(commodity);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(80, 40, 110, 25));
        QFont font1;
        font1.setPointSize(10);
        pushButton->setFont(font1);
        pushButton_2 = new QPushButton(commodity);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(280, 40, 110, 25));
        pushButton_2->setFont(font1);
        widget_add = new QWidget(commodity);
        widget_add->setObjectName(QStringLiteral("widget_add"));
        widget_add->setGeometry(QRect(40, 80, 400, 220));
        lineEdit_widget_add_commodity_article = new QLineEdit(widget_add);
        lineEdit_widget_add_commodity_article->setObjectName(QStringLiteral("lineEdit_widget_add_commodity_article"));
        lineEdit_widget_add_commodity_article->setEnabled(false);
        lineEdit_widget_add_commodity_article->setGeometry(QRect(150, 90, 150, 25));
        QFont font2;
        font2.setPointSize(12);
        lineEdit_widget_add_commodity_article->setFont(font2);
        label_5 = new QLabel(widget_add);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setEnabled(false);
        label_5->setGeometry(QRect(10, 130, 150, 25));
        label_5->setFont(font2);
        comboBox_widget_add_commodity_measurements_units = new QComboBox(widget_add);
        comboBox_widget_add_commodity_measurements_units->setObjectName(QStringLiteral("comboBox_widget_add_commodity_measurements_units"));
        comboBox_widget_add_commodity_measurements_units->setEnabled(false);
        comboBox_widget_add_commodity_measurements_units->setGeometry(QRect(150, 130, 150, 25));
        label_3 = new QLabel(widget_add);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setEnabled(false);
        label_3->setGeometry(QRect(10, 50, 150, 25));
        label_3->setFont(font2);
        label_2 = new QLabel(widget_add);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setEnabled(true);
        label_2->setGeometry(QRect(10, 10, 150, 25));
        label_2->setFont(font2);
        lineEdit_widget_add_commodity_name = new QLineEdit(widget_add);
        lineEdit_widget_add_commodity_name->setObjectName(QStringLiteral("lineEdit_widget_add_commodity_name"));
        lineEdit_widget_add_commodity_name->setEnabled(true);
        lineEdit_widget_add_commodity_name->setGeometry(QRect(150, 10, 150, 25));
        lineEdit_widget_add_commodity_name->setFont(font2);
        comboBox_widget_add_commodity_type_commodity = new QComboBox(widget_add);
        comboBox_widget_add_commodity_type_commodity->setObjectName(QStringLiteral("comboBox_widget_add_commodity_type_commodity"));
        comboBox_widget_add_commodity_type_commodity->setEnabled(false);
        comboBox_widget_add_commodity_type_commodity->setGeometry(QRect(150, 50, 150, 25));
        label_4 = new QLabel(widget_add);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setEnabled(false);
        label_4->setGeometry(QRect(10, 90, 150, 25));
        label_4->setFont(font2);
        label_6 = new QLabel(widget_add);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 170, 150, 25));
        label_6->setFont(font2);
        lineEdit_widget_add_commodity_quantity = new QLineEdit(widget_add);
        lineEdit_widget_add_commodity_quantity->setObjectName(QStringLiteral("lineEdit_widget_add_commodity_quantity"));
        lineEdit_widget_add_commodity_quantity->setGeometry(QRect(150, 170, 150, 25));
        lineEdit_widget_add_commodity_quantity->setFont(font2);
        pushButton_3 = new QPushButton(widget_add);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(310, 10, 71, 25));
        pushButton_3->setFont(font1);
        ErrorLabel_commodity = new QLabel(commodity);
        ErrorLabel_commodity->setObjectName(QStringLiteral("ErrorLabel_commodity"));
        ErrorLabel_commodity->setEnabled(false);
        ErrorLabel_commodity->setGeometry(QRect(20, 300, 431, 61));
        QFont font3;
        font3.setItalic(true);
        ErrorLabel_commodity->setFont(font3);
        ErrorLabel_commodity->setLocale(QLocale(QLocale::Ukrainian, QLocale::Ukraine));
        ErrorLabel_commodity->setScaledContents(false);
        ErrorLabel_commodity->setAlignment(Qt::AlignCenter);
        ErrorLabel_commodity->setWordWrap(false);
        widget_delete = new QWidget(commodity);
        widget_delete->setObjectName(QStringLiteral("widget_delete"));
        widget_delete->setGeometry(QRect(40, 80, 400, 220));
        label_10 = new QLabel(widget_delete);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(40, 10, 150, 25));
        label_10->setFont(font2);
        lineEdit_widget_delete_commodity_name = new QLineEdit(widget_delete);
        lineEdit_widget_delete_commodity_name->setObjectName(QStringLiteral("lineEdit_widget_delete_commodity_name"));
        lineEdit_widget_delete_commodity_name->setGeometry(QRect(150, 10, 150, 25));
        lineEdit_widget_delete_commodity_name->setFont(font2);
        label_12 = new QLabel(widget_delete);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(40, 50, 150, 25));
        label_12->setFont(font2);
        lineEdit_widget_delete_commodity_quantity = new QLineEdit(widget_delete);
        lineEdit_widget_delete_commodity_quantity->setObjectName(QStringLiteral("lineEdit_widget_delete_commodity_quantity"));
        lineEdit_widget_delete_commodity_quantity->setGeometry(QRect(150, 50, 150, 25));
        lineEdit_widget_delete_commodity_quantity->setFont(font2);
        buttonBox->raise();
        label_black_star->raise();
        pushButton->raise();
        pushButton_2->raise();
        ErrorLabel_commodity->raise();
        widget_delete->raise();
        widget_add->raise();

        retranslateUi(commodity);
        QObject::connect(buttonBox, SIGNAL(accepted()), commodity, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), commodity, SLOT(reject()));

        QMetaObject::connectSlotsByName(commodity);
    } // setupUi

    void retranslateUi(QDialog *commodity)
    {
        commodity->setWindowTitle(QApplication::translate("commodity", "\320\242\320\276\320\262\320\260\321\200", 0));
        label_black_star->setText(QApplication::translate("commodity", "\320\242\320\276\320\262\320\260\321\200", 0));
        pushButton->setText(QApplication::translate("commodity", "\320\224\320\276\320\264\320\260\321\202\320\270", 0));
        pushButton_2->setText(QApplication::translate("commodity", "\320\222\320\270\320\264\320\260\320\273\320\270\321\202\320\270", 0));
        label_5->setText(QApplication::translate("commodity", "\320\236\320\264. \320\262\320\270\320\274\321\226\321\200\321\216\320\262\320\260\320\275\320\275\321\217", 0));
        label_3->setText(QApplication::translate("commodity", "\320\242\320\270\320\277 \321\202\320\276\320\262\320\260\321\200\321\203", 0));
        label_2->setText(QApplication::translate("commodity", "\320\235\320\260\320\267\320\262\320\260 \321\202\320\276\320\262\320\260\321\200\321\203", 0));
        label_4->setText(QApplication::translate("commodity", "\320\220\321\200\321\202\320\270\320\272\321\203\320\273", 0));
        label_6->setText(QApplication::translate("commodity", "\320\232\321\226\320\273\321\214\320\272\321\226\321\201\321\202\321\214", 0));
        pushButton_3->setText(QApplication::translate("commodity", "\320\235\320\276\320\262\320\270\320\271", 0));
        ErrorLabel_commodity->setText(QApplication::translate("commodity", "<html><head/><body><p><br/></p></body></html>", 0));
        label_10->setText(QApplication::translate("commodity", "\320\235\320\260\320\267\320\262\320\260 \321\202\320\276\320\262\320\260\321\200\321\203", 0));
        label_12->setText(QApplication::translate("commodity", "\320\232\321\226\320\273\321\214\320\272\321\226\321\201\321\202\321\214", 0));
    } // retranslateUi

};

namespace Ui {
    class commodity: public Ui_commodity {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMODITY_H
