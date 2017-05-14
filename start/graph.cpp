#include "graph.h"
#include "ui_graph.h"

graph::graph(QWidget *parent, int store, int storage) :
    QDialog(parent),
    ui(new Ui::graph)
{
    ui->setupUi(this);

    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(90, 90, 90));
    gradient.setColorAt(0.38, QColor(105, 105, 105));
    gradient.setColorAt(1, QColor(70, 70, 70));
    ui->gr1->setBackground(QBrush(gradient));

        QCPBars *myBars = new QCPBars(ui->gr1->xAxis, ui->gr1->yAxis);
         myBars->setName("Кількість продукції");
        QVector<double> valueData;
        ui->gr1->xAxis->setLabel("Місце");
        ui->gr1->yAxis->setLabel("Кількість");

        QVector<double> ticks;
        QVector<QString> labels;
        ticks << 1 << 2;
        labels << "Магазин" << "Склад";
        QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
        textTicker->addTicks(ticks, labels);
        ui->gr1->xAxis->setTicker(textTicker);
        ui->gr1->xAxis->setTickLabelRotation(60);
        ui->gr1->xAxis->setSubTicks(false);
        valueData << store << storage;
        myBars->setData(ticks, valueData);
        ui->gr1->rescaleAxes();
        ui->gr1->replot();
        ui->gr1->xAxis->setTickLength(0, 4);
        ui->gr1->xAxis->setRange(0, 4);
        ui->gr1->xAxis->setBasePen(QPen(Qt::white));
        ui->gr1->xAxis->setTickPen(QPen(Qt::white));
        ui->gr1->xAxis->grid()->setVisible(true);
        ui->gr1->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
        ui->gr1->xAxis->setTickLabelColor(Qt::white);
        ui->gr1->xAxis->setLabelColor(Qt::white);
}


graph::~graph()
{
    delete ui;
}
