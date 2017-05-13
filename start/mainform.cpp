#include "mainform.h"
#include "ui_mainform.h"

MainForm::MainForm(QWidget *parent, QString login):
    QDialog(parent),
    ui(new Ui::MainForm)
{
    ui->setupUi(this);

    this->centerwindow();
    this->setWindowTitle("Happy Cake");

    mydb=QSqlDatabase::addDatabase("QPSQL");
    connOpen();
    QString role = getRole(login);
    qDebug() << role;
    if (role == "cashier") initcash();
    if (role == "manager") initmanager();


    for (int i = 0; i < ui->tableWidget->horizontalHeader()->count(); ++i)
            ui->tableWidget->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);

    for (int i = 0; i < ui->tableWidget_3->horizontalHeader()->count(); ++i)
            ui->tableWidget_3->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);


    for (int i = 0; i < ui->tableWidget_4->horizontalHeader()->count(); ++i)
        ui->tableWidget_4->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);

    for (int i = 0; i < ui->tableWidget_5->horizontalHeader()->count(); ++i)
        ui->tableWidget_5->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);

    for (int i = 0; i < ui->tableWidget_6->horizontalHeader()->count(); ++i)
        ui->tableWidget_6->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);

}



MainForm::~MainForm()
{
    delete ui;
    mydb.close();
}

int MainForm::initcash()
{
    ui->label_2->setText("Касир");
    ui->tab->setEnabled(0);
    return 0;
}

int MainForm::initmanager()
{
     ui->label_2->setText("Менеджер");
    return 0;
}

bool MainForm::connOpen()
{
    qDebug() << "CONNECTBD";
    QString servername = "happycake.cme8l9aci84u.eu-central-1.rds.amazonaws.com";
    QString dbname = "DenysPart";
    mydb = QSqlDatabase::addDatabase("QPSQL");
    mydb.setConnectOptions();
    mydb.setDatabaseName(dbname);
    mydb.setHostName(servername);
    mydb.setUserName("wolterlw");
    mydb.setPassword("PGhc-wolodzya135");
    if(mydb.open())
    {
         qDebug() << dbname;
         return true;

    }
    else
    {
        qDebug() << "Error " << mydb.lastError().text();
        return false;
    }
}

void MainForm::connClose()
{
    mydb.close();
    mydb.removeDatabase(QSqlDatabase::defaultConnection);

}


void MainForm::on_Button_buy_clicked()
{
    CounterAgent * ca = new CounterAgent(this, mydb);
    ca->setModal(true);
    ca->exec();
    delete ca;
}

void MainForm::on_pushButton_2_clicked()
{

    QString query = "select surname, name, date_of_birth, address, telephone_number from \"HappyCake_main\".\"physical_face\"";
    fillTable(ui->tableWidget, query);

    //fillTable(ui->table_goods_list, query);

    QString query2 = "select company_name, identification_code, telefon_number, adress from \"HappyCake_main\".\"corporate_face\"";
    fillTable(ui->tableWidget_3, query2);

    for (int i = 0; i < ui->tableWidget->horizontalHeader()->count(); ++i)
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);

    for (int i = 0; i < ui->tableWidget_3->horizontalHeader()->count(); ++i)
        ui->tableWidget_3->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);

}


QString MainForm::getRole( QString login)

{

        QSqlQuery sq = mydb.exec(QString("select rolname from pg_user\
                                join pg_auth_members on (pg_user.usesysid=pg_auth_members.member)\
                                join pg_roles on (pg_roles.oid=pg_auth_members.roleid)\
                                where pg_user.usename='%1';").arg(login));

//                                 if (sq.exec())
//                                         {
//                                             qDebug() << "Done";
//                                         }

//                                         else
//                                             qDebug() << "Error " << mydb.lastError().text();

        sq.first();
        qDebug() << sq.value(0).toString();
        return sq.value(0).toString();
}

void MainForm::on_pushButton_11_clicked()
{
    QSqlQuery qry = mydb.exec(QString("select * from \"HappyCake_main\".products_quant"));
    fillTable(ui->tableWidget_6, qry);
    for (int i = 0; i < ui->tableWidget_6->horizontalHeader()->count(); ++i)
        ui->tableWidget_6->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);
}


void MainForm::on_pushButton_13_clicked()
{
    QString query = "SELECT * FROM \"HappyCake_main\".doc_list_";
    fillTable(ui->tableWidget_4, query);

    for (int i = 0; i < ui->tableWidget_4->horizontalHeader()->count(); ++i)
        ui->tableWidget_4->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);

}

