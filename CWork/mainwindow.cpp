#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loginwindow.h"
#include "orderwindow.h"
#include "employeewindow.h"
#include "commodity.h"
#include "filterwindow.h"
#include "informationwindow.h"
#include "working_off.h"
#include <QResource>
#include <QMessageBox>
// #include "ncreport.h"
// #include "ncreportoutput.h"
// #include "ncreportpreviewoutput.h"
// #include "ncreportpreviewwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    QString El = "";
    db=QSqlDatabase::addDatabase("QPSQL");
    showLoginWindow();
//    login = "odmen";
    pw = "q";
    ip = "127.0.0.1";
    port = "5432";

    connectUser();
    QString role = getRole();
    if (role == "Merchant") initMerchant();
    if (role == "HRs") initHR();
    if (login == "odmen") initAdmin();

}

MainWindow::~MainWindow()
{
    db.close();
    delete ui;
}

int MainWindow::initMerchant(){
    int row = 0, col = 0;
    ui->hr_w->setVisible(false);
    ui->admin_w->setVisible(false);
    ui->commodity_movement_tv->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
    QString query;
    refreshMerch();
    connect(ui->refresh_merch_w, SIGNAL(clicked()), this, SLOT(refreshMerch()));
    connect(ui->add_or_merch_w, SIGNAL(clicked()), this, SLOT(showOrderWindow()));
    connect(ui->add_com_merch_w, SIGNAL(clicked()), this, SLOT(showCommodityWindow()));
    connect(ui->allFields_merch_w, SIGNAL(clicked()), this, SLOT(showFilter()));
    connect(ui->commodity_tv, SIGNAL(cellDoubleClicked(int, int)), this,
            SLOT(showInfo(int, int)));
    // connect(ui->report_merch_w, SIGNAL(clicked()), this, SLOT(showReportMerch()));

    return 0;
}
int MainWindow::initHR(){
    ui->merch_w->setVisible(false);
    ui->admin_w->setVisible(false);
    ui->department_tv->resizeColumnsToContents();
    ui->position_tv->resizeColumnsToContents();
    ui->movement_of_position_tv->resizeColumnsToContents();
    ui->employee_tv->resizeColumnsToContents();
    ui->working_off_tv->resizeColumnsToContents();
    refreshHR();
    // connect(ui->rep_hr, SIGNAL(clicked()), this, SLOT(showReportHR()));
    connect(ui->refresh, SIGNAL(clicked()), this, SLOT(refreshHR()));
    connect(ui->add_hr, SIGNAL(clicked()), this, SLOT(showEmployeeWindow()));
    connect(ui->allFields_hr, SIGNAL(clicked()), this, SLOT(showFilter()));
    connect(ui->department_tv, SIGNAL(cellDoubleClicked(int, int)), this,
            SLOT(showInfo(int, int)));
    connect(ui->upd_b_5, SIGNAL(clicked()), this, SLOT(showWoff()));
    return 0;

}
int MainWindow::initAdmin(){
    ui->hr_w->setVisible(false);
    ui->merch_w->setVisible(false);
    refreshAdmin("", "");
    connect(ui->admin_w_refresh, SIGNAL(clicked()), this, SLOT(refreshAdmin()));
    connect(ui->admin_w_filter, SIGNAL(clicked()), this, SLOT(filterAdmin()));
    connect(ui->admin_w_add, SIGNAL(clicked()), this, SLOT(addRowAdmin()));
    connect(ui->admin_w_download, SIGNAL(clicked()), this, SLOT(submitAdmin()));

    return 0;
}

