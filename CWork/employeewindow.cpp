#include "employeewindow.h"
#include "ui_employeewindow.h"

EmployeeWindow::EmployeeWindow(QWidget *parent, QSqlDatabase db1) :
    QDialog(parent),
    ui(new Ui::EmployeeWindow)
{
    ui->setupUi(this);
    db = db1;
    ui->widget_change->setVisible(false);
    ui->widget_new_worker->setVisible(false);
    ui->comboBox_change_position->setEditable(false);
    ui->comboBox_employee_department->setEditable(false);
    ui->dateEdit_begin->setEnabled(false);
    ui->dateEdit_end->setEnabled(false);
    connect(ui->pushButton_add_change, SIGNAL(clicked()), this, SLOT(showRefresh()));
    connect(ui->pushButton_add_new_worker, SIGNAL(clicked()), this, SLOT(showAdd()));
    connect(ui->comboBox_employee_department, SIGNAL(currentIndexChanged(int)),
            this, SLOT(refreshPosition()));
    connect(ui->lineEdit_change_name, SIGNAL(editingFinished()), this, SLOT(refreshEmpl()));
    connect(ui->tableWidget_list_employee, SIGNAL(cellDoubleClicked(int, int)), this,
            SLOT(chooseEmpl(int, int)));

    QSqlQuery sq = db.exec("SELECT e.name FROM \"XY\".employee e;");
    while (sq.next())
        slEmp << sq.value(0).toString();
    QCompleter *copl = new QCompleter(slEmp, this);
    copl->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineEdit_change_name->setCompleter(copl);
    fillTable(ui->tableWidget_list_employee,
              QString("SELECT ename, pname, dname FROM \"XY\".empl;"));
}

EmployeeWindow::~EmployeeWindow()
{
    delete ui;
}
int EmployeeWindow::refreshPosition(){

   ui->comboBox_change_position->clear();
   QSqlQuery sq = db.exec(QString("SELECT p.name FROM \"XY\".position p"
                     " JOIN \"XY\".department d ON p.id_department=d.id_department"
                     "  WHERE d.name='%1';").arg(ui->comboBox_employee_department->currentText()));
//   qDebug() << sq.lastError();
   while (sq.next())
        ui->comboBox_change_position->addItem(sq.value(0).toString());
    return 0;
}
void EmployeeWindow::accept(){

    QString query, err = "";
    bool ok = true;
    bool eStF = true;
    float rate = 0;
    if (ui->widget_change->isVisible()){
        if (ui->dateEdit_begin->isEnabled()){
            query = QString("INSERT INTO \"XY\".movement_of_position "
                            "(date_start, id_employee, id_position)"
                            "SELECT '%1',"
                            "(SELECT e.id_employee FROM \"XY\".employee e WHERE e.name='%2'),"
                            "(SELECT p.id_position FROM \"XY\".position p WHERE p.name='%3');"
                            "").arg(ui->dateEdit_begin->text(),
                                   ui->lineEdit_change_name->text(),
                                   ui->comboBox_change_position->currentText());

            db.exec(query);
            qDebug() << db.lastError();

            QDialog::accept();
        }
        else{
            query = QString("UPDATE \"XY\".movement_of_position SET date_finish='%1'"
                            "WHERE id_employee="
                            "(SELECT e.id_employee FROM \"XY\".employee e WHERE e.name='%2')"
                            "").arg(ui->dateEdit_end->text(),
                                    ui->lineEdit_change_name->text());
            db.exec(query);
            qDebug() << db.lastError();
            if (db.lastError().nativeErrorCode() == "P0001")
                err += "Дата кінця менше дати початку<br>";
            else
                QDialog::accept();
        }
    }
    if (ui->widget_new_worker->isVisible()){
        QString name = ui->lineEdit_employee_name->text();
        QString date = ui->dateEdit->text();
        QString addr = ui->lineEdit_3_employee_adrress->text();
        QString edu = ui->lineEdit_4__employee_education->text();
        QString exp = ui->lineEdit_5_employee_experience->text();
        QString rateS = ui->lineEdit_8_employee_rate->text();
        if (name==""){
            ok = false;
            err += "ПІБ працівника не заданий<br>";
        }
        else if (slEmp.contains(name, Qt::CaseInsensitive)){
            ok = false;
            err += "Працівник з таки ім’ям вже присутній в базі даних<br>";
        }
        if (rateS==""){
            ok = false;
            err += "Ставка не задана<br>";
        }
        else{
            rate = rateS.toFloat(&eStF);
            if ((rate<0) || !eStF){
                ok = false;
                err += "Ставка задана некорректно<br>";
            }
        }
        if (ok){
            query = QString("INSERT INTO \"XY\".employee "
                            "(name, date_of_birth, address, education, experience, rate) "
                            "VALUES ('%1', '%2', '%3', '%4', '%5', %6);"
                            "").arg(name, date, addr, edu, exp, rateS);
            db.exec(query);
            qDebug() << db.lastError();
            QDialog::accept();
        }
    }
    ui->ErrorLabel_employee->setText("<html><head/><body><p style=\"color:red;\">"+err+
                                         "</p></body></html>");

}

