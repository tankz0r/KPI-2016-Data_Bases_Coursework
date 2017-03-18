#include "counteragent.h"
#include "ui_counteragent.h"

CounterAgent::CounterAgent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CounterAgent)
{
    ui->setupUi(this);

}
CounterAgent::~CounterAgent()
{
    delete ui;
}

void CounterAgent::on_Load_clicked()
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
