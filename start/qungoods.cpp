#include "qungoods.h"
#include "ui_qungoods.h"

qungoods::qungoods(QWidget *parent, QSqlDatabase db1) :
    QDialog(parent),
    ui(new Ui::qungoods)
{
    ui->setupUi(this);
    mydb = db1;

    qDebug()<< "TWO";

    for (int i = 0; i < ui->tableWidget_6->horizontalHeader()->count(); ++i)
            ui->tableWidget_6->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);

         QRegExp reg_for_string;
         reg_for_string.setPattern(QString("[а-яА-Я0-9\\s]+"));
         QRegExpValidator *validator_for_string = new QRegExpValidator(reg_for_string, this);
         ui->lineEdit_widget_delete_commodity_name->setValidator(validator_for_string);

         keyF11 = new QShortcut(this);
         keyF11->setKey(Qt::Key_F11);
         connect(keyF11, SIGNAL(activated()), this, SLOT(on_pushButton_clicked()));
         keyF10 = new QShortcut(this);
         keyF10->setKey(Qt::Key_F10);
         connect(keyF10, SIGNAL(activated()), this, SLOT(on_pushButton_11_clicked()));


}

qungoods::~qungoods()
{
    delete ui;
}

void qungoods::on_pushButton_11_clicked()
{
    QSqlQuery qry = mydb.exec(QString("select * from \"HappyCake_main\".products_quant"));
    fillTable(ui->tableWidget_6, qry);
    for (int i = 0; i < ui->tableWidget_6->horizontalHeader()->count(); ++i)
            ui->tableWidget_6->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);

}

int qungoods::fillTable(QTableWidget *tab, QSqlQuery &sq)
{
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

void qungoods::on_pushButton_9_clicked()
{

    QString name = ui->lineEdit_widget_delete_commodity_name->text();

    QString err = "";
    bool ok = true;

    if ((name=="") || (name.length()>10))
    {
        ok = false;
        err += "Ім’я задано не коректно<br>";
    }

    QString prtype = ui->comboBox_widget_->currentText();

    if (prtype == "Продукты                                          ")
        prtype = "1";
    else
        prtype = "2";

    //qDebug() << "INSERT"<< name << prtype ;
    if (ok)
    {
        QSqlQuery query =mydb.exec(QString("INSERT INTO \"HappyCake_main\".product(product_name, \"Id_product\", \"Id_prod_type\")"
                                       "  VALUES ('%1', DEFAULT , '%2')").arg(name,prtype));

        QString errCode = mydb.lastError().nativeErrorCode();
        qDebug() << mydb.lastError();
        if (errCode == "23505")
        {
                   //QString errorstatment = mydb.lastError().databaseText();
                    //qDebug() << "Error " << errorstatment;
                    ErrorWindow er(this, "Товар з таким ім’ям вже присутній.");
                    er.setModal(true);
                    er.exec();
        }

    }


    ui->ErrorLabel_Order->setText("<html><head/><body><p style=\"color:red;\">"+err+
                                  "</p></body></html>");
//    if (query.exec())
//            {
//                qDebug() << "Done";
//            }

//            else
//                qDebug() << "Error " << mydb.lastError().text();
}

void qungoods::onButtonSend(QString text)
{
    // вызываем сигнал, в котором передаём введённые данные
    emit sendData(text);
}

void qungoods::on_pushButton_clicked()
{
    QItemSelectionModel *select = ui->tableWidget_6->selectionModel();
    QString name = select->selectedIndexes().value(0).data().toString();
    qDebug()<< "ONE"<< name;
    onButtonSend(name);
    delete select;
    close();
}
