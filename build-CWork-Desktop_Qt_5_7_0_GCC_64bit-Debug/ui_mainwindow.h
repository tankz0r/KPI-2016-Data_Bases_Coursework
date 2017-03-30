/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *merch_w;
    QPushButton *add_or_merch_w;
    QPushButton *report_merch_w;
    QPushButton *allFields_merch_w;
    QPushButton *add_com_merch_w;
    QTabWidget *tables_merch;
    QWidget *commodity_movement_t;
    QTableWidget *commodity_movement_tv;
    QWidget *commodity_t;
    QTableWidget *commodity_tv;
    QPushButton *refresh_merch_w;
    QWidget *hr_w;
    QPushButton *upd_b_5;
    QPushButton *add_hr;
    QPushButton *rep_hr;
    QPushButton *allFields_hr;
    QTabWidget *tables_hr;
    QWidget *movement_of_position_t;
    QTableWidget *movement_of_position_tv;
    QWidget *employee_t;
    QTableWidget *employee_tv;
    QWidget *working_off_t;
    QTableWidget *working_off_tv;
    QWidget *department_t;
    QTableWidget *department_tv;
    QWidget *position_t;
    QTableWidget *position_tv;
    QPushButton *refresh;
    QWidget *admin_w;
    QPushButton *admin_w_download;
    QPushButton *admin_w_add;
    QTabWidget *tabWidget_admin_w;
    QPushButton *admin_w_refresh;
    QPushButton *admin_w_filter;
    QLineEdit *lineEdit;
    QLabel *ErrorLabel_admin_w;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setMaximumSize(QSize(800, 600));
        MainWindow->setLocale(QLocale(QLocale::Ukrainian, QLocale::Ukraine));
        MainWindow->setToolButtonStyle(Qt::ToolButtonIconOnly);
        MainWindow->setDocumentMode(true);
        MainWindow->setTabShape(QTabWidget::Rounded);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        merch_w = new QWidget(centralWidget);
        merch_w->setObjectName(QStringLiteral("merch_w"));
        merch_w->setGeometry(QRect(0, 0, 800, 600));
        add_or_merch_w = new QPushButton(merch_w);
        add_or_merch_w->setObjectName(QStringLiteral("add_or_merch_w"));
        add_or_merch_w->setGeometry(QRect(10, 460, 140, 40));
        QFont font;
        font.setPointSize(8);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        add_or_merch_w->setFont(font);
        add_or_merch_w->setLocale(QLocale(QLocale::Ukrainian, QLocale::Ukraine));
        report_merch_w = new QPushButton(merch_w);
        report_merch_w->setObjectName(QStringLiteral("report_merch_w"));
        report_merch_w->setGeometry(QRect(10, 510, 140, 40));
        report_merch_w->setFont(font);
        allFields_merch_w = new QPushButton(merch_w);
        allFields_merch_w->setObjectName(QStringLiteral("allFields_merch_w"));
        allFields_merch_w->setGeometry(QRect(160, 510, 140, 40));
        allFields_merch_w->setFont(font);
        allFields_merch_w->setLocale(QLocale(QLocale::Ukrainian, QLocale::Ukraine));
        add_com_merch_w = new QPushButton(merch_w);
        add_com_merch_w->setObjectName(QStringLiteral("add_com_merch_w"));
        add_com_merch_w->setGeometry(QRect(160, 460, 140, 40));
        add_com_merch_w->setFont(font);
        add_com_merch_w->setLocale(QLocale(QLocale::Ukrainian, QLocale::Ukraine));
        tables_merch = new QTabWidget(merch_w);
        tables_merch->setObjectName(QStringLiteral("tables_merch"));
        tables_merch->setGeometry(QRect(0, 0, 800, 400));
        commodity_movement_t = new QWidget();
        commodity_movement_t->setObjectName(QStringLiteral("commodity_movement_t"));
        commodity_movement_t->setLocale(QLocale(QLocale::Ukrainian, QLocale::Ukraine));
        commodity_movement_tv = new QTableWidget(commodity_movement_t);
        if (commodity_movement_tv->columnCount() < 8)
            commodity_movement_tv->setColumnCount(8);
        QFont font1;
        font1.setKerning(false);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font1);
        commodity_movement_tv->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        commodity_movement_tv->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        commodity_movement_tv->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        commodity_movement_tv->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        commodity_movement_tv->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        commodity_movement_tv->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        commodity_movement_tv->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        commodity_movement_tv->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        commodity_movement_tv->setObjectName(QStringLiteral("commodity_movement_tv"));
        commodity_movement_tv->setEnabled(true);
        commodity_movement_tv->setGeometry(QRect(0, 0, 800, 373));
        commodity_movement_tv->setAutoFillBackground(false);
        commodity_movement_tv->setEditTriggers(QAbstractItemView::NoEditTriggers);
        commodity_movement_tv->setDragEnabled(false);
        commodity_movement_tv->setAlternatingRowColors(true);
        commodity_movement_tv->setSortingEnabled(true);
        commodity_movement_tv->setRowCount(0);
        commodity_movement_tv->setColumnCount(8);
        commodity_movement_tv->horizontalHeader()->setCascadingSectionResizes(true);
        commodity_movement_tv->horizontalHeader()->setDefaultSectionSize(100);
        commodity_movement_tv->horizontalHeader()->setMinimumSectionSize(20);
        commodity_movement_tv->horizontalHeader()->setStretchLastSection(true);
        commodity_movement_tv->verticalHeader()->setVisible(false);
        commodity_movement_tv->verticalHeader()->setCascadingSectionResizes(false);
        commodity_movement_tv->verticalHeader()->setDefaultSectionSize(40);
        commodity_movement_tv->verticalHeader()->setProperty("showSortIndicator", QVariant(true));
        tables_merch->addTab(commodity_movement_t, QString());
        commodity_t = new QWidget();
        commodity_t->setObjectName(QStringLiteral("commodity_t"));
        commodity_t->setLocale(QLocale(QLocale::Ukrainian, QLocale::Ukraine));
        commodity_tv = new QTableWidget(commodity_t);
        if (commodity_tv->columnCount() < 6)
            commodity_tv->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setFont(font1);
        commodity_tv->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        commodity_tv->setHorizontalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        commodity_tv->setHorizontalHeaderItem(2, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        commodity_tv->setHorizontalHeaderItem(3, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        commodity_tv->setHorizontalHeaderItem(4, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        commodity_tv->setHorizontalHeaderItem(5, __qtablewidgetitem13);
        commodity_tv->setObjectName(QStringLiteral("commodity_tv"));
        commodity_tv->setGeometry(QRect(0, 0, 800, 373));
        commodity_tv->setMinimumSize(QSize(0, 0));
        commodity_tv->setMaximumSize(QSize(800, 400));
        commodity_tv->setAutoFillBackground(false);
        commodity_tv->setEditTriggers(QAbstractItemView::NoEditTriggers);
        commodity_tv->setDragEnabled(false);
        commodity_tv->setAlternatingRowColors(true);
        commodity_tv->setSortingEnabled(true);
        commodity_tv->setRowCount(0);
        commodity_tv->setColumnCount(6);
        commodity_tv->horizontalHeader()->setCascadingSectionResizes(true);
        commodity_tv->horizontalHeader()->setDefaultSectionSize(120);
        commodity_tv->horizontalHeader()->setMinimumSectionSize(25);
        commodity_tv->horizontalHeader()->setStretchLastSection(true);
        commodity_tv->verticalHeader()->setVisible(false);
        commodity_tv->verticalHeader()->setCascadingSectionResizes(false);
        commodity_tv->verticalHeader()->setDefaultSectionSize(40);
        commodity_tv->verticalHeader()->setProperty("showSortIndicator", QVariant(true));
        tables_merch->addTab(commodity_t, QString());
        refresh_merch_w = new QPushButton(merch_w);
        refresh_merch_w->setObjectName(QStringLiteral("refresh_merch_w"));
        refresh_merch_w->setGeometry(QRect(310, 510, 140, 40));
        refresh_merch_w->setFont(font);
        refresh_merch_w->setLocale(QLocale(QLocale::Ukrainian, QLocale::Ukraine));
        add_or_merch_w->raise();
        report_merch_w->raise();
        allFields_merch_w->raise();
        add_com_merch_w->raise();
        refresh_merch_w->raise();
        tables_merch->raise();
        hr_w = new QWidget(centralWidget);
        hr_w->setObjectName(QStringLiteral("hr_w"));
        hr_w->setEnabled(true);
        hr_w->setGeometry(QRect(0, 0, 800, 600));
        upd_b_5 = new QPushButton(hr_w);
        upd_b_5->setObjectName(QStringLiteral("upd_b_5"));
        upd_b_5->setGeometry(QRect(160, 460, 140, 40));
        upd_b_5->setFont(font);
        upd_b_5->setLocale(QLocale(QLocale::Ukrainian, QLocale::Ukraine));
        upd_b_5->setAutoDefault(false);
        add_hr = new QPushButton(hr_w);
        add_hr->setObjectName(QStringLiteral("add_hr"));
        add_hr->setGeometry(QRect(10, 460, 140, 40));
        add_hr->setFont(font);
        add_hr->setLocale(QLocale(QLocale::Ukrainian, QLocale::Ukraine));
        rep_hr = new QPushButton(hr_w);
        rep_hr->setObjectName(QStringLiteral("rep_hr"));
        rep_hr->setGeometry(QRect(10, 510, 140, 40));
        rep_hr->setFont(font);
        allFields_hr = new QPushButton(hr_w);
        allFields_hr->setObjectName(QStringLiteral("allFields_hr"));
        allFields_hr->setGeometry(QRect(160, 510, 140, 40));
        allFields_hr->setFont(font);
        allFields_hr->setLocale(QLocale(QLocale::Ukrainian, QLocale::Ukraine));
        tables_hr = new QTabWidget(hr_w);
        tables_hr->setObjectName(QStringLiteral("tables_hr"));
        tables_hr->setGeometry(QRect(0, 0, 800, 400));
        movement_of_position_t = new QWidget();
        movement_of_position_t->setObjectName(QStringLiteral("movement_of_position_t"));
        movement_of_position_t->setLocale(QLocale(QLocale::Ukrainian, QLocale::Ukraine));
        movement_of_position_tv = new QTableWidget(movement_of_position_t);
        if (movement_of_position_tv->columnCount() < 5)
            movement_of_position_tv->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        __qtablewidgetitem14->setFont(font1);
        movement_of_position_tv->setHorizontalHeaderItem(0, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        movement_of_position_tv->setHorizontalHeaderItem(1, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        movement_of_position_tv->setHorizontalHeaderItem(2, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        movement_of_position_tv->setHorizontalHeaderItem(3, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        movement_of_position_tv->setHorizontalHeaderItem(4, __qtablewidgetitem18);
        movement_of_position_tv->setObjectName(QStringLiteral("movement_of_position_tv"));
        movement_of_position_tv->setGeometry(QRect(0, 0, 800, 373));
        movement_of_position_tv->setEditTriggers(QAbstractItemView::NoEditTriggers);
        movement_of_position_tv->setDragEnabled(false);
        movement_of_position_tv->setAlternatingRowColors(true);
        movement_of_position_tv->setSortingEnabled(true);
        movement_of_position_tv->setRowCount(0);
        movement_of_position_tv->setColumnCount(5);
        movement_of_position_tv->horizontalHeader()->setCascadingSectionResizes(true);
        movement_of_position_tv->horizontalHeader()->setDefaultSectionSize(150);
        movement_of_position_tv->horizontalHeader()->setMinimumSectionSize(60);
        movement_of_position_tv->horizontalHeader()->setStretchLastSection(true);
        movement_of_position_tv->verticalHeader()->setVisible(false);
        movement_of_position_tv->verticalHeader()->setCascadingSectionResizes(false);
        movement_of_position_tv->verticalHeader()->setDefaultSectionSize(40);
        movement_of_position_tv->verticalHeader()->setProperty("showSortIndicator", QVariant(true));
        tables_hr->addTab(movement_of_position_t, QString());
        employee_t = new QWidget();
        employee_t->setObjectName(QStringLiteral("employee_t"));
        employee_t->setLocale(QLocale(QLocale::Ukrainian, QLocale::Ukraine));
        employee_tv = new QTableWidget(employee_t);
        if (employee_tv->columnCount() < 9)
            employee_tv->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        __qtablewidgetitem19->setFont(font1);
        employee_tv->setHorizontalHeaderItem(0, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        employee_tv->setHorizontalHeaderItem(1, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        employee_tv->setHorizontalHeaderItem(2, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        employee_tv->setHorizontalHeaderItem(3, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        employee_tv->setHorizontalHeaderItem(4, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        employee_tv->setHorizontalHeaderItem(5, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        employee_tv->setHorizontalHeaderItem(6, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        employee_tv->setHorizontalHeaderItem(7, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        employee_tv->setHorizontalHeaderItem(8, __qtablewidgetitem27);
        employee_tv->setObjectName(QStringLiteral("employee_tv"));
        employee_tv->setGeometry(QRect(0, 0, 800, 373));
        employee_tv->setEditTriggers(QAbstractItemView::NoEditTriggers);
        employee_tv->setDragEnabled(false);
        employee_tv->setAlternatingRowColors(true);
        employee_tv->setSortingEnabled(true);
        employee_tv->setRowCount(0);
        employee_tv->setColumnCount(9);
        employee_tv->horizontalHeader()->setCascadingSectionResizes(true);
        employee_tv->horizontalHeader()->setDefaultSectionSize(90);
        employee_tv->horizontalHeader()->setMinimumSectionSize(20);
        employee_tv->horizontalHeader()->setStretchLastSection(true);
        employee_tv->verticalHeader()->setVisible(false);
        employee_tv->verticalHeader()->setCascadingSectionResizes(false);
        employee_tv->verticalHeader()->setDefaultSectionSize(40);
        employee_tv->verticalHeader()->setProperty("showSortIndicator", QVariant(true));
        tables_hr->addTab(employee_t, QString());
        working_off_t = new QWidget();
        working_off_t->setObjectName(QStringLiteral("working_off_t"));
        working_off_t->setLocale(QLocale(QLocale::Ukrainian, QLocale::Ukraine));
        working_off_tv = new QTableWidget(working_off_t);
        if (working_off_tv->columnCount() < 7)
            working_off_tv->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        __qtablewidgetitem28->setFont(font1);
        working_off_tv->setHorizontalHeaderItem(0, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        working_off_tv->setHorizontalHeaderItem(1, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        working_off_tv->setHorizontalHeaderItem(2, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        working_off_tv->setHorizontalHeaderItem(3, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        working_off_tv->setHorizontalHeaderItem(4, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        working_off_tv->setHorizontalHeaderItem(5, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        working_off_tv->setHorizontalHeaderItem(6, __qtablewidgetitem34);
        working_off_tv->setObjectName(QStringLiteral("working_off_tv"));
        working_off_tv->setGeometry(QRect(0, 0, 800, 373));
        working_off_tv->setEditTriggers(QAbstractItemView::NoEditTriggers);
        working_off_tv->setDragEnabled(false);
        working_off_tv->setAlternatingRowColors(true);
        working_off_tv->setSortingEnabled(true);
        working_off_tv->setRowCount(0);
        working_off_tv->setColumnCount(7);
        working_off_tv->horizontalHeader()->setCascadingSectionResizes(true);
        working_off_tv->horizontalHeader()->setDefaultSectionSize(100);
        working_off_tv->horizontalHeader()->setMinimumSectionSize(20);
        working_off_tv->horizontalHeader()->setStretchLastSection(true);
        working_off_tv->verticalHeader()->setVisible(false);
        working_off_tv->verticalHeader()->setCascadingSectionResizes(false);
        working_off_tv->verticalHeader()->setDefaultSectionSize(40);
        working_off_tv->verticalHeader()->setProperty("showSortIndicator", QVariant(true));
        tables_hr->addTab(working_off_t, QString());
        department_t = new QWidget();
        department_t->setObjectName(QStringLiteral("department_t"));
        department_t->setLocale(QLocale(QLocale::Ukrainian, QLocale::Ukraine));
        department_tv = new QTableWidget(department_t);
        if (department_tv->columnCount() < 3)
            department_tv->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        __qtablewidgetitem35->setFont(font1);
        department_tv->setHorizontalHeaderItem(0, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        department_tv->setHorizontalHeaderItem(1, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        department_tv->setHorizontalHeaderItem(2, __qtablewidgetitem37);
        department_tv->setObjectName(QStringLiteral("department_tv"));
        department_tv->setGeometry(QRect(0, 0, 800, 373));
        department_tv->setEditTriggers(QAbstractItemView::NoEditTriggers);
        department_tv->setDragEnabled(false);
        department_tv->setAlternatingRowColors(true);
        department_tv->setSortingEnabled(true);
        department_tv->setRowCount(0);
        department_tv->setColumnCount(3);
        department_tv->horizontalHeader()->setCascadingSectionResizes(true);
        department_tv->horizontalHeader()->setDefaultSectionSize(100);
        department_tv->horizontalHeader()->setMinimumSectionSize(20);
        department_tv->horizontalHeader()->setStretchLastSection(true);
        department_tv->verticalHeader()->setVisible(false);
        department_tv->verticalHeader()->setCascadingSectionResizes(false);
        department_tv->verticalHeader()->setDefaultSectionSize(40);
        department_tv->verticalHeader()->setProperty("showSortIndicator", QVariant(true));
        tables_hr->addTab(department_t, QString());
        position_t = new QWidget();
        position_t->setObjectName(QStringLiteral("position_t"));
        position_t->setLocale(QLocale(QLocale::Ukrainian, QLocale::Ukraine));
        position_tv = new QTableWidget(position_t);
        if (position_tv->columnCount() < 4)
            position_tv->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        __qtablewidgetitem38->setFont(font1);
        position_tv->setHorizontalHeaderItem(0, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        position_tv->setHorizontalHeaderItem(1, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        position_tv->setHorizontalHeaderItem(2, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        position_tv->setHorizontalHeaderItem(3, __qtablewidgetitem41);
        position_tv->setObjectName(QStringLiteral("position_tv"));
        position_tv->setGeometry(QRect(0, 0, 800, 373));
        position_tv->setEditTriggers(QAbstractItemView::NoEditTriggers);
        position_tv->setDragEnabled(false);
        position_tv->setAlternatingRowColors(true);
        position_tv->setSortingEnabled(true);
        position_tv->setRowCount(0);
        position_tv->setColumnCount(4);
        position_tv->horizontalHeader()->setCascadingSectionResizes(true);
        position_tv->horizontalHeader()->setDefaultSectionSize(100);
        position_tv->horizontalHeader()->setMinimumSectionSize(20);
        position_tv->horizontalHeader()->setStretchLastSection(true);
        position_tv->verticalHeader()->setVisible(false);
        position_tv->verticalHeader()->setCascadingSectionResizes(false);
        position_tv->verticalHeader()->setDefaultSectionSize(40);
        position_tv->verticalHeader()->setProperty("showSortIndicator", QVariant(true));
        tables_hr->addTab(position_t, QString());
        refresh = new QPushButton(hr_w);
        refresh->setObjectName(QStringLiteral("refresh"));
        refresh->setGeometry(QRect(310, 510, 140, 40));
        refresh->setFont(font);
        refresh->setLocale(QLocale(QLocale::Ukrainian, QLocale::Ukraine));
        upd_b_5->raise();
        add_hr->raise();
        rep_hr->raise();
        allFields_hr->raise();
        refresh->raise();
        tables_hr->raise();
        admin_w = new QWidget(centralWidget);
        admin_w->setObjectName(QStringLiteral("admin_w"));
        admin_w->setGeometry(QRect(0, 0, 800, 600));
        admin_w_download = new QPushButton(admin_w);
        admin_w_download->setObjectName(QStringLiteral("admin_w_download"));
        admin_w_download->setGeometry(QRect(160, 410, 140, 40));
        admin_w_download->setFont(font);
        admin_w_download->setLocale(QLocale(QLocale::Ukrainian, QLocale::Ukraine));
        admin_w_add = new QPushButton(admin_w);
        admin_w_add->setObjectName(QStringLiteral("admin_w_add"));
        admin_w_add->setGeometry(QRect(10, 410, 140, 40));
        admin_w_add->setFont(font);
        admin_w_add->setLocale(QLocale(QLocale::Ukrainian, QLocale::Ukraine));
        tabWidget_admin_w = new QTabWidget(admin_w);
        tabWidget_admin_w->setObjectName(QStringLiteral("tabWidget_admin_w"));
        tabWidget_admin_w->setGeometry(QRect(0, 0, 800, 400));
        admin_w_refresh = new QPushButton(admin_w);
        admin_w_refresh->setObjectName(QStringLiteral("admin_w_refresh"));
        admin_w_refresh->setGeometry(QRect(310, 410, 140, 40));
        admin_w_refresh->setFont(font);
        admin_w_refresh->setLocale(QLocale(QLocale::Ukrainian, QLocale::Ukraine));
        admin_w_filter = new QPushButton(admin_w);
        admin_w_filter->setObjectName(QStringLiteral("admin_w_filter"));
        admin_w_filter->setGeometry(QRect(650, 410, 140, 40));
        admin_w_filter->setFont(font);
        admin_w_filter->setLocale(QLocale(QLocale::Ukrainian, QLocale::Ukraine));
        lineEdit = new QLineEdit(admin_w);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(10, 410, 631, 40));
        ErrorLabel_admin_w = new QLabel(admin_w);
        ErrorLabel_admin_w->setObjectName(QStringLiteral("ErrorLabel_admin_w"));
        ErrorLabel_admin_w->setEnabled(false);
        ErrorLabel_admin_w->setGeometry(QRect(10, 510, 761, 65));
        QFont font2;
        font2.setItalic(true);
        ErrorLabel_admin_w->setFont(font2);
        ErrorLabel_admin_w->setLocale(QLocale(QLocale::Ukrainian, QLocale::Ukraine));
        ErrorLabel_admin_w->setScaledContents(false);
        ErrorLabel_admin_w->setWordWrap(false);
        tabWidget_admin_w->raise();
        admin_w_filter->raise();
        lineEdit->raise();
        ErrorLabel_admin_w->raise();
        admin_w_refresh->raise();
        admin_w_download->raise();
        admin_w_add->raise();
        MainWindow->setCentralWidget(centralWidget);
        admin_w->raise();
        hr_w->raise();
        merch_w->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 20));
        menuBar->setDefaultUp(true);
        menuBar->setNativeMenuBar(true);
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tables_merch->setCurrentIndex(1);
        tables_hr->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\250\320\276\320\272\320\276\320\273\320\260\320\264\320\275\320\260 \321\204\320\260\320\261\321\200\320\270\320\272\320\260", 0));
        add_or_merch_w->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\264\320\260\321\202\320\270 \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\320\275\321\217", 0));
        report_merch_w->setText(QApplication::translate("MainWindow", "\320\227\320\262\321\226\321\202", 0));
        allFields_merch_w->setText(QApplication::translate("MainWindow", "\320\244\321\226\320\273\321\214\321\202\321\200\321\203\320\262\320\260\321\202\320\270", 0));
        add_com_merch_w->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\264\320\260\321\202\320\270/\320\222\320\270\320\264\320\260\320\273\320\270\321\202\320\270 \321\202\320\276\320\262\320\260\321\200", 0));
        QTableWidgetItem *___qtablewidgetitem = commodity_movement_tv->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "\342\204\226", 0));
        QTableWidgetItem *___qtablewidgetitem1 = commodity_movement_tv->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\271\320\274\320\265\320\275\321\203\320\262\320\260\320\275\320\275\321\217\n"
"\321\202\320\276\320\262\320\260\321\200\321\203", 0));
        QTableWidgetItem *___qtablewidgetitem2 = commodity_movement_tv->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\275\321\202\321\200\320\260\320\263\320\265\320\275\321\202", 0));
        QTableWidgetItem *___qtablewidgetitem3 = commodity_movement_tv->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "\320\232\321\226\320\273\321\214\320\272\321\226\321\201\321\202\321\214", 0));
        QTableWidgetItem *___qtablewidgetitem4 = commodity_movement_tv->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "\320\236\320\264\320\270\320\275\320\270\321\206\321\226 \n"
"\320\262\320\270\320\274\321\226\321\200\321\216\320\262\320\260\320\275\320\275\321\217", 0));
        QTableWidgetItem *___qtablewidgetitem5 = commodity_movement_tv->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "\320\246\321\226\320\275\320\260 \n"
"\320\267\320\260 \320\276\320\264\320\270\320\275\320\270\321\206\321\216", 0));
        QTableWidgetItem *___qtablewidgetitem6 = commodity_movement_tv->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "\320\222\320\260\320\273\321\216\321\202\320\260", 0));
        QTableWidgetItem *___qtablewidgetitem7 = commodity_movement_tv->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "\320\242\320\270\320\277 \321\200\321\203\321\205\321\203\n"
"\321\202\320\276\320\262\320\260\321\200\321\203", 0));
        tables_merch->setTabText(tables_merch->indexOf(commodity_movement_t), QApplication::translate("MainWindow", "\320\240\321\203\321\205 \321\202\320\276\320\262\320\260\321\200\321\226\320\262", 0));
        QTableWidgetItem *___qtablewidgetitem8 = commodity_tv->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "\342\204\226", 0));
        QTableWidgetItem *___qtablewidgetitem9 = commodity_tv->horizontalHeaderItem(1);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\271\320\274\320\265\320\275\321\203\320\262\320\260\320\275\320\275\321\217\n"
"\321\202\320\276\320\262\320\260\321\200\321\203", 0));
        QTableWidgetItem *___qtablewidgetitem10 = commodity_tv->horizontalHeaderItem(2);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "\320\242\320\270\320\277 \321\202\320\276\320\262\320\260\321\200\321\203", 0));
        QTableWidgetItem *___qtablewidgetitem11 = commodity_tv->horizontalHeaderItem(3);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "\320\232\321\226\320\273\321\214\320\272\321\226\321\201\321\202\321\214", 0));
        QTableWidgetItem *___qtablewidgetitem12 = commodity_tv->horizontalHeaderItem(4);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWindow", "\320\236\320\264\320\270\320\275\320\270\321\206\321\226\n"
"\320\262\320\270\320\274\321\226\321\200\321\216\320\262\320\260\320\275\320\275\321\217", 0));
        QTableWidgetItem *___qtablewidgetitem13 = commodity_tv->horizontalHeaderItem(5);
        ___qtablewidgetitem13->setText(QApplication::translate("MainWindow", "\320\220\321\200\321\202\320\270\320\272\321\203\320\273", 0));
        tables_merch->setTabText(tables_merch->indexOf(commodity_t), QApplication::translate("MainWindow", "\320\242\320\276\320\262\320\260\321\200\320\270", 0));
        refresh_merch_w->setText(QApplication::translate("MainWindow", "\320\236\320\275\320\276\320\262\320\270\321\202\320\270", 0));
        upd_b_5->setText(QApplication::translate("MainWindow", "\320\222\321\226\320\264\320\277\321\200\320\260\321\206\321\216\320\262\320\260\320\275\320\275\321\217", 0));
        add_hr->setText(QApplication::translate("MainWindow", "\320\227\320\274\321\226\320\275\320\270\321\202\320\270 \321\200\320\276\320\261\321\226\321\202\320\275\320\270\320\272\320\260", 0));
        rep_hr->setText(QApplication::translate("MainWindow", "\320\227\320\262\321\226\321\202", 0));
        allFields_hr->setText(QApplication::translate("MainWindow", "\320\244\321\226\320\273\321\214\321\202\321\200\321\203\320\262\320\260\321\202\320\270", 0));
        QTableWidgetItem *___qtablewidgetitem14 = movement_of_position_tv->horizontalHeaderItem(0);
        ___qtablewidgetitem14->setText(QApplication::translate("MainWindow", "\342\204\226", 0));
        QTableWidgetItem *___qtablewidgetitem15 = movement_of_position_tv->horizontalHeaderItem(1);
        ___qtablewidgetitem15->setText(QApplication::translate("MainWindow", "\320\237\320\276\321\201\320\260\320\264\320\260", 0));
        QTableWidgetItem *___qtablewidgetitem16 = movement_of_position_tv->horizontalHeaderItem(2);
        ___qtablewidgetitem16->setText(QApplication::translate("MainWindow", "\320\237\320\206\320\221 \320\277\321\200\320\260\321\206\321\226\320\262\320\275\320\270\320\272\320\260", 0));
        QTableWidgetItem *___qtablewidgetitem17 = movement_of_position_tv->horizontalHeaderItem(3);
        ___qtablewidgetitem17->setText(QApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260 \n"
"\320\277\320\276\321\207\320\260\321\202\320\272\321\203 \321\200\320\276\320\261\320\276\321\202\320\270", 0));
        QTableWidgetItem *___qtablewidgetitem18 = movement_of_position_tv->horizontalHeaderItem(4);
        ___qtablewidgetitem18->setText(QApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260 \n"
"\320\267\320\260\320\272\321\226\320\275\321\207\320\265\320\275\320\275\321\217 \321\200\320\276\320\261\320\276\321\202\320\270", 0));
        tables_hr->setTabText(tables_hr->indexOf(movement_of_position_t), QApplication::translate("MainWindow", "\320\240\321\203\321\205 \320\277\320\276\321\201\320\260\320\264", 0));
        QTableWidgetItem *___qtablewidgetitem19 = employee_tv->horizontalHeaderItem(0);
        ___qtablewidgetitem19->setText(QApplication::translate("MainWindow", "\342\204\226", 0));
        QTableWidgetItem *___qtablewidgetitem20 = employee_tv->horizontalHeaderItem(1);
        ___qtablewidgetitem20->setText(QApplication::translate("MainWindow", "\320\237\320\206\320\221\n"
"\320\277\321\200\320\260\321\206\321\226\320\262\320\275\320\270\320\272\320\260", 0));
        QTableWidgetItem *___qtablewidgetitem21 = employee_tv->horizontalHeaderItem(2);
        ___qtablewidgetitem21->setText(QApplication::translate("MainWindow", "\320\237\320\276\321\201\320\260\320\264\320\260", 0));
        QTableWidgetItem *___qtablewidgetitem22 = employee_tv->horizontalHeaderItem(3);
        ___qtablewidgetitem22->setText(QApplication::translate("MainWindow", "\320\222\321\226\320\264\320\264\321\226\320\273", 0));
        QTableWidgetItem *___qtablewidgetitem23 = employee_tv->horizontalHeaderItem(4);
        ___qtablewidgetitem23->setText(QApplication::translate("MainWindow", "\320\220\320\264\321\200\320\265\321\201\320\260", 0));
        QTableWidgetItem *___qtablewidgetitem24 = employee_tv->horizontalHeaderItem(5);
        ___qtablewidgetitem24->setText(QApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260 \n"
"\320\275\320\260\321\200\320\276\320\264\320\266\320\265\320\275\320\275\321\217", 0));
        QTableWidgetItem *___qtablewidgetitem25 = employee_tv->horizontalHeaderItem(6);
        ___qtablewidgetitem25->setText(QApplication::translate("MainWindow", "\320\236\321\201\320\262\321\226\321\202\320\260", 0));
        QTableWidgetItem *___qtablewidgetitem26 = employee_tv->horizontalHeaderItem(7);
        ___qtablewidgetitem26->setText(QApplication::translate("MainWindow", "\320\224\320\276\321\201\320\262\321\226\320\264", 0));
        QTableWidgetItem *___qtablewidgetitem27 = employee_tv->horizontalHeaderItem(8);
        ___qtablewidgetitem27->setText(QApplication::translate("MainWindow", "\320\241\321\202\320\260\320\262\320\272\320\260", 0));
        tables_hr->setTabText(tables_hr->indexOf(employee_t), QApplication::translate("MainWindow", "\320\237\321\200\320\260\321\206\321\226\320\262\320\275\320\270\320\272\320\270", 0));
        QTableWidgetItem *___qtablewidgetitem28 = working_off_tv->horizontalHeaderItem(0);
        ___qtablewidgetitem28->setText(QApplication::translate("MainWindow", "\342\204\226", 0));
        QTableWidgetItem *___qtablewidgetitem29 = working_off_tv->horizontalHeaderItem(1);
        ___qtablewidgetitem29->setText(QApplication::translate("MainWindow", "\320\237\320\206\320\221 \320\277\321\200\320\260\321\206\321\226\320\262\320\275\320\270\320\272\320\260", 0));
        QTableWidgetItem *___qtablewidgetitem30 = working_off_tv->horizontalHeaderItem(2);
        ___qtablewidgetitem30->setText(QApplication::translate("MainWindow", "\320\237\320\276\321\201\320\260\320\264\320\260", 0));
        QTableWidgetItem *___qtablewidgetitem31 = working_off_tv->horizontalHeaderItem(3);
        ___qtablewidgetitem31->setText(QApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260\n"
" \320\262\321\226\320\264\320\277\321\200\320\260\321\206\321\216\320\262\320\260\320\275\320\275\321\217", 0));
        QTableWidgetItem *___qtablewidgetitem32 = working_off_tv->horizontalHeaderItem(4);
        ___qtablewidgetitem32->setText(QApplication::translate("MainWindow", "\320\232\321\226\320\273\321\214\320\272\321\226\321\201\321\202\321\214 \n"
"\320\263\320\276\320\264\320\270\320\275", 0));
        QTableWidgetItem *___qtablewidgetitem33 = working_off_tv->horizontalHeaderItem(5);
        ___qtablewidgetitem33->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\277\321\200\320\260\321\206\321\216\320\262\320\260\320\275\320\275\321\217", 0));
        QTableWidgetItem *___qtablewidgetitem34 = working_off_tv->horizontalHeaderItem(6);
        ___qtablewidgetitem34->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\274\320\265\320\275\321\202\320\260\321\200", 0));
        tables_hr->setTabText(tables_hr->indexOf(working_off_t), QApplication::translate("MainWindow", "\320\222\321\226\320\264\320\277\321\200\320\260\321\206\321\216\320\262\320\260\320\275\320\275\321\217", 0));
        QTableWidgetItem *___qtablewidgetitem35 = department_tv->horizontalHeaderItem(0);
        ___qtablewidgetitem35->setText(QApplication::translate("MainWindow", "\342\204\226", 0));
        QTableWidgetItem *___qtablewidgetitem36 = department_tv->horizontalHeaderItem(1);
        ___qtablewidgetitem36->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260", 0));
        QTableWidgetItem *___qtablewidgetitem37 = department_tv->horizontalHeaderItem(2);
        ___qtablewidgetitem37->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\275\321\202\321\200\320\260\320\263\320\265\320\275\321\202", 0));
        tables_hr->setTabText(tables_hr->indexOf(department_t), QApplication::translate("MainWindow", "\320\222\321\226\320\264\320\264\321\226\320\273", 0));
        QTableWidgetItem *___qtablewidgetitem38 = position_tv->horizontalHeaderItem(0);
        ___qtablewidgetitem38->setText(QApplication::translate("MainWindow", "\342\204\226", 0));
        QTableWidgetItem *___qtablewidgetitem39 = position_tv->horizontalHeaderItem(1);
        ___qtablewidgetitem39->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260", 0));
        QTableWidgetItem *___qtablewidgetitem40 = position_tv->horizontalHeaderItem(2);
        ___qtablewidgetitem40->setText(QApplication::translate("MainWindow", "\320\236\320\272\320\273\320\260\320\264", 0));
        QTableWidgetItem *___qtablewidgetitem41 = position_tv->horizontalHeaderItem(3);
        ___qtablewidgetitem41->setText(QApplication::translate("MainWindow", "\320\222\321\226\320\264\320\264\321\226\320\273", 0));
        tables_hr->setTabText(tables_hr->indexOf(position_t), QApplication::translate("MainWindow", "\320\237\320\276\321\201\320\260\320\264\320\260", 0));
        refresh->setText(QApplication::translate("MainWindow", "\320\236\320\275\320\276\320\262\320\270\321\202\320\270", 0));
        admin_w_download->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\262\320\260\320\275\321\202\320\260\320\266\320\270\321\202\320\270", 0));
        admin_w_add->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\264\320\260\321\202\320\270", 0));
        admin_w_refresh->setText(QApplication::translate("MainWindow", "\320\236\320\275\320\276\320\262\320\270\321\202\320\270", 0));
        admin_w_filter->setText(QApplication::translate("MainWindow", "\320\244\321\226\320\273\321\214\321\202\321\200\321\203\320\262\320\260\321\202\320\270", 0));
        ErrorLabel_admin_w->setText(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
