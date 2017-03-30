#include "mainform.h"
#include "ui_mainform.h"

MainForm::MainForm(QWidget *parent, QString role):
    QDialog(parent),
    ui(new Ui::MainForm)
{
    ui->setupUi(this);
    mydb=QSqlDatabase::addDatabase("QPSQL");
    connOpen();
    role = "HRs";
    qDebug() << role;
    if (role == "HRs") initHR();
    if (role == "admin") initadmin();

}

MainForm::~MainForm()
{
    delete ui;
}

int MainForm::initHR()
{
    ui->tab->setEnabled(0);
    ui->tab_3->setEnabled(0);
    return 0;
}

int MainForm::initadmin()
{
    return 0;
}


bool MainForm::connOpen()
{
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
    CounterAgent ca(this, mydb);
    ca.setModal(true);
    ca.exec();
}

void MainForm::on_pushButton_2_clicked()
{
    QSqlQueryModel * model = new QSqlQueryModel;
    QSqlQuery qry = mydb.exec(QString("select * from \"HappyCake_main\".\"physical_face\""));
    model->setQuery(qry);
    ui->tableView->setModel(model);
}
