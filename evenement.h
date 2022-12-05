#ifndef EVENEMENT_H
#define EVENEMENT_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDoubleValidator>
#include <QtDebug>
#include <QObject>
#include <QMainWindow>
#include <QDateTime>
#include <QFile>
#include <QMessageBox>
#include <QDate>
#include <QTime>
#include <QTableView>

class evenement
{
public:
    evenement();
    evenement(int,QString,QString,int,QDate,QTime);

    int getnumevent();
    QString getnom();
    QString gettype();
    int getnbrpersonnes();
    QDate getdate();
    QTime gettime();

    void setnumevent(int);
    void setnom(QString);
    void settype(QString);
    void setnbrpersonnes(int);
    void setdate(QDate);
    void settime(QTime);

    bool AjouterE();
    bool ModifierE();
    bool SupprimerE(int);
    QSqlQueryModel* afficher();
    QSqlQueryModel* afficher_numevent();
    QSqlQueryModel* tri_nom();
    QSqlQueryModel* tri_type();
    QSqlQueryModel* tri_nbrpersonnes();


    QString read();
    void write(QString,QString);
    QString time();
    void clearh();
    void clearTable(QTableView * table);
    void chercheID(QTableView *table, int x);
    void chercheNom(QTableView *table, QString x);
    void chercheType(QTableView *table, QString x);

private:
    int NUM_EVENT;
    QString NOM;
    QString TYPE;
    int NOMBRE_PERSONNES;
    QDate DATE_E;
    QTime TIME_E;


};

#endif // EVENEMENT_H
