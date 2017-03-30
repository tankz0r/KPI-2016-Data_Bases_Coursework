#include "informationwindow.h"
#include "ui_informationwindow.h"

InformationWindow::InformationWindow(QWidget *parent, QSqlDatabase db,
                                     QString caName) :
    QDialog(parent),
    ui(new Ui::InformationWindow)
{
    ui->setupUi(this);
    QString query = QString("SELECT cm.caname FROM \"XY\".comm_mov cm "
                     "WHERE cm.cname = '%1' GROUP BY (cm.caname);").arg(caName);

    QSqlQuery sq = db.exec(query);
    while(sq.next())
        ui->listWidget->addItem(sq.value(0).toString());
//    QStringList slPe;
//    QStringList slLe;
//    ui->widget_legal->setVisible(false);
//    ui->widget_person->setVisible(false);
//    QString query = QString("SELECT pe.name FROM \"XY\".person_entity pe;");
//    QSqlQuery sq = db.exec(query);
//    while (sq.next())
//        slPe <<  sq.value(0).toString();

//    query = QString("SELECT le.name FROM \"XY\".legal_entity le;");
//    sq = db.exec(query);
//    while (sq.next())
//        slLe <<  sq.value(0).toString();

//    if(slPe.contains(caName)){
//        ui->widget_person->setVisible(true);
//        query = QString("SELECT pe.name, pe.date_of_birth, pe.telephone "
//                        "FROM \"XY\".person_entity pe;");
//        sq = db.exec(query);
//        sq.first();
//        ui->label_widget_person_name->setText(sq.value(0).toString());
//        ui->label_widget_person_date_birth->setText(sq.value(1).toString());
//        ui->label_widget_person_telephone->setText(sq.value(2).toString());
//    }
//    if(slLe.contains(caName)){
//        ui->widget_legal->setVisible(true);
//        query = QString("SELECT le.name, le.edrpou, le.identification_code, le.telephone "
//                        "FROM \"XY\".legal_entity le;");
//        sq = db.exec(query);
//        sq.first();
//        ui->label_legal_name->setText(sq.value(0).toString());
//        ui->label_legal_edrpou->setText(sq.value(1).toString());
//        ui->label_legal_id_code->setText(sq.value(2).toString());
//        ui->label_legal_telephone->setText(sq.value(3).toString());
//    }


}

InformationWindow::~InformationWindow()
{
    delete ui;
}
