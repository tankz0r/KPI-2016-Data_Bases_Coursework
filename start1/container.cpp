#include "container.h"
#include "ui_container.h"

container::container(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::container)
{
    ui->setupUi(this);
}

container::~container()
{
    delete ui;
}

void container::on_pushButton_2_clicked()
{
    QSqlQueryModel * model = new QSqlQueryModel;
    MainForm conn;
    if (conn.connOpen())
            qDebug() << "work";
    QSqlQuery * qry = new QSqlQuery(conn.mydb);

    qry->prepare("select * from \"HappyCake_main\".\"physical_face\"");
    qry->exec();
    model->setQuery(*qry);
    conn.connClose();
    ui->tableView->setModel(model);
}