int MainForm::fillTable(QTableWidget *tab, QString query)
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


int MainForm::fillTable(QTableWidget *tab, QSqlQuery &sq)
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

void MainForm::on_Button_add_CA_3_clicked()
{
    documbuy * d = new documbuy(this, mydb, "");
    while(d->exec()!=QDialog::Rejected) {};
    delete d;

    //    d->setModal(true);
//    dexec();
//    d.setAttribute(Qt::WA_DeleteOnClose, true);
}


//void MainForm::on_pushButton_6_clicked()
//{
//    QSqlQueryModel * model = new QSqlQueryModel;
//    QSqlQuery qry = mydb.exec(QString("SELECT * from \"HappyCake_main\".documents"));
//    model->setQuery(qry);
//    //ui->tableWidget->setModel(model);
//}

void MainForm::on_Button_add_CA_4_clicked()
{
    movedoc m(this, mydb);
    m.setModal(true);
    m.exec();
}


void MainForm::on_pushButton_4_clicked()
{

        //QString id= ui->lineEdit_widget_good_id->text();
        QString caname = ui->lineEdit_widget_ca_name->text();
        QString dmin = ui->dateEdit->text();
        QString dmax = ui->dateEdit_2->text();
        QString cr = ui->comboBox_widget_doc_type->currentText();

        QString err = "";
        bool ok = true;

        if ((caname=="") || (caname.length()>25))
        {
            ok = false;
            err += "Ім’я задано не коректно<br>";
        }

        QStringList nn = caname.split(' ');
        QString sub1;
        if (nn.size() == 2)
        {
            sub1 = nn[0].mid(0,3)+'%'+nn[1].mid(0,3)+'%';
        }
        else
            sub1 = nn[0].mid(0,3)+'%';

        //qDebug() << caname << sub1;
        if (ok)
        {
            QSqlQuery query =mydb.exec(QString("SELECT * "
                            "FROM \"HappyCake_main\".doc_list_ "
                            "WHERE lower(name) LIKE lower('%1') "
                            "AND document_date BETWEEN '%2' AND '%3'"
                            "AND type_name LIKE '%4'"
                            ).arg(sub1, dmin, dmax, cr));

            fillTable(ui->tableWidget_4, query);

            for (int i = 0; i < ui->tableWidget_4->horizontalHeader()->count(); ++i)
                ui->tableWidget_4->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);
        }
        ui->ErrorLabel_Order_2->setText("<html><head/><body><p style=\"color:red;\">"+err+
                                      "</p></body></html>");
}

void MainForm::on_pushButton_9_clicked()
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
}

void MainForm::on_tableWidget_4_itemDoubleClicked(QTableWidgetItem *item)
{

    connect(ui->tableWidget_4, SIGNAL(itemActivated (QTableWidgetItem *)), this, SLOT(userclicked()));
}

void MainForm::userclicked()
{
    QItemSelectionModel *select = ui->tableWidget_4->selectionModel();
    QString id = select->selectedIndexes().value(0).data().toString();
    QSqlQuery query =mydb.exec(QString("SELECT product_name, price, quantity from \"HappyCake_main\".prod_in_doc "
                                       "where \"Id_document\"='%1' ").arg(id));
    fillTable(ui->tableWidget_5, query);
    for (int i = 0; i < ui->tableWidget_5->horizontalHeader()->count(); ++i)
        ui->tableWidget_5->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);

}

void MainForm::centerwindow()
{
    QRect scr = QApplication::desktop()->screenGeometry(0);
    move( scr.center() - rect().center() );
}


void MainForm::on_pushButton_clicked()
{
    QStringList list;
    QString query;

    QFile caFile("output.odt");
    caFile.open(QIODevice::WriteOnly | QIODevice::Text);

    if(!caFile.isOpen()){
        qDebug() << "- Error, unable to open" << "outputFilename" << "for output";
    }

    QTextStream outStream(&caFile);

    query = QString("SELECT * FROM \"HappyCake_main\".physical_face ");
    //qDebug() << query;
    QSqlQuery sq = mydb.exec(query);
    QString res;


    while (sq.next())
    {
        res = "";
        for(int i=0; i<6 ;i++)
        res += sq.value(i).toString() + "; ";
        outStream << res << endl;
        //qDebug() << res;
        list << res;
    }

        qDebug() << list;
        caFile.close();

        if(!(popen("soffice --calc output.odt", "r")))
            {
               qDebug() << "It doesnt work";
            }

}
