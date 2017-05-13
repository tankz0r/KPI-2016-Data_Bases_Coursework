#include "movedoc.h"
#include "ui_movedoc.h"


movedoc::movedoc(QWidget *parent, QSqlDatabase db1) :
    QDialog(parent),
    ui(new Ui::movedoc)
{
    ui->setupUi(this);
    mydb = db1;
    for (int i = 0; i < ui->tableWidget->horizontalHeader()->count(); ++i)
            ui->tableWidget->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);

    QDate s = QDate::currentDate();
    ui->lineEdit_date->setText(s.toString(Qt::ISODate));
    ui->lineEdit_date->setEnabled(0);
    ui->tableWidget->setCellWidget(0, 1, new QSpinBox(ui->tableWidget));
}

movedoc::~movedoc()
{
    delete ui;
}

void movedoc::on_pushButton_2_add_next_commodity_clicked()
{

    int n = 0;
    for (int i=0; i< ui->tableWidget->rowCount(); ++i)
    {
        if (ui->tableWidget-> item(i, 0)->text() != "None")
            n++;
        qDebug() << "DEBUGN" << n;
    }

    QString nameC[n];
    QString quanC[n];

    for (int i=0; i< n; ++i)
    {

            nameC[i] = ui->tableWidget-> item(i, 0)->text();
            QSpinBox *sp_1 = (QSpinBox *)ui->tableWidget->cellWidget(i,1);
            quanC[i] = QString::number(sp_1->value());
            qDebug() << "Quantity" <<quanC[i];
    }

    for (int i=0; i< n; ++i)
         qDebug() << nameC[i];

    QString err = "";
    bool ok = true;
    bool eStF = true;
    float quan;
    float price;


    for (int i=0; i< n; ++i)
    {
       if (nameC[i] == "")
       {
           ok = false;
           err += "Назва товару не задана<br>";
       }
    }

    for (int i=0; i< n; ++i)
    {
        if (quanC[i] ==""){
            ok = false;
            err += "Кількість товару не задана<br>";
        }

        else{
            quan = quanC[i].toFloat(&eStF);
            if ((quan<=0) || !eStF){
                ok = false;
                err += "Кількість товару задана некорректно<br>";
            }
        }
    }
    if ( n == 0)
    {
        ok = false;
        err += "Товари на додавання не задані<br>";
    }

    if (ok)
    {
    // Тип переміщення
    QString tmov = ui->comboBox_direction->currentText();
    if (tmov == "Касса->Склад   ")
        tmov = "3";
    else
        tmov = "4";

    // Тип товара
//        QString prtype = ui->comboBox_4->currentText();
//        if (prtype == "Продукты")
//            prtype = "0";
//        else
//            prtype = "1";

    //Дата
        QString data = ui->lineEdit_date->text();

    //Название товара
        QString nameB[n];
        QString finalname = "";
        QString finalquan = "";
        for (int i=0; i<n; ++i)
        {
            qDebug() << "Massiv"<< nameC[i] ;
            QSqlQuery qry =mydb.exec(QString("SELECT \"Id_product\" FROM \"HappyCake_main\".product "
                                     "where product_name = '%1'").arg(nameC[i]));

            if (qry.next())
            {
                if (i==0)
                {
                    qDebug() << "FIRST";
                    finalname = finalname + qry.value(0).toString();
                    finalquan = finalquan + quanC[i];
                }
                else
                {
                    qDebug() << "DEBUG" << qry.value(0).toString();
                    finalname = finalname + ',' + qry.value(0).toString();
                    finalquan = finalquan + ',' + quanC[i];
                    nameB[i] = qry.value(0).toString();
                }
            }
            else
            {
                ErrorWindow er(this, "Товару "+ nameC[i] +" не існує");
                er.setModal(true);
                er.exec();
            }
        }
        qDebug() << "Final" <<finalname << " " << finalquan;

//        --n integer, iddtype integer, d DATE, idprod integer[], quant integer[]
//        SELECT move_doc(1, 3, '2017-04-22', '{1}', '{10}');

        QSqlQuery qry1 = mydb.exec(QString("select move_doc('%1', '%2', '%3','{%4}', '{%5}')").arg(QString::number(n), tmov, data, finalname, finalquan));

        QString errCode = mydb.lastError().nativeErrorCode();
        qDebug() << mydb.lastError();
        if (errCode == "P0001")
        {
                    QString errorstatment = mydb.lastError().databaseText();
                    qDebug() << "Error " << errorstatment;
                    ErrorWindow er(this, errorstatment);
                    er.setModal(true);
                    er.exec();
        }
        }

ui->ErrorLabel_Order->setText("<html><head/><body><p style=\"color:red;\">"+err+
                                  "</p></body></html>");

}


void movedoc::on_tableWidget_itemDoubleClicked(QTableWidgetItem *item)
{
   connect(ui->tableWidget, SIGNAL(itemActivated (QTableWidgetItem *)), this, SLOT(userclicked()));
}

void movedoc::recieveDataQuan(QString word)
{
    ui->tableWidget->setItem(number,0, new QTableWidgetItem(word));
    QTextStream(stdout) << "recieveDataQuan"<<word << endl;
}

void movedoc::userclicked()
{

    QModelIndexList selection = ui->tableWidget->selectionModel()->selectedIndexes();
    QModelIndex index = selection.at(0);
    int id = index.row();
    number = id;
    qungoods *q = new qungoods(this, mydb);
    QObject::connect(q, SIGNAL(sendData(QString)), this, SLOT(recieveDataQuan(QString)));
    q->setModal(true);
    q->exec();
}

void movedoc::on_addButton_clicked()
{

    const int num = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(num);
    ui->tableWidget->setItem(num,0, new QTableWidgetItem("None"));
    ui->tableWidget->setCellWidget(num, 1, new QSpinBox(ui->tableWidget));
}

void movedoc::on_pushButton_ok_clicked()
{
    close();
}

