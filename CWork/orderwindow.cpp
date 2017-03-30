#include "orderwindow.h"
#include "ui_orderwindow.h"

OrderWindow::OrderWindow(QWidget *parent, QSqlDatabase db1) :
    QDialog(parent),
    ui(new Ui::OrderWindow)
{
    ui->setupUi(this);
    db = db1;
    ui->widget_contragent->setVisible(false);
    ui->person_entity->setVisible(false);
    ui->legal_entity->setVisible(false);
    connect(ui->pushButton_add_new_contragent, SIGNAL(clicked()), this, SLOT(showCA()));
    connect(ui->radioButton_3_person_entity, SIGNAL(clicked()), this, SLOT(showPE()));
    connect(ui->radioButton_4_legal_entity, SIGNAL(clicked()), this, SLOT(showLE()));
    connect(ui->pushButton_add_new_contragent_2, SIGNAL(clicked()), this, SLOT(addCA()));
    connect(ui->pushButton_2_add_next_commodity, SIGNAL(clicked()), this, SLOT(submitComm()));

    QStringList slComm;

    QSqlQuery sq = db.exec("SELECT c.name FROM \"XY\".commodity c;");
    while (sq.next())
        slComm << sq.value(0).toString();
    QCompleter *copl = new QCompleter(slComm, this);
    copl->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineEdit_name_commodity->setCompleter(copl);


    sq = db.exec("SELECT c.name FROM \"XY\".currency c;");
//    qDebug() << sq.lastError();
    ui->comboBox_4_currency->addItem("");
    while (sq.next())
        ui->comboBox_4_currency->addItem(sq.value(0).toString());

    refreshCA();
}
int OrderWindow::showCA(){
    if (ui->lineEdit_contragent->isEnabled()){
        ui->pushButton_add_new_contragent->setText("Відміна");
        ui->widget_contragent->setVisible(true);
        ui->lineEdit_contragent->setEnabled(false);
    }
    else {
        ui->pushButton_add_new_contragent->setText("Додати нового контрагента");
        ui->widget_contragent->setVisible(false);
        ui->lineEdit_contragent->setEnabled(true);
    }
    return 0;
}
int OrderWindow::showPE(){
    ui->person_entity->setVisible(true);
    ui->legal_entity->setVisible(false);
    return 0;
}
int OrderWindow::showLE(){
    ui->legal_entity->setVisible(true);
    ui->person_entity->setVisible(false);
    return 0;
}
void OrderWindow::accept(){
    if (!submitComm()) QDialog::accept();
}
OrderWindow::~OrderWindow()
{
    delete ui;
}
int OrderWindow::addCA(){
    QString name, tel, edrpuo, id_code, datebirth, err;
    if (ui->radioButton_3_person_entity->isChecked()){
       name = ui->lineEdit_9->text();
       datebirth = ui->lineEdit_11->text();
       tel = ui->lineEdit_10->text();
       if ((name!="") && (name.length()<50)){
           db.exec(QString("INSERT INTO \"XY\".person_entity (name, date_of_birth, telephone)"
                           "VALUES ('%1', %2, %3);").arg(name,
                                                           datebirth=="" ? "NULL" : "'"+datebirth+"'",
                                                           tel=="" ? "NULL" : "'"+tel+"'"));
       clearCA();
       showCA();
       ui->lineEdit_contragent->setText(name);
       }
       else
           err = "Ім’я контрагента не задано";
//       qDebug() << db.lastError();
    }
    if (ui->radioButton_4_legal_entity->isChecked()){
       name = ui->lineEdit_5_legal_entity_name->text();
       id_code = ui->lineEdit_6_legal_entity_id_code->text();
       tel = ui->lineEdit_8_legal_entity_telephone->text();
       edrpuo = ui->lineEdit_7_legal_entity_edrpou->text();
       if ((name!="") && (name.length()<50)){
           db.exec(QString("INSERT INTO \"XY\".legal_entity (name, edrpou, identification_code, telephone)"
                           "VALUES ('%1', '%2', '%3', '%4');").arg(name, edrpuo, id_code, tel));
           clearCA();
           showCA();
           ui->lineEdit_contragent->setText(name);
       }
       else
           err = "Ім’я контрагента не задано";
//       qDebug() << db.lastError();
        }
    ui->ErrorLabel_Order->setText("<html><head/><body><p style=\"color:red;\">"+err+
                                     "</p></body></html>");
    refreshCA();
}
int OrderWindow::refreshCA(){
    ui->lineEdit_contragent->clear();
    QStringList slCa;
    QSqlQuery sq = db.exec("SELECT concat(pe.name, le.name) FROM \"XY\".conteragent ca "
                 "LEFT JOIN \"XY\".person_entity pe ON pe.id_contragent = ca.id_contragent "
                 "LEFT JOIN \"XY\".legal_entity le ON le.id_contragent = ca.id_contragent;");
//    qDebug() << sq.lastError();
    while (sq.next())
        slCa << sq.value(0).toString();
    QCompleter *copl = new QCompleter(slCa, this);
    copl->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineEdit_contragent->setCompleter(copl);

}
int OrderWindow::clearCA(){
    ui->lineEdit_5_legal_entity_name->clear();
    ui->lineEdit_6_legal_entity_id_code->clear();
    ui->lineEdit_8_legal_entity_telephone->clear();
    ui->lineEdit_7_legal_entity_edrpou->clear();
    ui->lineEdit_9->clear();
    ui->lineEdit_11->clear();
    ui->lineEdit_10->clear();

}
int OrderWindow::submitComm(){

    QString query;
    QString quanS=ui->lineEdit_2_quantity->text();
    QString pricS=ui->lineEdit_3_price->text();
    QString date= ui->dateEdit->text();
    QString comm= ui->lineEdit_name_commodity->text();
    QString coag= ui->lineEdit_contragent->text();
    QString curr= ui->comboBox_4_currency->currentText();
    QString tmov= ui->radioButton_sale->isChecked() ? "Продаж" :
                                   ui->radioButton_2_buy->isChecked() ? "Покупка" : "";
    QString err = "";
    bool ok = true;
    bool eStF = true;
    float quan;
    float price;
    if (quanS==""){
        ok = false;
        err += "Кількість товару не задана<br>";
    }
    else{
        quan = quanS.toFloat(&eStF);
        if ((quan<0) || !eStF){
            ok = false;
            err += "Кількість товару задана некорректно<br>";
        }
    }
    if (pricS==""){
        ok = false;
        err += "Ціна за одиницю не задана<br>";
    }
    else{
        price = pricS.toFloat(&eStF);
        if ((price<0) || !eStF){
            ok = false;
            err += "Ціна за одиницю заданa некорректно<br>";
        }
    }
    if (date==""){
        ok = false;
        err += "Дата замовлення не задана<br>";
    }
    if (comm==""){
        ok = false;
        err += "Назва товару не задана<br>";
    }
    if (coag==""){
        ok = false;
        err += "Контрагент не заданий<br>";
    }
    if (curr==""){
        ok = false;
        err += "Валюта не задана<br>";
    }
    if (tmov==""){
        ok = false;
        err += "Тип операції не заданий<br>";
    }
    if (ok){
        query = QString("INSERT INTO \"XY\".commodity_movement (quantity, price, date_m, id_commodity,"
                    " id_contragent,  id_currency, id_movement_type)"
                    "SELECT "
                    "%1, "
                    "%2, "
                    "'%3',"
                    "(SELECT c.id_commodity FROM \"XY\".commodity c WHERE c.name='%4'),"
                    "(SELECT ca.id_contragent FROM \"XY\".conteragent ca "
                    "       LEFT JOIN \"XY\".person_entity pe ON pe.id_contragent = ca.id_contragent "
                    "       LEFT JOIN \"XY\".legal_entity le ON le.id_contragent = ca.id_contragent "
                    "   WHERE concat(pe.name, le.name)='%5'),"
                    "(SELECT cr.id_currency FROM \"XY\".currency cr WHERE cr.name='%6'),"
                    "(SELECT mt.id_movement_type FROM \"XY\".movement_type mt "
                    "WHERE mt.name='%7');").arg(quanS, pricS, date, comm, coag, curr, tmov);
        db.exec(query);
        QString errCode = db.lastError().nativeErrorCode();
        qDebug() << db.lastError();
        if (errCode == "23502")
            err += "Контрагента або товару з таким іменем не існує<br>";
        else
            if (errCode == "P0001")
                err += "Недостатньо товару на складі<br>";
            else{
                int row = ui->tableWidget_new_order->rowCount();
                ui->tableWidget_new_order->insertRow(row);
                QTableWidgetItem * name = new QTableWidgetItem(comm);
                ui->tableWidget_new_order->setItem(row, 0, name);
                QTableWidgetItem * quan = new QTableWidgetItem(quanS);
                ui->tableWidget_new_order->setItem(row, 1, quan);

                ui->lineEdit_2_quantity->clear();
                ui->lineEdit_3_price->clear();
                ui->lineEdit_name_commodity->clear();
                ui->comboBox_4_currency->setCurrentText("");

                return 0;
            }
    }
    ui->ErrorLabel_Order->setText("<html><head/><body><p style=\"color:red;\">"+err+
                                  "</p></body></html>");
    return 1;
}
