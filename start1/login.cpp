#include "login.h"
#include "ui_login.h"


Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);


    QString servername = "happycake.cme8l9aci84u.eu-central-1.rds.amazonaws.com";
    QString dbname = "test";

    db_driver = QSqlDatabase::addDatabase("QPSQL");
    db_driver.setConnectOptions();

    db_driver.setDatabaseName(dbname);
    db_driver.setHostName(servername);
    db_driver.setUserName("wolterlw");
    db_driver.setPassword("PGhc-wolodzya135");

    if(db_driver.open())
    {
//        qDebug() << dbname;
        ui->label->setText("Opened!");
    }
    else
    {
          ui->label->setText("Error");
//        qDebug() << "Error " << db_driver.lastError().text();
    }



}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
    QString name, pass;
    name = ui->lineEdit_user_name->text();
    pass = ui->lineEdit_password->text();

    QSqlQuery query;
    int count=0;
            if(query.exec("SELECT * FROM \"autorization\" where name='"+name+"' and pass='"+pass+"'"))
            {
                while(query.next())
                {
//                    qDebug() << query.value(0).toString() << query.value(1).toString();
                        count++;
                }

            }
            else
                 qDebug() << "Error " << db_driver.lastError().text();

            if (count ==1)
            {
                ui->label->setText("Autorization success");
                this->hide();
                MainForm mainform(this, name);
                mainform.setModal(true);
                mainform.exec();

                //cont.setWindowFlags(Qt::Widget);
                //cont.setWindowModality(Qt::ApplicationModal);
                //cont.hide();
                //cont.show();


            }

            else
                ui->label->setText("Autorization failed") ;
//                else {
//                qDebug() << "Error " << db_driver.lastError().text();
//            }

    db_driver.close();
    db_driver.removeDatabase(QSqlDatabase::defaultConnection);

}



