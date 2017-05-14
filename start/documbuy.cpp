#include "documbuy.h"
#include "ui_documbuy.h"

documbuy::documbuy(QWidget *parent, QSqlDatabase db1, QString nname) :
    QDialog(parent),
    ui(new Ui::documbuy)
{

    ui->setupUi(this);
    mydb = db1;
    ui->lineEdit_contragent->setText("");

    ui->comboBox_2->addItem("Фізична особа");
    ui->comboBox_2->addItem("Юридична особа");

    ui->comboBox_3->addItem("0");
    ui->comboBox_3->addItem("5");
    ui->comboBox_3->addItem("10");

    ui->comboBox_4->addItem("Продукты");
    ui->comboBox_4->addItem("Фурнитура");

    ui->lineEdit_name_commodity_4->setText("2017-03-24");

     QDate s = QDate::currentDate();
     ui->lineEdit_name_commodity_4->setText(s.toString(Qt::ISODate));
     ui->lineEdit_name_commodity_4->setEnabled(0);

     for (int i = 0; i < ui->tableWidget->horizontalHeader()->count(); ++i)
             ui->tableWidget->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);

     ui->tableWidget->setCellWidget(0,1, new QSpinBox(ui->tableWidget));
     ui->tableWidget->setItem(0,2, new QTableWidgetItem("0"));


//     QRegExp reg_for_string;
//     reg_for_string.setPattern(QString("[0-9]+"));
//     QRegExpValidator *validator_for_string = new QRegExpValidator(reg_for_string, this);
//     ui->tableWidget-> item(0, 2)->setValidator(validator_for_string);

     keyF11 = new QShortcut(this);
     keyF11->setKey(Qt::Key_F11);
     connect(keyF11, SIGNAL(activated()), this, SLOT(on_pushButton_2_add_next_commodity_clicked()));

}

documbuy::~documbuy()
{
    qDebug() << "documbuyDESTRUCTOR";
    delete ui;
}

void documbuy::recieveData(QString word)
{
    ui->lineEdit_contragent->setText(word);
    //QTextStream(stdout) << word << endl;
}

void documbuy::recieveDataQuan(QString word)
{
    ui->tableWidget->setItem(number,0, new QTableWidgetItem(word));
    //QTextStream(stdout) << "recieveDataQuan"<<word << endl;
}

