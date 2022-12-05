#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtGui>
#include <QtCore>
#include <QMainWindow>
#include "gestion_client.h"
#include "abonnement.h"
#include "fidelite.h"
#include <QtCharts>
#include <QDebug>
#include <QDialog>
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

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
        int G_PVS1();
        int G_PVS2();
        int G_PVS3();
        int G_PVS4();
        int G_PVS5();


        QChartView* piechart();

private slots:

    void on_pb_ajouter_clicked();
    void on_pb_supprimer_clicked();

    void on_pb_edit_clicked();

    //void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEdit_rech_textEdited(const QString &arg1);

    void on_trier_desc_clicked();

    void on_trier_desc_2_clicked();

    //void on_pb_ajouter_3_clicked();

    void on_creer_abo_clicked();

    //void on_trier_desc_5_clicked();

    //void on_delete_client_clicked();

    //void on_trier_desc_3_clicked();

    void on_pdf_clicked();

    void on_creer_fidelite_clicked();

    //void on_tabWidget_tabBarClicked(int index);

private:
    Ui::MainWindow *ui;
   // Gestion_client C;
    Abonnement A;
    Fidelite F;
    int mnSelected;

};

#endif // MAINWINDOW_H
