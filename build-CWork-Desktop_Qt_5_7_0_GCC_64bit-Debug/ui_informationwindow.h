/********************************************************************************
** Form generated from reading UI file 'informationwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFORMATIONWINDOW_H
#define UI_INFORMATIONWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InformationWindow
{
public:
    QDialogButtonBox *buttonBox_InformationWindow;
    QLabel *label_InformationWindow;
    QWidget *widget_person;
    QLabel *label_1;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label_widget_person;
    QLabel *label_widget_person_name;
    QLabel *label_widget_person_date_birth;
    QLabel *label_widget_person_telephone;
    QWidget *widget_legal;
    QLabel *label_9;
    QLabel *label_11;
    QLabel *label_10;
    QLabel *label_12;
    QLabel *label_widget_legal;
    QLabel *label_legal_telephone;
    QLabel *label_legal_edrpou;
    QLabel *label_legal_name;
    QLabel *label_legal_id_code;
    QLabel *ErrorLabel_InformationWindow;
    QListWidget *listWidget;

    void setupUi(QDialog *InformationWindow)
    {
        if (InformationWindow->objectName().isEmpty())
            InformationWindow->setObjectName(QStringLiteral("InformationWindow"));
        InformationWindow->resize(500, 400);
        InformationWindow->setMinimumSize(QSize(500, 400));
        InformationWindow->setMaximumSize(QSize(500, 400));
        buttonBox_InformationWindow = new QDialogButtonBox(InformationWindow);
        buttonBox_InformationWindow->setObjectName(QStringLiteral("buttonBox_InformationWindow"));
        buttonBox_InformationWindow->setGeometry(QRect(-150, 340, 621, 32));
        buttonBox_InformationWindow->setOrientation(Qt::Horizontal);
        buttonBox_InformationWindow->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label_InformationWindow = new QLabel(InformationWindow);
        label_InformationWindow->setObjectName(QStringLiteral("label_InformationWindow"));
        label_InformationWindow->setGeometry(QRect(190, 10, 111, 25));
        QFont font;
        font.setPointSize(15);
        label_InformationWindow->setFont(font);
        widget_person = new QWidget(InformationWindow);
        widget_person->setObjectName(QStringLiteral("widget_person"));
        widget_person->setGeometry(QRect(0, 60, 500, 180));
        label_1 = new QLabel(widget_person);
        label_1->setObjectName(QStringLiteral("label_1"));
        label_1->setGeometry(QRect(130, 80, 101, 30));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setWeight(50);
        label_1->setFont(font1);
        label_3 = new QLabel(widget_person);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(130, 110, 111, 30));
        label_3->setFont(font1);
        label_2 = new QLabel(widget_person);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(130, 50, 101, 30));
        label_2->setFont(font1);
        label_widget_person = new QLabel(widget_person);
        label_widget_person->setObjectName(QStringLiteral("label_widget_person"));
        label_widget_person->setGeometry(QRect(210, 10, 101, 30));
        label_widget_person->setFont(font1);
        label_widget_person_name = new QLabel(widget_person);
        label_widget_person_name->setObjectName(QStringLiteral("label_widget_person_name"));
        label_widget_person_name->setGeometry(QRect(210, 50, 150, 30));
        label_widget_person_name->setFont(font1);
        label_widget_person_date_birth = new QLabel(widget_person);
        label_widget_person_date_birth->setObjectName(QStringLiteral("label_widget_person_date_birth"));
        label_widget_person_date_birth->setGeometry(QRect(210, 80, 150, 30));
        label_widget_person_date_birth->setFont(font1);
        label_widget_person_telephone = new QLabel(widget_person);
        label_widget_person_telephone->setObjectName(QStringLiteral("label_widget_person_telephone"));
        label_widget_person_telephone->setGeometry(QRect(210, 110, 150, 30));
        label_widget_person_telephone->setFont(font1);
        widget_legal = new QWidget(InformationWindow);
        widget_legal->setObjectName(QStringLiteral("widget_legal"));
        widget_legal->setGeometry(QRect(0, 60, 500, 180));
        label_9 = new QLabel(widget_legal);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(130, 50, 101, 30));
        label_9->setFont(font1);
        label_11 = new QLabel(widget_legal);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(130, 110, 111, 30));
        label_11->setFont(font1);
        label_10 = new QLabel(widget_legal);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(130, 80, 101, 30));
        label_10->setFont(font1);
        label_12 = new QLabel(widget_legal);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(130, 140, 101, 30));
        label_12->setFont(font1);
        label_widget_legal = new QLabel(widget_legal);
        label_widget_legal->setObjectName(QStringLiteral("label_widget_legal"));
        label_widget_legal->setGeometry(QRect(200, 10, 101, 30));
        label_widget_legal->setFont(font1);
        label_legal_telephone = new QLabel(widget_legal);
        label_legal_telephone->setObjectName(QStringLiteral("label_legal_telephone"));
        label_legal_telephone->setGeometry(QRect(230, 140, 150, 30));
        label_legal_telephone->setFont(font1);
        label_legal_edrpou = new QLabel(widget_legal);
        label_legal_edrpou->setObjectName(QStringLiteral("label_legal_edrpou"));
        label_legal_edrpou->setGeometry(QRect(230, 80, 150, 30));
        label_legal_edrpou->setFont(font1);
        label_legal_name = new QLabel(widget_legal);
        label_legal_name->setObjectName(QStringLiteral("label_legal_name"));
        label_legal_name->setGeometry(QRect(230, 50, 150, 30));
        label_legal_name->setFont(font1);
        label_legal_id_code = new QLabel(widget_legal);
        label_legal_id_code->setObjectName(QStringLiteral("label_legal_id_code"));
        label_legal_id_code->setGeometry(QRect(230, 110, 150, 30));
        label_legal_id_code->setFont(font1);
        ErrorLabel_InformationWindow = new QLabel(InformationWindow);
        ErrorLabel_InformationWindow->setObjectName(QStringLiteral("ErrorLabel_InformationWindow"));
        ErrorLabel_InformationWindow->setEnabled(false);
        ErrorLabel_InformationWindow->setGeometry(QRect(80, 250, 360, 50));
        QFont font2;
        font2.setItalic(true);
        ErrorLabel_InformationWindow->setFont(font2);
        ErrorLabel_InformationWindow->setLocale(QLocale(QLocale::Ukrainian, QLocale::Ukraine));
        ErrorLabel_InformationWindow->setScaledContents(false);
        ErrorLabel_InformationWindow->setAlignment(Qt::AlignCenter);
        ErrorLabel_InformationWindow->setWordWrap(false);
        listWidget = new QListWidget(InformationWindow);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(100, 40, 256, 291));
        buttonBox_InformationWindow->raise();
        label_InformationWindow->raise();
        ErrorLabel_InformationWindow->raise();
        widget_legal->raise();
        widget_person->raise();
        listWidget->raise();

        retranslateUi(InformationWindow);
        QObject::connect(buttonBox_InformationWindow, SIGNAL(accepted()), InformationWindow, SLOT(accept()));
        QObject::connect(buttonBox_InformationWindow, SIGNAL(rejected()), InformationWindow, SLOT(reject()));

        QMetaObject::connectSlotsByName(InformationWindow);
    } // setupUi

    void retranslateUi(QDialog *InformationWindow)
    {
        InformationWindow->setWindowTitle(QApplication::translate("InformationWindow", "\320\206\320\275\321\204\320\276\321\200\320\274\320\260\321\206\321\226\321\217", 0));
        label_InformationWindow->setText(QApplication::translate("InformationWindow", "\320\206\320\275\321\204\320\276\321\200\320\274\320\260\321\206\321\226\321\217", 0));
        label_1->setText(QApplication::translate("InformationWindow", "\320\224\320\260\321\202\320\260 \320\275\320\260\321\200.", 0));
        label_3->setText(QApplication::translate("InformationWindow", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275", 0));
        label_2->setText(QApplication::translate("InformationWindow", "\320\237\320\206\320\221", 0));
        label_widget_person->setText(QApplication::translate("InformationWindow", "\320\244\321\226\320\267\320\270\321\207\320\275\320\260 \320\276\321\201\320\276\320\261\320\260", 0));
        label_widget_person_name->setText(QString());
        label_widget_person_date_birth->setText(QString());
        label_widget_person_telephone->setText(QString());
        label_9->setText(QApplication::translate("InformationWindow", "\320\235\320\260\320\267\320\262\320\260", 0));
        label_11->setText(QApplication::translate("InformationWindow", "\320\206\320\264\320\265\320\275\321\202. \320\272\320\276\320\264", 0));
        label_10->setText(QApplication::translate("InformationWindow", "\320\204\320\224\320\240\320\237\320\236\320\243", 0));
        label_12->setText(QApplication::translate("InformationWindow", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275", 0));
        label_widget_legal->setText(QApplication::translate("InformationWindow", "\320\256\321\200\320\270\320\264\320\270\321\207\320\275\320\260 \320\276\321\201\320\276\320\261\320\260", 0));
        label_legal_telephone->setText(QString());
        label_legal_edrpou->setText(QString());
        label_legal_name->setText(QString());
        label_legal_id_code->setText(QString());
        ErrorLabel_InformationWindow->setText(QApplication::translate("InformationWindow", "<html><head/><body><p><br/></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class InformationWindow: public Ui_InformationWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFORMATIONWINDOW_H
