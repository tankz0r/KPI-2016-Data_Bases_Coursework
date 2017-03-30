/********************************************************************************
** Form generated from reading UI file 'employeewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYEEWINDOW_H
#define UI_EMPLOYEEWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EmployeeWindow
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label_black_star;
    QLabel *ErrorLabel_employee;
    QPushButton *pushButton_add_new_worker;
    QWidget *widget_new_worker;
    QLabel *label_5;
    QLineEdit *lineEdit_5_employee_experience;
    QLineEdit *lineEdit_4__employee_education;
    QLineEdit *lineEdit_3_employee_adrress;
    QLineEdit *lineEdit_8_employee_rate;
    QDateEdit *dateEdit;
    QLabel *label_7;
    QLabel *label_10;
    QLineEdit *lineEdit_employee_name;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_6;
    QPushButton *pushButton_add_change;
    QWidget *widget_change;
    QLineEdit *lineEdit_change_name;
    QLabel *label_11;
    QLabel *label_12;
    QComboBox *comboBox_change_position;
    QDateEdit *dateEdit_begin;
    QLabel *label_13;
    QLabel *label_16;
    QDateEdit *dateEdit_end;
    QComboBox *comboBox_employee_department;
    QLabel *label_8;
    QWidget *widget_list_employee;
    QLabel *label_list_employee;
    QTableWidget *tableWidget_list_employee;

    void setupUi(QDialog *EmployeeWindow)
    {
        if (EmployeeWindow->objectName().isEmpty())
            EmployeeWindow->setObjectName(QStringLiteral("EmployeeWindow"));
        EmployeeWindow->setEnabled(true);
        EmployeeWindow->resize(800, 400);
        EmployeeWindow->setMinimumSize(QSize(800, 400));
        EmployeeWindow->setMaximumSize(QSize(800, 400));
        buttonBox = new QDialogButtonBox(EmployeeWindow);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(180, 350, 181, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label_black_star = new QLabel(EmployeeWindow);
        label_black_star->setObjectName(QStringLiteral("label_black_star"));
        label_black_star->setGeometry(QRect(130, 10, 170, 25));
        QFont font;
        font.setPointSize(15);
        label_black_star->setFont(font);
        ErrorLabel_employee = new QLabel(EmployeeWindow);
        ErrorLabel_employee->setObjectName(QStringLiteral("ErrorLabel_employee"));
        ErrorLabel_employee->setEnabled(false);
        ErrorLabel_employee->setGeometry(QRect(20, 280, 360, 65));
        QFont font1;
        font1.setItalic(true);
        ErrorLabel_employee->setFont(font1);
        ErrorLabel_employee->setLocale(QLocale(QLocale::Ukrainian, QLocale::Ukraine));
        ErrorLabel_employee->setScaledContents(false);
        ErrorLabel_employee->setWordWrap(false);
        pushButton_add_new_worker = new QPushButton(EmployeeWindow);
        pushButton_add_new_worker->setObjectName(QStringLiteral("pushButton_add_new_worker"));
        pushButton_add_new_worker->setGeometry(QRect(30, 40, 140, 30));
        widget_new_worker = new QWidget(EmployeeWindow);
        widget_new_worker->setObjectName(QStringLiteral("widget_new_worker"));
        widget_new_worker->setGeometry(QRect(20, 70, 360, 201));
        label_5 = new QLabel(widget_new_worker);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 70, 150, 25));
        QFont font2;
        font2.setPointSize(12);
        label_5->setFont(font2);
        lineEdit_5_employee_experience = new QLineEdit(widget_new_worker);
        lineEdit_5_employee_experience->setObjectName(QStringLiteral("lineEdit_5_employee_experience"));
        lineEdit_5_employee_experience->setGeometry(QRect(150, 130, 200, 25));
        lineEdit_5_employee_experience->setFont(font2);
        lineEdit_4__employee_education = new QLineEdit(widget_new_worker);
        lineEdit_4__employee_education->setObjectName(QStringLiteral("lineEdit_4__employee_education"));
        lineEdit_4__employee_education->setGeometry(QRect(150, 100, 200, 25));
        lineEdit_4__employee_education->setFont(font2);
        lineEdit_3_employee_adrress = new QLineEdit(widget_new_worker);
        lineEdit_3_employee_adrress->setObjectName(QStringLiteral("lineEdit_3_employee_adrress"));
        lineEdit_3_employee_adrress->setGeometry(QRect(150, 70, 200, 25));
        lineEdit_3_employee_adrress->setFont(font2);
        lineEdit_8_employee_rate = new QLineEdit(widget_new_worker);
        lineEdit_8_employee_rate->setObjectName(QStringLiteral("lineEdit_8_employee_rate"));
        lineEdit_8_employee_rate->setGeometry(QRect(150, 160, 200, 25));
        lineEdit_8_employee_rate->setFont(font2);
        dateEdit = new QDateEdit(widget_new_worker);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(150, 40, 200, 25));
        label_7 = new QLabel(widget_new_worker);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 130, 150, 25));
        label_7->setFont(font2);
        label_10 = new QLabel(widget_new_worker);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 160, 150, 25));
        label_10->setFont(font2);
        lineEdit_employee_name = new QLineEdit(widget_new_worker);
        lineEdit_employee_name->setObjectName(QStringLiteral("lineEdit_employee_name"));
        lineEdit_employee_name->setGeometry(QRect(150, 10, 200, 25));
        lineEdit_employee_name->setFont(font2);
        label_3 = new QLabel(widget_new_worker);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 10, 150, 25));
        label_3->setFont(font2);
        label_4 = new QLabel(widget_new_worker);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 40, 150, 25));
        label_4->setFont(font2);
        label_6 = new QLabel(widget_new_worker);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 100, 150, 25));
        label_6->setFont(font2);
        pushButton_add_change = new QPushButton(EmployeeWindow);
        pushButton_add_change->setObjectName(QStringLiteral("pushButton_add_change"));
        pushButton_add_change->setGeometry(QRect(200, 40, 140, 30));
        widget_change = new QWidget(EmployeeWindow);
        widget_change->setObjectName(QStringLiteral("widget_change"));
        widget_change->setGeometry(QRect(20, 70, 360, 201));
        lineEdit_change_name = new QLineEdit(widget_change);
        lineEdit_change_name->setObjectName(QStringLiteral("lineEdit_change_name"));
        lineEdit_change_name->setGeometry(QRect(150, 10, 200, 25));
        lineEdit_change_name->setFont(font2);
        label_11 = new QLabel(widget_change);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(10, 10, 150, 25));
        label_11->setFont(font2);
        label_12 = new QLabel(widget_change);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 40, 150, 25));
        label_12->setFont(font2);
        comboBox_change_position = new QComboBox(widget_change);
        comboBox_change_position->setObjectName(QStringLiteral("comboBox_change_position"));
        comboBox_change_position->setGeometry(QRect(150, 40, 200, 25));
        dateEdit_begin = new QDateEdit(widget_change);
        dateEdit_begin->setObjectName(QStringLiteral("dateEdit_begin"));
        dateEdit_begin->setGeometry(QRect(150, 70, 200, 25));
        dateEdit_begin->setCalendarPopup(true);
        label_13 = new QLabel(widget_change);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(10, 70, 150, 25));
        label_13->setFont(font2);
        label_16 = new QLabel(widget_change);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(10, 100, 150, 25));
        label_16->setFont(font2);
        dateEdit_end = new QDateEdit(widget_change);
        dateEdit_end->setObjectName(QStringLiteral("dateEdit_end"));
        dateEdit_end->setGeometry(QRect(150, 100, 200, 25));
        dateEdit_end->setCalendarPopup(true);
        comboBox_employee_department = new QComboBox(widget_change);
        comboBox_employee_department->setObjectName(QStringLiteral("comboBox_employee_department"));
        comboBox_employee_department->setGeometry(QRect(150, 130, 200, 25));
        label_8 = new QLabel(widget_change);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 130, 150, 25));
        label_8->setFont(font2);
        widget_list_employee = new QWidget(EmployeeWindow);
        widget_list_employee->setObjectName(QStringLiteral("widget_list_employee"));
        widget_list_employee->setGeometry(QRect(389, 30, 401, 331));
        label_list_employee = new QLabel(widget_list_employee);
        label_list_employee->setObjectName(QStringLiteral("label_list_employee"));
        label_list_employee->setGeometry(QRect(49, 0, 191, 25));
        label_list_employee->setFont(font);
        tableWidget_list_employee = new QTableWidget(widget_list_employee);
        if (tableWidget_list_employee->columnCount() < 3)
            tableWidget_list_employee->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_list_employee->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_list_employee->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_list_employee->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget_list_employee->setObjectName(QStringLiteral("tableWidget_list_employee"));
        tableWidget_list_employee->setGeometry(QRect(0, 30, 401, 301));
        tableWidget_list_employee->horizontalHeader()->setDefaultSectionSize(132);
        buttonBox->raise();
        label_black_star->raise();
        ErrorLabel_employee->raise();
        pushButton_add_new_worker->raise();
        widget_new_worker->raise();
        pushButton_add_change->raise();
        widget_list_employee->raise();
        widget_change->raise();

        retranslateUi(EmployeeWindow);
        QObject::connect(buttonBox, SIGNAL(accepted()), EmployeeWindow, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), EmployeeWindow, SLOT(reject()));

        QMetaObject::connectSlotsByName(EmployeeWindow);
    } // setupUi

    void retranslateUi(QDialog *EmployeeWindow)
    {
        EmployeeWindow->setWindowTitle(QApplication::translate("EmployeeWindow", "Employee Window", 0));
        label_black_star->setText(QApplication::translate("EmployeeWindow", "\320\240\321\203\321\205 \320\277\320\276\321\201\320\260\320\264", 0));
        ErrorLabel_employee->setText(QApplication::translate("EmployeeWindow", "<html><head/><body><p><br/></p></body></html>", 0));
        pushButton_add_new_worker->setText(QApplication::translate("EmployeeWindow", "\320\224\320\276\320\264\320\260\321\202\320\270 \321\200\320\276\320\261\321\226\321\202\320\275\320\270\320\272\320\260", 0));
        label_5->setText(QApplication::translate("EmployeeWindow", "\320\220\320\264\321\200\320\265\321\201\320\260", 0));
        dateEdit->setDisplayFormat(QApplication::translate("EmployeeWindow", "dd/MM/yyyy", 0));
        label_7->setText(QApplication::translate("EmployeeWindow", "\320\224\320\276\321\201\320\262\321\226\320\264", 0));
        label_10->setText(QApplication::translate("EmployeeWindow", "\320\241\321\202\320\260\320\262\320\272\320\260", 0));
        label_3->setText(QApplication::translate("EmployeeWindow", "\320\237\320\206\320\221", 0));
        label_4->setText(QApplication::translate("EmployeeWindow", "\320\224\320\260\321\202\320\260 \320\275\320\260\321\200\320\276\320\264\320\266\320\265\320\275\320\275\321\217", 0));
        label_6->setText(QApplication::translate("EmployeeWindow", "\320\236\321\201\320\262\321\226\321\202\320\260", 0));
        pushButton_add_change->setText(QApplication::translate("EmployeeWindow", "\320\227\320\274\321\226\320\275\320\270\321\202\320\270 \321\201\321\202\320\260\321\202\321\203\321\201", 0));
        label_11->setText(QApplication::translate("EmployeeWindow", "\320\237\320\206\320\221", 0));
        label_12->setText(QApplication::translate("EmployeeWindow", "\320\237\320\276\321\201\320\260\320\264\320\260", 0));
        dateEdit_begin->setDisplayFormat(QApplication::translate("EmployeeWindow", "dd/MM/yyyy", 0));
        label_13->setText(QApplication::translate("EmployeeWindow", "\320\224\320\260\321\202\320\260 \320\277\320\276\321\207\320\260\321\202\320\272\321\203", 0));
        label_16->setText(QApplication::translate("EmployeeWindow", "\320\224\320\260\321\202\320\260 \320\277\320\276\321\207\320\260\321\202\320\272\321\203", 0));
        dateEdit_end->setDisplayFormat(QApplication::translate("EmployeeWindow", "dd/MM/yyyy", 0));
        label_8->setText(QApplication::translate("EmployeeWindow", "\320\222\321\226\320\264\320\264\321\226\320\273", 0));
        label_list_employee->setText(QApplication::translate("EmployeeWindow", "\320\241\320\277\320\270\321\201\320\276\320\272 \320\277\321\200\320\260\321\206\321\226\320\262\320\275\320\270\320\272\321\226\320\262", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_list_employee->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("EmployeeWindow", "\320\237\320\206\320\221", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_list_employee->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("EmployeeWindow", "\320\237\320\276\321\201\320\260\320\264\320\260", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_list_employee->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("EmployeeWindow", "\320\222\321\226\320\264\320\264\321\226\320\273", 0));
    } // retranslateUi

};

namespace Ui {
    class EmployeeWindow: public Ui_EmployeeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYEEWINDOW_H
