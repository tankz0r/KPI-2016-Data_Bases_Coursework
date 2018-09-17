#include "login.h"
#include "ui_login.h"


Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);


    this->setWindowTitle("Happy Cake");
    this->setFixedSize(this->size());
    QRect scr = QApplication::desktop()->screenGeometry(0);
    move( scr.center() - rect().center() );

    ui->lineEdit_user_name->setText("admin");
    ui->lineEdit_password->setText("qq");

    //connectdb();
}

Login::~Login()
{
    delete ui;
}

void Login::connectdb()
{
    qDebug() << "CONNECTBD";
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


void Login::on_pushButton_clicked()
{
    connectdb();

    QString name, pass;
    name = ui->lineEdit_user_name->text();
    pass = ui->lineEdit_password->text();

    QSqlQuery query;
    int count=0;
            if(query.exec("SELECT * FROM \"autorization\" where name='"+name+"' and pass='"+pass+"'"))
            {
                while(query.next())
                {
                        //qDebug() << query.value(0).toString() << query.value(1).toString();
                        count++;
                }

            }
            else
                 qDebug() << "Error " << db_driver.lastError().text();
                 //qDebug() << "COUNT" << count;
            if (count ==1)
            {
                ui->label->setText("Autorization success");
                this->hide();

                qDebug() << "DELETECONNECTBD";
                db_driver.close();
                db_driver.removeDatabase(QSqlDatabase::defaultConnection);
                qDebug() << "AfterDelete" << QSqlDatabase::database().connectionNames();

                MainForm mainform(this, name);
                mainform.setModal(true);
                mainform.exec();

            }

            else
                ui->label->setText("<html><head/><body><p style=\"color:red;\"> Autorization failed "
                                           "</p></body></html>");
//            else {
//                qDebug() << "Error " << db_driver.lastError().text();
//            }



}



