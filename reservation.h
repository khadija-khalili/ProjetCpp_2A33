#ifndef RESERVATION_H
#define RESERVATION_H
#include <QMainWindow>
#include <QMainWindow>
#include <QFileDialog>
#include <QSystemTrayIcon>
#include <qsystemtrayicon.h>
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QDialog>
#include <QMouseEvent>
#include <QPoint>
#include <QtCharts>
#include <QtCharts>
#include"gestion_reservation.h"
namespace Ui {
class Reservation;
}

class Reservation : public QDialog
{
    Q_OBJECT

public:
    explicit Reservation(QWidget *parent = nullptr);
    ~Reservation();
    void update_id();

private slots:
    void on_pushButton_clicked();
    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_2_clicked();

    void on_Impdos_2_clicked();

    void on_Ajouter_clicked();
    int G_PVS1();
    int G_PVS2();
    int G_PVS3();
    int G_PVS4();
    int G_PVS5();

    QChartView* piechart();
    void on_tabWidget_3_tabBarClicked(int index);

    void on_LeIdRT_textChanged(const QString &arg1);

    void on_pushButton_3_clicked();
    void on_qrcodegen_clicked();

private:
    gestion_reservation r;
    int id_p=0;
    Ui::Reservation  *ui;
};

#endif // RESERVATION_H
