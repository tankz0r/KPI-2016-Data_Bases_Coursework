/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *loginField;
    QLineEdit *pwField;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *ErrorLabel;
    QLineEdit *pwField_2;
    QLabel *label_4;
    QLineEdit *pwField_3;
    QLabel *label_5;

    void setupUi(QDialog *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName(QStringLiteral("LoginWindow"));
        LoginWindow->resize(475, 365);
        LoginWindow->setMinimumSize(QSize(475, 365));
        LoginWindow->setMaximumSize(QSize(475, 365));
        buttonBox = new QDialogButtonBox(LoginWindow);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(10, 320, 441, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        loginField = new QLineEdit(LoginWindow);
        loginField->setObjectName(QStringLiteral("loginField"));
        loginField->setGeometry(QRect(160, 60, 301, 33));
        loginField->setClearButtonEnabled(true);
        pwField = new QLineEdit(LoginWindow);
        pwField->setObjectName(QStringLiteral("pwField"));
        pwField->setGeometry(QRect(160, 110, 301, 33));
        pwField->setEchoMode(QLineEdit::Password);
        pwField->setClearButtonEnabled(true);
        label = new QLabel(LoginWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 10, 231, 21));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        label_2 = new QLabel(LoginWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(60, 60, 66, 21));
        QFont font1;
        font1.setPointSize(12);
        label_2->setFont(font1);
        label_3 = new QLabel(LoginWindow);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(60, 110, 66, 21));
        label_3->setFont(font1);
        label_3->setTextFormat(Qt::AutoText);
        ErrorLabel = new QLabel(LoginWindow);
        ErrorLabel->setObjectName(QStringLiteral("ErrorLabel"));
        ErrorLabel->setEnabled(false);
        ErrorLabel->setGeometry(QRect(30, 250, 431, 61));
        QFont font2;
        font2.setItalic(true);
        ErrorLabel->setFont(font2);
        ErrorLabel->setLocale(QLocale(QLocale::Ukrainian, QLocale::Ukraine));
        ErrorLabel->setWordWrap(false);
        pwField_2 = new QLineEdit(LoginWindow);
        pwField_2->setObjectName(QStringLiteral("pwField_2"));
        pwField_2->setGeometry(QRect(160, 160, 301, 33));
        pwField_2->setClearButtonEnabled(true);
        label_4 = new QLabel(LoginWindow);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(60, 160, 66, 21));
        label_4->setFont(font1);
        label_4->setTextFormat(Qt::AutoText);
        pwField_3 = new QLineEdit(LoginWindow);
        pwField_3->setObjectName(QStringLiteral("pwField_3"));
        pwField_3->setGeometry(QRect(160, 210, 301, 33));
        pwField_3->setClearButtonEnabled(true);
        label_5 = new QLabel(LoginWindow);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(60, 210, 66, 21));
        label_5->setFont(font1);
        label_5->setTextFormat(Qt::AutoText);

        retranslateUi(LoginWindow);
        QObject::connect(buttonBox, SIGNAL(accepted()), LoginWindow, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), LoginWindow, SLOT(reject()));

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QDialog *LoginWindow)
    {
        LoginWindow->setWindowTitle(QApplication::translate("LoginWindow", "\320\220\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\321\226\321\217", 0));
        label->setText(QApplication::translate("LoginWindow", "\320\220\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\321\226\321\217 \320\272\320\276\321\200\320\270\321\201\321\202\321\203\320\262\320\260\321\207\320\260", 0));
        label_2->setText(QApplication::translate("LoginWindow", "\320\233\320\276\320\263\321\226\320\275", 0));
        label_3->setText(QApplication::translate("LoginWindow", "\320\237\320\260\321\200\320\276\320\273\321\214", 0));
        ErrorLabel->setText(QApplication::translate("LoginWindow", "<html><head/><body><p><br/></p></body></html>", 0));
        pwField_2->setText(QApplication::translate("LoginWindow", "127.0.0.1", 0));
        label_4->setText(QApplication::translate("LoginWindow", "IP", 0));
        pwField_3->setText(QApplication::translate("LoginWindow", "5432", 0));
        label_5->setText(QApplication::translate("LoginWindow", "\320\237\320\276\321\200\321\202", 0));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