void documbuy::on_pushButton_2_add_next_commodity_clicked()
{
    int n = 0;
    for (int i=0; i< ui->tableWidget->rowCount(); ++i)
    {
        if (ui->tableWidget-> item(i, 0)->text() != "None")
            n++;
    }

    QString nameC[n];
    QString quanC[n];
    QString pricC[n];

    for (int i=0; i< n; ++i)
    {

            nameC[i] = ui->tableWidget-> item(i, 0)->text();
            // Где я должен чистить эту память ?
            QSpinBox *sp_1 = (QSpinBox *)ui->tableWidget->cellWidget(i,1);
            quanC[i] = QString::number(sp_1->value());
            pricC[i] = ui->tableWidget-> item(i, 2)->text();

    }

    for (int i=0; i< n; ++i)
         qDebug() << nameC[i];

    QString query;

    QString data = ui->lineEdit_name_commodity_4->text();
    QString coag= ui->lineEdit_contragent->text();
    QString tmov= ui->radioButton_sale->isChecked() ? "Продаж" :
                                   ui->radioButton_2_buy->isChecked() ? "Покупка" : "";

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
            if ((quan<=0) || !eStF)
            {
                ok = false;
                err += "Кількість товару задана некорректно<br>";
            }
        }
    }

    for (int i=0; i< n; ++i)
    {
        if (pricC[i]==""){
            ok = false;
            err += "Ціна за одиницю не задана<br>";
        }
        else
        {
            price = pricC[i].toFloat(&eStF);
            if ((price<0) || !eStF)
            {
                ok = false;
                qDebug() << "PRICE" <<price;
                err += "Ціна за одиницю заданa некорректно<br>";
            }
        }
     }


    if (coag==""){
        ok = false;
        err += "Контрагент не заданий<br>";
    }

    if (tmov=="")
    {
        ok = false;
        err += "Тип операції не заданий<br>";
    }

    QString ca = ui->lineEdit_contragent->text();
    QSqlQuery qry =mydb.exec(QString("SELECT \"Id_counteragent\" FROM \"HappyCake_main\".members_ "
                             "where ns = '%1'").arg(ca));

    if (qry.next())
    {
        ca = qry.value(0).toString();
        qDebug() << "DEBUG CA" << ca;
    }
    else
    {
        qDebug() << "ERROR";
        ok = false;
        err += "Користувач з таким ім’ям відсутній<br>";
    }

    if ( n == 0)
    {
        ok = false;
        err += "Товари на додавання не задані<br>";
    }

    if (ok)
    {
    // Тип документа
        if (tmov == "Продаж")
            tmov = '1';
        else
            tmov = '2';

    //Контрагент

    // Тип товара
        QString prtype = ui->comboBox_4->currentText();
        if (prtype == "Продукты")
            prtype = "0";
        else
            prtype = "1";
    //Дата
        QString date = ui->lineEdit_name_commodity_4->text();

    // Скидка
        QString sale = ui->comboBox_3->currentText();
        if (sale == "0")
            sale = "3";
        else if (sale == "10")
            sale = "2";
        else
            sale = "1";

    //Название товара
        QString nameB[n];
        QString finalname = "";
        QString finalquan = "";
        QString finalprice = "";
        for (int i=0; i<n; ++i)
        {
            qDebug() << nameC[i] ;
            QSqlQuery qry =mydb.exec(QString("SELECT \"Id_product\" FROM \"HappyCake_main\".product "
                                     "where product_name = '%1'").arg(nameC[i]));

            if (qry.next())
            {
                if (i==0)
                {
                    finalname = finalname + qry.value(0).toString();
                    finalquan = finalquan + quanC[i];
                    finalprice = finalprice +pricC[i];
                }
                else
                {
                    qDebug() << "DEBUG" << qry.value(0).toString();
                    finalname = finalname + ',' + qry.value(0).toString();
                    finalquan = finalquan + ',' + quanC[i];
                    finalprice = finalprice + ',' + pricC[i];
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
        qDebug() << finalname << " " << finalquan << " "<<finalprice ;



       // CREATE OR REPLACE FUNCTION insert_doc(n integer, caname integer, iddtype integer, d DATE, sale integer,
         // idprod integer[], mprice DOUBLE PRECISION[], quant integer[])
        QSqlQuery qry1 = mydb.exec(QString("select insert_doc_date('%1', '%2', '%3', '%4', '%5', '{%6}', '{%7}', '{%8}')").arg(QString::number(n), ca, tmov, date, sale, finalname, finalprice, finalquan));


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
      close();
    }
    ui->ErrorLabel_Order->setText("<html><head/><body><p style=\"color:red;\">"+err+
                                  "</p></body></html>");

}

void documbuy::on_pushButton_clicked()
{
    CounterAgent *ca = new CounterAgent(this, mydb);
    QObject::connect(ca, SIGNAL(sendData(QString)), this, SLOT(recieveData(QString)));
    ca->setModal(true);
    ca->exec();
    delete ca;
}

void documbuy::on_tableWidget_itemDoubleClicked(QTableWidgetItem *item)
{
    //connect(ui->tableWidget, SIGNAL(itemActivated(QTableWidgetItem *)), this, SLOT(userclicked()));
    QModelIndexList selection = ui->tableWidget->selectionModel()->selectedIndexes();
    QModelIndex index = selection.at(0);
    int id = index.row();
    number = id;
    qungoods *q = new qungoods(this, mydb);
    QObject::connect(q, SIGNAL(sendData(QString)), this, SLOT(recieveDataQuan(QString)));
    q->setModal(true);
    q->exec();
    delete q;
}

//void documbuy::userclicked()
//{
//    qDebug() << "CONSTRUCTOR userclicked";
//    QModelIndexList selection = ui->tableWidget->selectionModel()->selectedIndexes();
//    QModelIndex index = selection.at(0);
//    int id = index.row();
//    number = id;
//    qungoods *q = new qungoods(this, mydb);
//    QObject::connect(q, SIGNAL(sendData(QString)), this, SLOT(recieveDataQuan(QString)));
//    q->setModal(true);
//    q->exec();
//    delete q;
//    qDebug() << "Destructor userclicked";
//}

void documbuy::on_pushButton_ok_clicked()
{
    close();
}

void documbuy::on_addButton_clicked()
{
    const int num = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(num);
    ui->tableWidget->setItem(num,0, new QTableWidgetItem("None"));
    ui->tableWidget->setCellWidget(num, 1, new QSpinBox(ui->tableWidget));
    ui->tableWidget->setItem(num,2, new QTableWidgetItem("0"));

}