int MainWindow::showLoginWindow(){
    QString El;
    while (1){
        LoginWindow d(this, El);
        d.show();
        int dres = d.exec();
        if(dres == QDialog::Accepted){
            login = d.getLogin();
            pw = d.getPw();
            ip = d.getIP();
            port = d.getPort();
            if (connectUser()){
                return 0;
            }
            else
                El = "<html><head/><body><p style=\"color:red;\">"
                     "Помилка: Користувача з даним логіном/паролем в <br>"
                     "заданій базі данних не знайдено</p></body></html>";
        }
        if(dres == QDialog::Rejected){
            QApplication::quit();
            break;
        }
    }
    return 1;
}
int MainWindow::showOrderWindow(){
    OrderWindow ow(this, db);
    ow.setModal(true);
    ow.show();
    int owres = ow.exec();
    return 0;
}
int MainWindow::showCommodityWindow(){
    commodity cw(this, db);
    cw.setModal(true);
    cw.show();
    int cwres = cw.exec();
    return 0;
}
int MainWindow::showEmployeeWindow(){
    EmployeeWindow ew(this, db);
    ew.setModal(true);
    ew.show();
    int ewres = ew.exec();
    return 0;
}
int MainWindow::showFilter(){

    QTableWidget* table;

    if (ui->hr_w->isVisible()){
        QString tableName = ui->tables_hr->tabText(ui->tables_hr->currentIndex());
        if (tableName == "Рух посад"){
            table = ui->movement_of_position_tv;
        }
        if (tableName == "Працівники"){
            table = ui->employee_tv;
        }
        if (tableName == "Відпрацювання"){
            table = ui->working_off_tv;
        }
        if (tableName == "Відділ"){
            table = ui->department_tv;
        }
        if (tableName == "Посада"){
            table = ui->position_tv;
        }

        FilterWindow fw(this, tableName, db, table);
        fw.setModal(true);
        fw.show();
        int fwres = fw.exec();
    }
    if (ui->merch_w->isVisible()){
        QString tableName = ui->tables_merch->tabText(ui->tables_merch->currentIndex());
        if (tableName == "Рух товарів"){
            table = ui->commodity_movement_tv;
        }
        if (tableName == "Товари"){
            table = ui->commodity_tv;
        }

        FilterWindow fw(this, tableName, db, table);
        fw.setModal(true);
        fw.show();
        int fwres = fw.exec();
    }
}
int MainWindow::showInfo(int row, int col){
    if (col == 1){
        InformationWindow iw(this, db, ui->commodity_tv->item(row, col)->text());
        iw.show();
        int iwres = iw.exec();

    }
}
int MainWindow::showWoff(){
    working_off wow(this, db);
    wow.setModal(true);
    wow.show();
    int wowres = wow.exec();
    return 0;

}
// // int MainWindow::showReportHR(){

//     QStringList list;
//     QString query = "SELECT e.ename, e.pname, e.dname, p.salary, e.date_of_birth, e.education "
//                     "FROM \"XY\".empl e "
//                     "JOIN \"XY\".position p ON e.pname=p.name "
//                     "WHERE e.pname != ''";
//     QSqlQuery sq = db.exec(query);
//     QString res;
//     while (sq.next()){
//         res = "";
//         for(int i=0; i<6 ;i++)
//             res += sq.value(i).toString() + ";";
//         qDebug() << res;
//         list << res;
//     }
//     // NCReport *report = new NCReport();

//     // report->setReportFile("report.xml");
//     report->addStringList(list, "model1");
//     // report->runReportToPreview();
//     if (report->hasError()) {

//         qDebug() << "ERROR:" << report->lastErrorMsg();

//     } else {

//         // NCReportPreviewWindow *pv = new NCReportPreviewWindow();
//         // pv->setOutput( (NCReportPreviewOutput*)report->output() );
//         pv->setWindowModality( Qt::ApplicationModal );
//         pv->setAttribute( Qt::WA_DeleteOnClose );
//         pv->show();
//     }

//     delete report;
// }
// int MainWindow::showReportMerch(){

//     QStringList list;
//     QString query = "SELECT c.id_commodity_movement, c.cname, c.mtname, c.quantity, c.price, c.price * c.quantity "
//                     "FROM \"XY\".comm_mov c;";

//     QSqlQuery sq = db.exec(query);
//     QString res;
//     while (sq.next()){
//         res = "";
//         for(int i=0; i<6 ;i++)
//             res += sq.value(i).toString() + ";";
//         qDebug() << res;
//         list << res;
//     }

//     // NCReport *report = new NCReport();

//    report->setReportSource( NCReportSource::File );
//     // report->setReportFile("report_order.xml");
//     report->addStringList(list, "model1");

//     // report->runReportToPreview();

//     if (report->hasError()) {

//         qDebug() << "ERROR:" << report->lastErrorMsg();

//     } else {

//         // NCReportPreviewWindow *pv = new NCReportPreviewWindow();
//         // pv->setOutput( (NCReportPreviewOutput*)report->output() );
//         pv->setWindowModality( Qt::ApplicationModal );
//         pv->setAttribute( Qt::WA_DeleteOnClose );
//         pv->show();
//     }

//     delete report;
// }
int MainWindow::addRowAdmin(){
    int index = ui->tabWidget_admin_w->currentIndex();
    models[index]->insertRow(0);

}
int MainWindow::submitAdmin(){
    int index = ui->tabWidget_admin_w->currentIndex();
    models[index]->submitAll();
    QString err = models[index]->lastError().text();
    ui->ErrorLabel_admin_w->setText("<html><head/><body><p style=\"color:red;\">"+err+
                                    "</p></body></html>");
}

