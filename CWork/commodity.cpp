#include "commodity.h"
#include "ui_commodity.h"

commodity::commodity(QWidget *parent, QSqlDatabase db1) :
    QDialog(parent),
    ui(new Ui::commodity)
{
    db = db1;
    ui->setupUi(this);
    ui->widget_add->setVisible(false);
    ui->widget_delete->setVisible(false);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(showAdd()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(showDelete()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(addComm()));


    QSqlQuery sq = db.exec("SELECT tc.name FROM \"XY\".type_commodity tc;");
    ui->comboBox_widget_add_commodity_type_commodity->addItem("");
    while (sq.next())
        ui->comboBox_widget_add_commodity_type_commodity->addItem(sq.value(0).toString());

    sq = db.exec("SELECT mu.name FROM \"XY\".measurement_units mu;");
    ui->comboBox_widget_add_commodity_measurements_units->addItem("");
    while (sq.next())
        ui->comboBox_widget_add_commodity_measurements_units->addItem(sq.value(0).toString());

    sq = db.exec("SELECT c.name FROM \"XY\".commodity c;");
    while (sq.next())
        slComm << sq.value(0).toString();
    QCompleter *copl = new QCompleter(slComm, this);
    copl->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineEdit_widget_delete_commodity_name->setCompleter(copl);
    addComm();

}
commodity::~commodity()
{
    delete ui;
}

int commodity::showAdd(){
    ui->widget_delete->setVisible(false);
    ui->widget_add->setVisible(true);
}
int commodity::showDelete(){
    ui->widget_add->setVisible(false);
    ui->widget_delete->setVisible(true);
}
int commodity::addComm(){
    newMode = !newMode;
    ui->lineEdit_widget_add_commodity_article->setEnabled(newMode);
    ui->comboBox_widget_add_commodity_type_commodity->setEnabled(newMode);
    ui->comboBox_widget_add_commodity_measurements_units->setEnabled(newMode);
    ui->label_3->setEnabled(newMode);
    ui->label_4->setEnabled(newMode);
    ui->label_5->setEnabled(newMode);
    QCompleter *copl;
    if (!newMode)
        copl = new QCompleter(slComm, this);
    else copl = new QCompleter(QStringList(), this);
    copl->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineEdit_widget_add_commodity_name->setCompleter(copl);

}

void commodity::accept(){
    QString err = "";
    QString query = "";
    float quan;
    bool eStF;
    bool ok = true;
    if (ui->widget_add->isVisible()){

        QString name = ui->lineEdit_widget_add_commodity_name->text();
        QString artl = ui->lineEdit_widget_add_commodity_article->text();
        QString quanS = ui->lineEdit_widget_add_commodity_quantity->text();
        QString type = ui->comboBox_widget_add_commodity_type_commodity->currentText();
        QString mtun = ui->comboBox_widget_add_commodity_measurements_units->currentText();
        float quan;
        bool eStF;
        bool ok = true;
        if (name==""){
            ok = false;
            err += "Назва товару не задана<br>";
        }
        qDebug() << err;

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

        if (newMode){
            if (slComm.contains(name, Qt::CaseInsensitive)){
                ok = false;
                err += "Товар з такою назвою вже є в базі данних<br>";
            }
            if (artl==""){
                ok = false;
                err += "Артикул не заданий<br>";
            }
            if (type==""){
                ok = false;
                err += "Тип товару не заданий<br>";
            }
            if (mtun==""){
                ok = false;
                err += "Одиниці вимірювання не задані<br>";
            }
        }
        else
            if (!slComm.contains(name)){
                ok = false;
                err += "Товар з таким ім’ям відсутній в базі данних<br>";
            }

        if (ok && newMode){
            query = QString("INSERT INTO \"XY\".commodity "
                            "(name, article, quantity, id_type_commodity, id_measurement_units)"
                            "SELECT '%1', '%2', '%3',"
                            "(SELECT tc.id_type_commodity FROM \"XY\".type_commodity tc "
                            "                                       WHERE tc.name='%4'), "
                            "(SELECT mu.id_measurement_units FROM \"XY\".measurement_units mu "
                            "                                    WHERE mu.name='%5');").arg(name,
                                                                                            artl,
                                                                                            quanS,
                                                                                            type,
                                                                                            mtun);
            db.exec(query);
            qDebug() << db.lastError();
        }
        if (ok && !newMode){
            query = QString("UPDATE \"XY\".commodity c "
                            "SET quantity = quantity + %1"
                            "WHERE c.name='%2'").arg(quanS, name);
            db.exec(query);
            qDebug() << db.lastError();
        }
        if (ok && quan > 0){
            query = QString("INSERT INTO \"XY\".commodity_movement "
                            "(id_contragent, quantity, price, id_currency, date_m, "
                            " id_movement_type, id_commodity) "
                            "SELECT 10, %1, 0, 4, now(), 4 ,"
                            "(SELECT c.id_commodity FROM \"XY\".commodity c "
                            "   WHERE c.name = '%2')").arg(quanS, name);
            db.exec(query);
            qDebug() << db.lastError();
            QDialog::accept();
        }
    }
    if (ui->widget_delete->isVisible()){
        QString name = ui->lineEdit_widget_delete_commodity_name->text();
        QString quanS = ui->lineEdit_widget_delete_commodity_quantity->text();
        if (name==""){
            ok = false;
            err += "Назва товару не задана<br>";
        }
        else if (!slComm.contains(name, Qt::CaseInsensitive)){
            ok = false;
            err += "Товару з такою назвою в базі данних немає<br>";
        }
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
        if (ok){
            query = QString("UPDATE \"XY\".commodity c SET "
                            "quantity = quantity - %1 "
                            "WHERE c.name='%2';").arg(quanS, name);
            db.exec(query);
            QString errCode = db.lastError().nativeErrorCode();
            qDebug() << db.lastError();
            ok = false;
            if (errCode == "23502")
                err += "Контрагента або товару з таким іменем не існує<br>";
            else
                if (errCode == "P0001")
                    err += "Недостатньо товару на складі<br>";
                else
                    ok = true;
        }
        if (ok && quan > 0){
            query = QString("INSERT INTO \"XY\".commodity_movement "
                            "(id_contragent, quantity, price, id_currency, date_m, "
                            " id_movement_type, id_commodity) "
                            "SELECT 14, %1, 0, 4, now(), 3 ,"
                            "(SELECT c.id_commodity FROM \"XY\".commodity c "
                            "   WHERE c.name = '%2')").arg(quanS, name);
            db.exec(query);
            qDebug() << db.lastError();
            QDialog::accept();
        }


    }
    qDebug() << err;
    ui->ErrorLabel_commodity->clear();
    ui->ErrorLabel_commodity->setText("<html><head/><body><p style=\"color:red;\">"+err+
                                      "</p></body></html>");
}

