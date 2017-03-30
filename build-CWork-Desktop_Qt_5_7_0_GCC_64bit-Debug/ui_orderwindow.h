/********************************************************************************
** Form generated from reading UI file 'orderwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDERWINDOW_H
#define UI_ORDERWINDOW_H

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
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OrderWindow
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton_add_new_contragent;
    QRadioButton *radioButton_sale;
    QRadioButton *radioButton_2_buy;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *pushButton_2_add_next_commodity;
    QWidget *widget_contragent;
    QRadioButton *radioButton_3_person_entity;
    QRadioButton *radioButton_4_legal_entity;
    QWidget *legal_entity;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLineEdit *lineEdit_5_legal_entity_name;
    QLineEdit *lineEdit_6_legal_entity_id_code;
    QLineEdit *lineEdit_7_legal_entity_edrpou;
    QLineEdit *lineEdit_8_legal_entity_telephone;
    QWidget *person_entity;
    QLabel *label_20_person_entity_name;
    QLabel *label_21_person_entity_date_birth;
    QLabel *label_22_person_entity_telephone;
    QLineEdit *lineEdit_9;
    QLineEdit *lineEdit_10;
    QDateEdit *lineEdit_11;
    QPushButton *pushButton_add_new_contragent_2;
    QLineEdit *lineEdit_2_quantity;
    QLineEdit *lineEdit_3_price;
    QLabel *label_14;
    QComboBox *comboBox_4_currency;
    QDateEdit *dateEdit;
    QLabel *label_7;
    QLabel *label_measurement_units;
    QLabel *ErrorLabel_Order;
    QLineEdit *lineEdit_name_commodity;
    QLineEdit *lineEdit_contragent;
    QWidget *widget_new_order;
    QLabel *label_widget_new_order;
    QTableWidget *tableWidget_new_order;

    void setupUi(QDialog *OrderWindow)
    {
        if (OrderWindow->objectName().isEmpty())
            OrderWindow->setObjectName(QStringLiteral("OrderWindow"));
        OrderWindow->resize(950, 475);
        OrderWindow->setMinimumSize(QSize(950, 475));
        OrderWindow->setMaximumSize(QSize(950, 475));
        buttonBox = new QDialogButtonBox(OrderWindow);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(10, 430, 621, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(OrderWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(255, 10, 130, 30));
        QFont font;
        font.setPointSize(15);
        font.setBold(false);
        font.setWeight(50);
        label->setFont(font);
        label_2 = new QLabel(OrderWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 50, 130, 30));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setWeight(50);
        label_2->setFont(font1);
        pushButton_add_new_contragent = new QPushButton(OrderWindow);
        pushButton_add_new_contragent->setObjectName(QStringLiteral("pushButton_add_new_contragent"));
        pushButton_add_new_contragent->setGeometry(QRect(349, 50, 321, 30));
        QFont font2;
        font2.setPointSize(12);
        pushButton_add_new_contragent->setFont(font2);
        radioButton_sale = new QRadioButton(OrderWindow);
        radioButton_sale->setObjectName(QStringLiteral("radioButton_sale"));
        radioButton_sale->setGeometry(QRect(50, 90, 90, 20));
        radioButton_sale->setFont(font2);
        radioButton_2_buy = new QRadioButton(OrderWindow);
        radioButton_2_buy->setObjectName(QStringLiteral("radioButton_2_buy"));
        radioButton_2_buy->setGeometry(QRect(160, 90, 90, 20));
        radioButton_2_buy->setFont(font2);
        label_3 = new QLabel(OrderWindow);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(110, 120, 130, 30));
        label_3->setFont(font1);
        label_4 = new QLabel(OrderWindow);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 210, 130, 30));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(false);
        font3.setWeight(50);
        label_4->setFont(font3);
        label_5 = new QLabel(OrderWindow);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 240, 130, 30));
        label_5->setFont(font3);
        label_6 = new QLabel(OrderWindow);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 270, 130, 30));
        label_6->setFont(font3);
        pushButton_2_add_next_commodity = new QPushButton(OrderWindow);
        pushButton_2_add_next_commodity->setObjectName(QStringLiteral("pushButton_2_add_next_commodity"));
        pushButton_2_add_next_commodity->setGeometry(QRect(30, 330, 220, 20));
        QFont font4;
        font4.setPointSize(10);
        pushButton_2_add_next_commodity->setFont(font4);
        widget_contragent = new QWidget(OrderWindow);
        widget_contragent->setObjectName(QStringLiteral("widget_contragent"));
        widget_contragent->setGeometry(QRect(350, 90, 321, 220));
        radioButton_3_person_entity = new QRadioButton(widget_contragent);
        radioButton_3_person_entity->setObjectName(QStringLiteral("radioButton_3_person_entity"));
        radioButton_3_person_entity->setGeometry(QRect(170, 10, 100, 20));
        radioButton_3_person_entity->setFont(font4);
        radioButton_4_legal_entity = new QRadioButton(widget_contragent);
        radioButton_4_legal_entity->setObjectName(QStringLiteral("radioButton_4_legal_entity"));
        radioButton_4_legal_entity->setGeometry(QRect(50, 10, 100, 20));
        radioButton_4_legal_entity->setFont(font4);
        legal_entity = new QWidget(widget_contragent);
        legal_entity->setObjectName(QStringLiteral("legal_entity"));
        legal_entity->setGeometry(QRect(20, 30, 281, 150));
        label_9 = new QLabel(legal_entity);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(20, 10, 101, 30));
        label_9->setFont(font3);
        label_10 = new QLabel(legal_entity);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(20, 40, 101, 30));
        label_10->setFont(font3);
        label_11 = new QLabel(legal_entity);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(20, 70, 111, 30));
        label_11->setFont(font3);
        label_12 = new QLabel(legal_entity);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(20, 100, 101, 30));
        label_12->setFont(font3);
        lineEdit_5_legal_entity_name = new QLineEdit(legal_entity);
        lineEdit_5_legal_entity_name->setObjectName(QStringLiteral("lineEdit_5_legal_entity_name"));
        lineEdit_5_legal_entity_name->setGeometry(QRect(120, 10, 150, 25));
        lineEdit_6_legal_entity_id_code = new QLineEdit(legal_entity);
        lineEdit_6_legal_entity_id_code->setObjectName(QStringLiteral("lineEdit_6_legal_entity_id_code"));
        lineEdit_6_legal_entity_id_code->setGeometry(QRect(120, 70, 150, 25));
        lineEdit_7_legal_entity_edrpou = new QLineEdit(legal_entity);
        lineEdit_7_legal_entity_edrpou->setObjectName(QStringLiteral("lineEdit_7_legal_entity_edrpou"));
        lineEdit_7_legal_entity_edrpou->setGeometry(QRect(120, 40, 150, 25));
        lineEdit_8_legal_entity_telephone = new QLineEdit(legal_entity);
        lineEdit_8_legal_entity_telephone->setObjectName(QStringLiteral("lineEdit_8_legal_entity_telephone"));
        lineEdit_8_legal_entity_telephone->setGeometry(QRect(120, 100, 150, 25));
        person_entity = new QWidget(widget_contragent);
        person_entity->setObjectName(QStringLiteral("person_entity"));
        person_entity->setGeometry(QRect(20, 30, 281, 175));
        label_20_person_entity_name = new QLabel(person_entity);
        label_20_person_entity_name->setObjectName(QStringLiteral("label_20_person_entity_name"));
        label_20_person_entity_name->setGeometry(QRect(20, 10, 101, 30));
        label_20_person_entity_name->setFont(font3);
        label_21_person_entity_date_birth = new QLabel(person_entity);
        label_21_person_entity_date_birth->setObjectName(QStringLiteral("label_21_person_entity_date_birth"));
        label_21_person_entity_date_birth->setGeometry(QRect(20, 40, 101, 30));
        label_21_person_entity_date_birth->setFont(font3);
        label_22_person_entity_telephone = new QLabel(person_entity);
        label_22_person_entity_telephone->setObjectName(QStringLiteral("label_22_person_entity_telephone"));
        label_22_person_entity_telephone->setGeometry(QRect(20, 70, 111, 30));
        label_22_person_entity_telephone->setFont(font3);
        lineEdit_9 = new QLineEdit(person_entity);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));
        lineEdit_9->setGeometry(QRect(120, 10, 150, 25));
        lineEdit_10 = new QLineEdit(person_entity);
        lineEdit_10->setObjectName(QStringLiteral("lineEdit_10"));
        lineEdit_10->setGeometry(QRect(120, 70, 150, 25));
        lineEdit_11 = new QDateEdit(person_entity);
        lineEdit_11->setObjectName(QStringLiteral("lineEdit_11"));
        lineEdit_11->setGeometry(QRect(120, 40, 150, 25));
        lineEdit_11->setCalendarPopup(true);
        pushButton_add_new_contragent_2 = new QPushButton(widget_contragent);
        pushButton_add_new_contragent_2->setObjectName(QStringLiteral("pushButton_add_new_contragent_2"));
        pushButton_add_new_contragent_2->setGeometry(QRect(70, 170, 191, 21));
        radioButton_3_person_entity->raise();
        radioButton_4_legal_entity->raise();
        pushButton_add_new_contragent_2->raise();
        legal_entity->raise();
        person_entity->raise();
        lineEdit_2_quantity = new QLineEdit(OrderWindow);
        lineEdit_2_quantity->setObjectName(QStringLiteral("lineEdit_2_quantity"));
        lineEdit_2_quantity->setGeometry(QRect(141, 210, 151, 25));
        lineEdit_3_price = new QLineEdit(OrderWindow);
        lineEdit_3_price->setObjectName(QStringLiteral("lineEdit_3_price"));
        lineEdit_3_price->setGeometry(QRect(141, 240, 150, 25));
        label_14 = new QLabel(OrderWindow);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setEnabled(true);
        label_14->setGeometry(QRect(20, 180, 101, 30));
        label_14->setFont(font3);
        comboBox_4_currency = new QComboBox(OrderWindow);
        comboBox_4_currency->setObjectName(QStringLiteral("comboBox_4_currency"));
        comboBox_4_currency->setEnabled(true);
        comboBox_4_currency->setGeometry(QRect(141, 270, 150, 25));
        dateEdit = new QDateEdit(OrderWindow);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(141, 300, 150, 25));
        dateEdit->setCalendarPopup(true);
        label_7 = new QLabel(OrderWindow);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 300, 130, 30));
        label_7->setFont(font3);
        label_measurement_units = new QLabel(OrderWindow);
        label_measurement_units->setObjectName(QStringLiteral("label_measurement_units"));
        label_measurement_units->setGeometry(QRect(270, 210, 47, 21));
        ErrorLabel_Order = new QLabel(OrderWindow);
        ErrorLabel_Order->setObjectName(QStringLiteral("ErrorLabel_Order"));
        ErrorLabel_Order->setEnabled(false);
        ErrorLabel_Order->setGeometry(QRect(320, 300, 341, 121));
        QFont font5;
        font5.setItalic(true);
        ErrorLabel_Order->setFont(font5);
        ErrorLabel_Order->setLocale(QLocale(QLocale::Ukrainian, QLocale::Ukraine));
        ErrorLabel_Order->setScaledContents(false);
        ErrorLabel_Order->setWordWrap(false);
        lineEdit_name_commodity = new QLineEdit(OrderWindow);
        lineEdit_name_commodity->setObjectName(QStringLiteral("lineEdit_name_commodity"));
        lineEdit_name_commodity->setGeometry(QRect(140, 180, 151, 25));
        lineEdit_contragent = new QLineEdit(OrderWindow);
        lineEdit_contragent->setObjectName(QStringLiteral("lineEdit_contragent"));
        lineEdit_contragent->setGeometry(QRect(120, 50, 201, 25));
        widget_new_order = new QWidget(OrderWindow);
        widget_new_order->setObjectName(QStringLiteral("widget_new_order"));
        widget_new_order->setGeometry(QRect(680, 40, 265, 391));
        label_widget_new_order = new QLabel(widget_new_order);
        label_widget_new_order->setObjectName(QStringLiteral("label_widget_new_order"));
        label_widget_new_order->setGeometry(QRect(50, 0, 181, 30));
        label_widget_new_order->setFont(font);
        tableWidget_new_order = new QTableWidget(widget_new_order);
        if (tableWidget_new_order->columnCount() < 2)
            tableWidget_new_order->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_new_order->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_new_order->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget_new_order->setObjectName(QStringLiteral("tableWidget_new_order"));
        tableWidget_new_order->setGeometry(QRect(0, 30, 265, 361));
        tableWidget_new_order->horizontalHeader()->setDefaultSectionSize(130);

        retranslateUi(OrderWindow);
        QObject::connect(buttonBox, SIGNAL(accepted()), OrderWindow, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), OrderWindow, SLOT(reject()));

        QMetaObject::connectSlotsByName(OrderWindow);
    } // setupUi

    void retranslateUi(QDialog *OrderWindow)
    {
        OrderWindow->setWindowTitle(QApplication::translate("OrderWindow", "\320\227\320\260\320\274\320\276\320\262\320\273\320\265\320\275\320\275\321\217", 0));
        label->setText(QApplication::translate("OrderWindow", "\320\227\320\260\320\274\320\276\320\262\320\273\320\265\320\275\320\275\321\217", 0));
        label_2->setText(QApplication::translate("OrderWindow", "\320\232\320\276\320\275\321\202\321\200\320\260\320\263\320\265\320\275\321\202", 0));
        pushButton_add_new_contragent->setText(QApplication::translate("OrderWindow", "\320\224\320\276\320\264\320\260\321\202\320\270 \320\275\320\276\320\262\320\276\320\263\320\276 \320\272\320\276\320\275\321\202\321\200\320\260\320\263\320\265\320\275\321\202\320\260", 0));
        radioButton_sale->setText(QApplication::translate("OrderWindow", "\320\237\321\200\320\276\320\264\320\260\320\266", 0));
        radioButton_2_buy->setText(QApplication::translate("OrderWindow", "\320\237\320\276\320\272\321\203\320\277\320\272\320\260", 0));
        label_3->setText(QApplication::translate("OrderWindow", "\320\241\320\277\320\270\321\201\320\276\320\272 \321\202\320\276\320\262\320\260\321\200\321\226\320\262", 0));
        label_4->setText(QApplication::translate("OrderWindow", "\320\232\321\226\320\273\321\214\320\272\321\226\321\201\321\202\321\214", 0));
        label_5->setText(QApplication::translate("OrderWindow", "\320\246\321\226\320\275\320\260 \320\267\320\260 \320\276\320\264\320\275\320\270\321\206\321\216", 0));
        label_6->setText(QApplication::translate("OrderWindow", "\320\222\320\260\320\273\321\216\321\202\320\260", 0));
        pushButton_2_add_next_commodity->setText(QApplication::translate("OrderWindow", "\320\224\320\276\320\264\320\260\321\202\320\270 \320\275\320\260\321\201\321\202\321\203\320\277\320\275\320\270\320\271 \321\202\320\276\320\262\320\260\321\200", 0));
        radioButton_3_person_entity->setText(QApplication::translate("OrderWindow", "\320\244\321\226\320\267_\320\276\321\201\320\276\320\261\320\260", 0));
        radioButton_4_legal_entity->setText(QApplication::translate("OrderWindow", "\320\256\321\200_\320\276\321\201\320\276\320\261\320\260", 0));
        label_9->setText(QApplication::translate("OrderWindow", "\320\235\320\260\320\267\320\262\320\260", 0));
        label_10->setText(QApplication::translate("OrderWindow", "\320\204\320\224\320\240\320\237\320\236\320\243*", 0));
        label_11->setText(QApplication::translate("OrderWindow", "\320\206\320\264\320\265\320\275\321\202. \320\272\320\276\320\264*", 0));
        label_12->setText(QApplication::translate("OrderWindow", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275*", 0));
        label_20_person_entity_name->setText(QApplication::translate("OrderWindow", "\320\237\320\206\320\221", 0));
        label_21_person_entity_date_birth->setText(QApplication::translate("OrderWindow", "\320\224\320\260\321\202\320\260 \320\275\320\260\321\200.*", 0));
        label_22_person_entity_telephone->setText(QApplication::translate("OrderWindow", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275*", 0));
        lineEdit_11->setDisplayFormat(QApplication::translate("OrderWindow", "dd/MM/yyyy", 0));
        pushButton_add_new_contragent_2->setText(QApplication::translate("OrderWindow", "\320\224\320\276\320\264\320\260\321\202\320\270", 0));
        label_14->setText(QApplication::translate("OrderWindow", "\320\235\320\260\320\267\320\262\320\260 \321\202\320\276\320\262\320\260\321\200\321\203", 0));
        dateEdit->setDisplayFormat(QApplication::translate("OrderWindow", "dd/MM/yyyy", 0));
        label_7->setText(QApplication::translate("OrderWindow", "\320\224\320\260\321\202\320\260 \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\320\275\321\217", 0));
        label_measurement_units->setText(QString());
        ErrorLabel_Order->setText(QApplication::translate("OrderWindow", "<html><head/><body><p><br/></p></body></html>", 0));
        label_widget_new_order->setText(QApplication::translate("OrderWindow", "\320\235\320\276\320\262\320\265 \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\320\275\321\217", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_new_order->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("OrderWindow", "\320\235\320\260\320\267\320\262\320\260 \321\202\320\276\320\262\320\260\321\200\321\203", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_new_order->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("OrderWindow", "\320\232\321\226\320\273\321\214\320\272\321\226\321\201\321\202\321\214", 0));
    } // retranslateUi

};

namespace Ui {
    class OrderWindow: public Ui_OrderWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDERWINDOW_H
