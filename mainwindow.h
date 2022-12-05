#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"reservation.h"
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

private:
    reservation r;
    int id_p=0;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
