/********************************************************************************
** Form generated from reading UI file 'working_off.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORKING_OFF_H
#define UI_WORKING_OFF_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_working_off
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label_black_star1;
    QLineEdit *lineEdit_working_off_name;
    QLabel *label_11;
    QDateEdit *dateEdit_date_working_off;
    QLabel *label_13;
    QLineEdit *lineEdit_working_off_hours;
    QLabel *label_14;
    QLineEdit *lineEdit_working_off_overworking;
    QLabel *label_15;
    QLabel *label_16;
    QTextEdit *textEdit_working_off;
    QLabel *ErrorLabel_working_off;

    void setupUi(QDialog *working_off)
    {
        if (working_off->objectName().isEmpty())
            working_off->setObjectName(QStringLiteral("working_off"));
        working_off->resize(400, 480);
        working_off->setMinimumSize(QSize(400, 480));
        working_off->setMaximumSize(QSize(400, 480));
        buttonBox = new QDialogButtonBox(working_off);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(-250, 430, 621, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label_black_star1 = new QLabel(working_off);
        label_black_star1->setObjectName(QStringLiteral("label_black_star1"));
        label_black_star1->setGeometry(QRect(120, 10, 141, 25));
        QFont font;
        font.setPointSize(15);
        label_black_star1->setFont(font);
        lineEdit_working_off_name = new QLineEdit(working_off);
        lineEdit_working_off_name->setObjectName(QStringLiteral("lineEdit_working_off_name"));
        lineEdit_working_off_name->setGeometry(QRect(170, 60, 200, 25));
        QFont font1;
        font1.setPointSize(12);
        lineEdit_working_off_name->setFont(font1);
        label_11 = new QLabel(working_off);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(30, 60, 150, 25));
        label_11->setFont(font1);
        dateEdit_date_working_off = new QDateEdit(working_off);
        dateEdit_date_working_off->setObjectName(QStringLiteral("dateEdit_date_working_off"));
        dateEdit_date_working_off->setGeometry(QRect(170, 90, 200, 25));
        label_13 = new QLabel(working_off);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(30, 90, 150, 25));
        label_13->setFont(font1);
        lineEdit_working_off_hours = new QLineEdit(working_off);
        lineEdit_working_off_hours->setObjectName(QStringLiteral("lineEdit_working_off_hours"));
        lineEdit_working_off_hours->setGeometry(QRect(170, 120, 200, 25));
        lineEdit_working_off_hours->setFont(font1);
        label_14 = new QLabel(working_off);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(30, 120, 150, 25));
        label_14->setFont(font1);
        lineEdit_working_off_overworking = new QLineEdit(working_off);
        lineEdit_working_off_overworking->setObjectName(QStringLiteral("lineEdit_working_off_overworking"));
        lineEdit_working_off_overworking->setGeometry(QRect(170, 150, 200, 25));
        lineEdit_working_off_overworking->setFont(font1);
        label_15 = new QLabel(working_off);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(30, 150, 150, 25));
        label_15->setFont(font1);
        label_16 = new QLabel(working_off);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(30, 180, 150, 25));
        label_16->setFont(font1);
        textEdit_working_off = new QTextEdit(working_off);
        textEdit_working_off->setObjectName(QStringLiteral("textEdit_working_off"));
        textEdit_working_off->setGeometry(QRect(170, 180, 201, 70));
        ErrorLabel_working_off = new QLabel(working_off);
        ErrorLabel_working_off->setObjectName(QStringLiteral("ErrorLabel_working_off"));
        ErrorLabel_working_off->setEnabled(false);
        ErrorLabel_working_off->setGeometry(QRect(10, 290, 381, 111));
        QFont font2;
        font2.setItalic(true);
        ErrorLabel_working_off->setFont(font2);
        ErrorLabel_working_off->setLocale(QLocale(QLocale::Ukrainian, QLocale::Ukraine));
        ErrorLabel_working_off->setScaledContents(false);
        ErrorLabel_working_off->setAlignment(Qt::AlignCenter);
        ErrorLabel_working_off->setWordWrap(false);

        retranslateUi(working_off);
        QObject::connect(buttonBox, SIGNAL(accepted()), working_off, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), working_off, SLOT(reject()));

        QMetaObject::connectSlotsByName(working_off);
    } // setupUi

    void retranslateUi(QDialog *working_off)
    {
        working_off->setWindowTitle(QApplication::translate("working_off", "\320\222\321\226\320\264\320\277\321\200\320\260\321\206\321\216\320\262\320\260\320\275\320\275\321\217", 0));
        label_black_star1->setText(QApplication::translate("working_off", "\320\222\321\226\320\264\320\277\321\200\320\260\321\206\321\216\320\262\320\260\320\275\320\275\321\217", 0));
        label_11->setText(QApplication::translate("working_off", "\320\237\320\206\320\221", 0));
        dateEdit_date_working_off->setDisplayFormat(QApplication::translate("working_off", "dd/MM/yyyy", 0));
        label_13->setText(QApplication::translate("working_off", "\320\224\320\260\321\202\320\260 \320\262\321\226\320\264\320\277\321\200\320\260\321\206.", 0));
        label_14->setText(QApplication::translate("working_off", "\320\232\321\226\320\273\321\214\320\272\321\226\321\201\321\202\321\214 \320\263\320\276\320\264\320\270\320\275", 0));
        label_15->setText(QApplication::translate("working_off", "\320\237\320\265\321\200\320\265\320\277\321\200\320\260\321\206\321\216\320\262\320\260\320\275\320\275\321\217", 0));
        label_16->setText(QApplication::translate("working_off", "\320\232\320\276\320\274\320\265\320\275\321\202\320\260\321\200", 0));
        ErrorLabel_working_off->setText(QApplication::translate("working_off", "<html><head/><body><p><br/></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class working_off: public Ui_working_off {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORKING_OFF_H
