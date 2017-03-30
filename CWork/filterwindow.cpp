#include "filterwindow.h"
#include "ui_filterwindow.h"

FilterWindow::FilterWindow(QWidget *parent, QString tableName1,
                           QSqlDatabase db1, QTableWidget *table1) :
    QDialog(parent),
    ui(new Ui::FilterWindow)
{
    ui->setupUi(this);
    db =db1;
    table = table1;
    ui->widget_commodity_movement->setVisible(false);
    ui->widget_commodity->setVisible(false);
    ui->widget_movement_of_position->setVisible(false);
    ui->widget_employee->setVisible(false);
    ui->widget_working_off->setVisible(false);
    ui->widget_department->setVisible(false);
    ui->widget_position->setVisible(false);
    tableName = tableName1;

    if (tableName == "Рух товарів"){
        QSqlQuery sq = db.exec("SELECT c.name FROM \"XY\".currency c;");
        ui->comboBox_widget_commodity_movement_currency->addItem("");
        while (sq.next())
            ui->comboBox_widget_commodity_movement_currency->addItem(sq.value(0).toString());

        ui->widget_commodity_movement->setVisible(true);
    }
    if (tableName == "Товари"){
        ui->widget_commodity->setVisible(true);
    }
    if (tableName == "Рух посад"){

        ui->widget_movement_of_position->setVisible(true);
    }
    if (tableName == "Працівники"){
        ui->widget_employee->setVisible(true);
    }
    if (tableName == "Відпрацювання"){
        ui->widget_working_off->setVisible(true);
    }
    if (tableName == "Відділ"){
        ui->widget_department->setVisible(true);
    }
    if (tableName == "Посада"){
        ui->widget_position->setVisible(true);
    }

}
void FilterWindow::accept(){

    QString query;

    if (tableName == "Рух товарів"){

        QString name = ui->lineEdit_widget_commodity_movement_name_commodity->text();
        QString caname = ui->lineEdit_widget_commodity_movement_name_conteragent->text();
        QString qmin = ui->lineEdit_widget_commodity_movement_quantity_min->text();
        QString qmax = ui->lineEdit_widget_commodity_movement_quantity_max->text();
        QString pmin = ui->lineEdit_widget_commodity_movement_price_min->text();
        QString pmax = ui->lineEdit_widget_commodity_movement_price_max->text();
        QString cr = ui->comboBox_widget_commodity_movement_currency->currentText();
        qmin = qmin != "" ? qmin : "0";
        qmax = qmax != "" ? qmax : "9223372036854775807";
        pmin = pmin != "" ? pmin : "0";
        pmax = pmax != "" ? pmax : "9223372036854775807";

        query = QString("SELECT * FROM \"XY\".comm_mov "
                        "WHERE cname LIKE '%1\%' "
                        "AND caname LIKE '%2\%' "
                        "AND quantity BETWEEN %3 AND %4 "
                        "AND price BETWEEN %5 AND %6 "
                        "AND crname LIKE '%7\%';"
                        "").arg(name, caname, qmin, qmax, pmin, pmax, cr);
    }
    if (tableName == "Товари"){
        QString name = ui->lineEdit_widget_commodity_name->text();
        QString type = ui->lineEdit_widget_commodity_type_commodity->text();
        QString qmin = ui->lineEdit_widget_commodity_quantity_min->text();
        QString qmax = ui->lineEdit_widget_commodity_quantity_max->text();

        qmin = qmin != "" ? qmin : "0";
        qmax = qmax != "" ? qmax : "9223372036854775807";

        query = QString("SELECT * FROM \"XY\".comm "
                        "WHERE cname LIKE '%1\%' "
                        "AND tcname LIKE '%2\%' "
                        "AND quantity BETWEEN %3 AND %4 "
                        ";").arg(name, type, qmin, qmax);

    }
    if (tableName == "Рух посад"){
        QString name = ui->lineEdit_widget_movement_of_position_name->text();
        QString pname = ui->lineEdit_widget_movement_of_position_position->text();
        QString dst_s = ui->dateEdit_widget_movement_of_position_begin_begin->text();
        QString dst_f = ui->dateEdit_widget_movement_of_position_begin_end->text();
        QString df_s = ui->dateEdit_widget_movement_of_position_end_begin->text();
        QString df_f = ui->dateEdit_widget_movement_of_position_end_end->text();

        query = QString("SELECT * from \"XY\".mov_pos  "
                        "WHERE date_start BETWEEN '%1' AND '%2' "
                        "AND date_finish BETWEEN '%3' AND '%4' ").arg(dst_s, dst_f, df_s, df_f);

        if (name != ""){
            query += QString("AND ename LIKE '%1\%' ").arg(name);
        }
        if (pname != ""){
            query += QString("AND pname LIKE '%1\%' ").arg(pname);
        }
        query += ";";

    }
    if (tableName == "Працівники"){
        QString name = ui->lineEdit_widget_employee_name->text();
        QString pname = ui->lineEdit_widget_employee_position->text();
        QString dst = ui->dateEdit_widget_employee_date_birth_begin->text();
        QString df = ui->dateEdit_widget_employee_date_birth_end->text();
        query = QString("SELECT * from \"XY\".empl  "
                        "WHERE date_of_birth BETWEEN '%1' AND '%2' ").arg(dst, df);

        if (name != ""){
            query += QString("AND ename LIKE '%1\%' ").arg(name);
        }
        if (pname != ""){
            query += QString("AND pname LIKE '%1\%' ").arg(pname);
        }
        query += ";";
    }
    if (tableName == "Відпрацювання"){
        QString name = ui->lineEdit_widget_working_off_name->text();
        QString pname = ui->lineEdit_widget_working_off_position->text();

        query = QString("SELECT * from \"XY\".work_off WHERE 1=1 ");

        if (name != ""){
            query += QString("AND ename LIKE '%1\%' ").arg(name);
        }
        if (pname != ""){
            query += QString("AND pname LIKE '%1\%' ").arg(pname);
        }
        query += ";";
    }
    if (tableName == "Відділ"){
        QString dname = ui->lineEdit_widget_department_name->text();
        QString caname = ui->lineEdit_widget_department_contragent->text();

        query = QString("SELECT * from \"XY\".dept WHERE 1=1 ");

        if (caname != ""){
            query += QString("AND concat LIKE '%1\%' ").arg(caname);
        }
        if (dname != ""){
            query += QString("AND dname LIKE '%1\%' ").arg(dname);
        }

        query += ";";

    }
    if (tableName == "Посада"){
        QString name = ui->lineEdit_widget_position_name->text();
        QString dname = ui->lineEdit_widget_position_department->text();
        QString rmin = ui->lineEdit_widget_position_rate_begin->text();
        QString rmax = ui->lineEdit_widget_position_rate_end->text();
        rmin = rmin != "" ? rmin : "0";
        rmax = rmax != "" ? rmax : "9223372036854775807";

        query = QString("SELECT * from \"XY\".pos WHERE salary BETWEEN %1 AND %2 "
                        "").arg(rmin, rmax);

        if (name != ""){
            query += QString("AND pname LIKE '%1\%' ").arg(name);
        }
        if (dname != ""){
            query += QString("AND dname LIKE '%1\%' ").arg(dname);
        }

        query += ";";

    }
    QSqlQuery sq = db.exec(query);
    table->clearContents();
    int nc = table->columnCount();
    table->setRowCount(sq.size());
    sq.first();
    int row = 0;
    do{

        for (int i = 0; i < nc; i++){
            QTableWidgetItem* item = new QTableWidgetItem();
            item->setText(sq.value(i).toString());
            table->setItem(row, i, item);
        }
        row++;
    }
    while (sq.next());
    table->resizeColumnsToContents();
    QDialog::accept();
}

FilterWindow::~FilterWindow()
{
    delete ui;
}