int MainWindow::refreshMerch(){
    QString query;
    query = "SELECT * FROM \"XY\".comm;";
    fillTable(ui->commodity_tv, query);
    query = "SELECT * from \"XY\".comm_mov;";
    fillTable(ui->commodity_movement_tv, query);
    ui->commodity_tv->resizeColumnsToContents();
    ui->commodity_movement_tv->resizeColumnsToContents();
    return 0;
}
int MainWindow::refreshHR(){

    QString query;
    query = "SELECT * from \"XY\".dept;";
    fillTable(ui->department_tv , query);
    query = "SELECT * from \"XY\".pos;";
    fillTable(ui->position_tv , query);
    query = "SELECT * from \"XY\".mov_pos;";
    fillTable(ui->movement_of_position_tv , query);
    query = "SELECT * from \"XY\".empl;";
    fillTable(ui->employee_tv , query);
    query = "SELECT * from \"XY\".work_off;";
    fillTable(ui->working_off_tv , query);
    ui->department_tv->resizeColumnsToContents();
    ui->position_tv->resizeColumnsToContents();
    ui->movement_of_position_tv->resizeColumnsToContents();
    ui->employee_tv->resizeColumnsToContents();
    ui->working_off_tv->resizeColumnsToContents();
    return 0;
}
int MainWindow::refreshAdmin(QString tableName, QString filter){

    int index = ui->tabWidget_admin_w->currentIndex();
    ui->tabWidget_admin_w->clear();
    QStringList tables = db.tables();
    int *validTbls;
    int ntabs = 0;
    for(int i=1; i<tables.size(); i++){
        tables[i] = "\"XY\".\"" + tables[i].right(tables[i].size() - 3) + "\"";
        if (checkTable(tables[i])){
            int *temp = new int[ntabs + 1];
            memcpy(temp,validTbls, ntabs*sizeof(int));
            temp[ntabs++] = i;
            validTbls = temp;
        }
    }
    QWidget *tabs[ntabs];
    models = new QSqlTableModel*[ntabs];
    for(int i=0; i<ntabs; i++){
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);

        tabs[i] = new QWidget();
        ui->tabWidget_admin_w->addTab(tabs[i], tables[validTbls[i]]);
        tabs[i]->resize(ui->tabWidget_admin_w->size());
        QTableView *table = new QTableView(tabs[i]);
        QSqlTableModel *model = new QSqlTableModel(table, db);
        model->setTable(tables[validTbls[i]]);
        model->setEditStrategy(QSqlTableModel::OnManualSubmit);
        model->select();
        if (tableName == tables[validTbls[i]])
            model->setFilter(filter);
        models[i] = model;
        table->resize(tabs[i]->size());
        table->horizontalHeader()->setStretchLastSection(true);
        table->setModel(model);
        table->resizeColumnsToContents();
        table->show();
    }
    ui->tabWidget_admin_w->setCurrentIndex(index);
}

int MainWindow::checkTable(QString tablename){

    QSqlQuery query = db.exec(QString("SELECT * FROM %1;").arg(tablename));
    if (query.lastError().text() == " ") return 1;
    return 0;
}
int MainWindow::fillTable(QTableWidget *tab, QString query){

    QSqlQuery sq = db.exec(query);
//    qDebug() << sq.lastError();
    int nc = tab->columnCount();
    tab->setRowCount(sq.size());
    sq.first();
    int row = 0;
    do{

        for (int i = 0; i < nc; i++){
            QTableWidgetItem* item = new QTableWidgetItem();
            item->setText(sq.value(i).toString());
            tab->setItem(row, i, item);
        }
        row++;
    }
    while (sq.next());
    tab->resizeColumnsToContents();
    return 0;
}
int MainWindow::filterAdmin(){
    refreshAdmin(ui->tabWidget_admin_w->tabText(ui->tabWidget_admin_w->currentIndex()),
                 ui->lineEdit->text());
}

QString MainWindow::getRole(){
    QSqlQuery sq = db.exec(QString("select rolname from pg_user\
                            join pg_auth_members on (pg_user.usesysid=pg_auth_members.member)\
                            join pg_roles on (pg_roles.oid=pg_auth_members.roleid)\
                            where pg_user.usename='%1';").arg(login));

    sq.first();
    return sq.value(0).toString();
}
int MainWindow::connectUser(){

    db.setHostName(ip);
    db.setPort(port.toInt());
    db.setDatabaseName("cwork");
    db.setUserName(login);
    db.setPassword(pw);
    if(db.open()){
        return 1;
    }
    qDebug() << db.lastError();
    return 0;
}
