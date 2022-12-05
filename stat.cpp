#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <string>
#include <QMessageBox>
#include <QLineEdit>
#include <QSqlQueryModel>
#include <QtCharts>
#include "personnel.h"
#include "mainwindow.h"

QChartView* MainWindow::piechart()
{

    QPieSeries *series = new QPieSeries();
    series->append("masculin", 0);
    series->append("Feminin", 1);


    // Add label to 1st slice

    QPieSlice *slice0 = series->slices().at(0);
    slice0->setExploded();
    slice0->setLabelVisible();
    slice0->setPen(QPen(Qt::darkBlue, 2));
    slice0->setBrush(Qt::blue);

    // Add label, explode and define brush for 2nd slice
    QPieSlice *slice1 = series->slices().at(1);
    slice1->setExploded();
    slice1->setLabelVisible();
    slice1->setPen(QPen(Qt::darkGreen, 2));
    slice1->setBrush(Qt::green);





    series->slices().at(0)->setValue(m());
    series->slices().at(1)->setValue(f());


    series->slices().at(0)->setBrush(Qt::darkMagenta);
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle(" Sexe Des Personnels ");
    chart->legend()->hide();

    QChartView *chartView1 = new QChartView(chart);
    chartView1->setRenderHint(QPainter::Antialiasing);
    return chartView1;
}

int MainWindow::m()
{
    int c22=0;
    QSqlQuery qry22;
    qry22.exec("SELECT sexe FROM passagers WHERE sexe='masculin'");
    while(qry22.next())
    {
        c22++;
    }
    return c22;
}

int MainWindow::f()
{
    int c21=0;
    QSqlQuery qry21;
    qry21.exec("SELECT sexe FROM Passagers WHERE sexe='Feminin' ");
    while(qry21.next())
    {
        c21++;
    }
    return c21;
}