int EmployeeWindow::showAdd(){
    ui->widget_change->setVisible(false);
    ui->widget_new_worker->setVisible(true);

}
int EmployeeWindow::showRefresh(){
    ui->widget_change->setVisible(true);
    ui->widget_new_worker->setVisible(false);

}
int EmployeeWindow::refreshEmpl(){

    QString err = "", name = ui->lineEdit_change_name->text();
    QString pos, dept;
    if (!slEmp.contains(name)){
        err += "Працівник з таким ім’ям відсутній в базі данних<br>";
    }
    else{
        QSqlQuery sq = db.exec(QString("SELECT em.pname, d.name FROM \"XY\".empl em "
                                       "JOIN \"XY\".position p ON em.pname=p.name "
                                       "JOIN \"XY\".department d ON p.id_department=d.id_department "
                                       "WHERE em.ename='%1';"
                                       "").arg(name));
        sq.first();
        pos = sq.value(0).toString();
        dept = sq.value(1).toString();
        if (pos == ""){
            sq = db.exec("SELECT d.name FROM \"XY\".department d;");
            ui->comboBox_employee_department->clear();
            while (sq.next())
                ui->comboBox_employee_department->addItem(sq.value(0).toString());
            refreshPosition();
            ui->comboBox_change_position->setEditable(true);
            ui->comboBox_employee_department->setEditable(true);
            ui->dateEdit_begin->clear();
            ui->dateEdit_end->clear();

            ui->dateEdit_begin->setEnabled(true);
            ui->dateEdit_end->setEnabled(false);
        }
        else{
            sq = db.exec(QString("SELECT mp.date_start FROM \"XY\".mov_pos mp "
                         "WHERE mp.ename='%1' AND date_finish IS NULL;").arg(name));
            sq.first();
            qDebug() << sq.value(0).toDate();

            ui->dateEdit_begin->setDate(sq.value(0).toDate());
            ui->comboBox_change_position->setEditable(false);
            ui->comboBox_employee_department->setEditable(false);
            ui->comboBox_employee_department->clear();
            ui->comboBox_change_position->clear();
            ui->comboBox_change_position->addItem(pos);
            ui->comboBox_employee_department->addItem(dept);
            ui->comboBox_change_position->setCurrentText(pos);
            ui->comboBox_employee_department->setCurrentText(dept);
            ui->dateEdit_end->setEnabled(true);
            ui->dateEdit_begin->setEnabled(false);
        }
    }
    ui->ErrorLabel_employee->setText("<html><head/><body><p style=\"color:red;\">"+err+
                                     "</p></body></html>");

}
int EmployeeWindow::fillTable(QTableWidget *tab, QString query){

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
int EmployeeWindow::chooseEmpl(int row, int col){
    ui->lineEdit_change_name->setText(ui->tableWidget_list_employee->item(row, col)->text());
    ui->lineEdit_change_name->editingFinished();
}
