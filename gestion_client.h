#ifndef GESTION_CLIENT_H
#define GESTION_CLIENT_H
#include <QString>
#include <QSqlQueryModel>
# include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QAbstractItemModel>
#include <Qstring>
#include <iostream>
#include "ui_mainwindow_client.h"
#include "mainwindow_client.h"

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
class Gestion_client
{
public:
    Gestion_client();
    Gestion_client(int, QString, QString, int, QString);

    int getid();
    QString getnom();
    QString getprenom();
    int getnumtel();
    QString getabonnement();

    void setid(int);
    void setnom(QString);
    void setprenom(QString);
    void setnumtel(int);
    void setabonnement(QString);

    bool ajouter();
    bool modifier();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    QSqlQueryModel* chercher_client(QString);
    QSqlQueryModel* trier_client(QString);
    QSqlQueryModel* trier_client_id(QString);
    bool suppression(int);


private:
   int id,numtel;
   QString nom, prenom, abonnement;
};

#endif // GESTION_CLIENT_H
