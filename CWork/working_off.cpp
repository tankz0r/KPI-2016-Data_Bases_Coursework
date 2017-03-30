#include "working_off.h"
#include "ui_working_off.h"

working_off::working_off(QWidget *parent, QSqlDatabase db1) :
    QDialog(parent),
    ui(new Ui::working_off)
{
    db = db1;
    ui->setupUi(this);
    QSqlQuery sq = db.exec("SELECT e.name FROM \"XY\".employee e;");
    while (sq.next())
        slEmp << sq.value(0).toString();
    QCompleter *copl = new QCompleter(slEmp, this);
    copl->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineEdit_working_off_name->setCompleter(copl);

}

working_off::~working_off()
{
    delete ui;
}

void working_off::accept(){

    QString query, err = "";
    bool ok = true;
    bool eStF = true;
    float time = 0;
    float overTime = 0;
    QString name = ui->lineEdit_working_off_name->text();
    QString date = ui->dateEdit_date_working_off->text();
    QString timeS = ui->lineEdit_working_off_hours->text();
    QString overTimeS = ui->lineEdit_working_off_overworking->text();
    QString note = ui->textEdit_working_off->toPlainText();
    if (name==""){
        ok = false;
        err += "ПІБ працівника не заданий<br>";
    }
    else
        if (!slEmp.contains(name)){
            ok = false;
            err += "Працівник з таки ім’ям відсутній в базі даних<br>";
        }
    if (timeS==""){
        ok = false;
        err += "Час не заданий<br>";
    }
    else{
        time = timeS.toFloat(&eStF);
        if ((time<0) || !eStF){
            ok = false;
            err += "Час заданий некорректно<br>";
        }
    }
    if (overTimeS==""){
        overTimeS = "0";
    }
    else{
        overTime = overTimeS.toFloat(&eStF);
        if ((overTime<0) || !eStF){
            ok = false;
            err += "Час перепрацювання заданий некорректно<br>";
        }
    }

    if (ok){
        query = QString("INSERT INTO \"XY\".working_off "
                        "(date_w, hours, overtime_working_off, notes, id_employee) "
                        "SELECT '%1', '%2', '%3', '%4',"
                        "(SELECT e.id_employee FROM \"XY\".employee e "
                        "   WHERE e.name = '%5');"
                        "").arg(date, timeS, overTimeS, note, name);
        db.exec(query);
        qDebug() << db.lastError();
        QDialog::accept();
    }
    ui->ErrorLabel_working_off->setText("<html><head/><body><p style=\"color:red;\">"+err+
                                 "</p></body></html>");
}


