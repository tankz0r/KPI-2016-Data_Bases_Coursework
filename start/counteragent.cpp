#include "counteragent.h"
#include "ui_counteragent.h"
#include "documbuy.h"
#include "test.h"

CounterAgent::CounterAgent(QWidget *parent, QSqlDatabase db1) :
    QDialog(parent),
    ui(new Ui::CounterAgent)
{

    ui->setupUi(this);
    mydb = db1;
    for (int i = 0; i < ui->tableWidget->horizontalHeader()->count(); ++i)
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);

    QRegExp reg_for_string, reg_for_numbers;
    reg_for_string.setPattern(QString("[а-яА-Я]+"));
    reg_for_numbers.setPattern(QString("[0-9]+"));
    QRegExpValidator *validator_for_string = new QRegExpValidator(reg_for_string, this);
    QRegExpValidator *validator_for_numbers = new QRegExpValidator(reg_for_numbers, this);


    QRegExp reg(QString("^[A-zА-я ,.'- ]+$/i"));
    //QRegExp reg(QString("^\t"));

//    QRegExp reg_for_string;
//    reg_for_string.setPattern(QString("[\\W]*"));
//    QRegExpValidator *validator_for_string = new QRegExpValidator(reg_for_string, this);
//    ui->lineEdit->setValidator(validator_for_string);

    ui->lineEdit->setValidator(new QRegExpValidator(reg,this));
    ui->lineEdit_2->setValidator(new QRegExpValidator(reg,this));
    ui->lineEdit_4->setValidator(new QRegExpValidator(reg,this));
    ui->lineEdit_5->setValidator(new QIntValidator(this));

    ui->lineEdit_5_legal_entity_name->setValidator(new QRegExpValidator(reg,this));
    ui->lineEdit_7_legal_entity_addr->setValidator(new QRegExpValidator(reg,this));
    ui->lineEdit_6_legal_entity_id_code->setValidator(new QIntValidator(this));
    ui->lineEdit_8_legal_entity_telephone->setValidator(new QIntValidator(this));


}
CounterAgent::~CounterAgent()
{
    qDebug() << "DESTRUCTOR";
    delete ui;
}

void CounterAgent::on_pushButton_3_clicked()
{
    QString name, surname, tel, addr, date;

    name = ui->lineEdit->text();
    surname = ui->lineEdit_2->text();
    date = ui->dateEdit->text();
    addr = ui->lineEdit_4->text();
    tel = ui->lineEdit_5->text();


    QString err = "";
    bool ok = true;

    if ((name=="") || (name.length()>20))
    {
        ok = false;
        err += "Ім’я задано не коректно<br>";
    }

    if ((surname=="") || (surname.length()>20))
    {
        ok = false;
        err += "Прізвище задано не коректно<br>";
    }

    if ((addr=="") || (addr.length()>20))
    {
        ok = false;
        err += "Адреса задано не коректно<br>";
    }

    if ((tel=="") || (tel.length()>10))
    {
        ok = false;
        err += "Телефон задано не коректно<br>";
    }

    if (ok)
    {
        QSqlQuery qry =mydb.exec(QString("INSERT INTO \"HappyCake_main\".physical_face (surname, name, date_of_birth, address, telephone_number) "
                                     "VALUES ('%1','%2','%3','%4','%5')").arg(surname, name, date, addr, tel));

        ui->lineEdit->setText("");
        ui->lineEdit_2->setText("");
        ui->lineEdit_4->setText("");
        ui->lineEdit_5->setText("");
    }

    ui->ErrorLabel_Order_2->setText("<html><head/><body><p style=\"color:red;\">"+err+
                                  "</p></body></html>");

   //    if (qry.exec())
   //            {
   //                qDebug() << "Done";
   //            }

   //            else
   //                qDebug() << "Error " << mydb.lastError().text();

}

int CounterAgent::fillTable(QTableWidget *tab, QString query)
{
    QSqlQuery sq = mydb.exec(query);
    //qDebug() << "FILL THE TABLE"<< sq.lastError();
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

void CounterAgent::on_pushButton_4_clicked()
{
    QString name, ind_code, tel, addr;

    name = ui->lineEdit_5_legal_entity_name->text();
    ind_code = ui->lineEdit_6_legal_entity_id_code->text();
    addr = ui->lineEdit_7_legal_entity_addr->text();
    tel = ui->lineEdit_8_legal_entity_telephone->text();

    QString err = "";
    bool ok = true;

    if ((name=="") || (name.length()>20))
    {
        ok = false;
        err += "Ім’я задано не коректно<br>";
    }

    if ((ind_code=="") || (ind_code.length()>10))
    {
        ok = false;
        err += "Ідентифікаційний код задано не коректно<br>";
    }

    if ((addr=="") || (addr.length()>20))
    {
        ok = false;
        err += "Адреса задано не коректно<br>";
    }

    if ((tel=="") || (tel.length()>10))
    {
        ok = false;
        err += "Телефон задано не коректно<br>";
    }

    if (ok)
    {

        QSqlQuery qry =mydb.exec(QString("INSERT INTO \"HappyCake_main\".corporate_face (company_name, identification_code, telefon_number, adress) "
                                         "VALUES ('%1','%2','%3','%4')").arg( name, ind_code, tel, addr));


    }


    ui->ErrorLabel_Order->setText("<html><head/><body><p style=\"color:red;\">"+err+
                                  "</p></body></html>");
}

void CounterAgent::on_pushButton_5_clicked()
{
     QString query = "select * from \"HappyCake_main\".\"members_\"";
     fillTable(ui->tableWidget, query);
     for (int i = 0; i < ui->tableWidget->horizontalHeader()->count(); ++i)
         ui->tableWidget->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);
}

void CounterAgent::on_pushButton_2_clicked()
{
    QItemSelectionModel *select = ui->tableWidget->selectionModel();
    QString name = select->selectedIndexes().value(0).data().toString();
    qDebug()<< name;
    b = name;
   // documbuy::statVar = "It works";
    onButtonSend(name);
    close();
}

void CounterAgent::onButtonSend(QString text)
{
    // вызываем сигнал, в котором передаём введённые данные
    emit sendData(text);
}
