#include "counteragent.h"
#include "ui_counteragent.h"

CounterAgent::CounterAgent(QWidget *parent, QSqlDatabase db1) :
    QDialog(parent),
    ui(new Ui::CounterAgent)
{
    ui->setupUi(this);
    mydb = db1;
}
CounterAgent::~CounterAgent()
{
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

    qDebug() << date;

//    if ((name!="") && (name.length()<50)){
//        db.exec(QString("INSERT INTO \"XY\".person_entity (name, date_of_birth, telephone)"
//                        "VALUES ('%1', %2, %3);").arg(name,
//                                                        datebirth=="" ? "NULL" : "'"+datebirth+"'",
//                                                        tel=="" ? "NULL" : "'"+tel+"'"));
//    clearCA();
//    showCA();
//    ui->lineEdit_contragent->setText(name);
//    }
//    else
//        err = "Ім’я контрагента не задано";


    QSqlQuery qry =mydb.exec(QString("INSERT INTO \"HappyCake_main\".physical_face (surname, name, date_of_birth, address, telephone_number) "
                                     "VALUES ('%1','%2','%3','%4','%5')").arg(surname, name, date, addr, tel));

    if (qry.exec())
            {
                qDebug() << "Done";
            }

            else
                qDebug() << "Error " << mydb.lastError().text();


//    query = QString("UPDATE \"XY\".commodity c "
//                    "SET quantity = quantity + %1"
//                    "WHERE c.name='%2'").arg(quanS, name);

}
