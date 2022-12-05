#include "fidelite.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>

Fidelite::Fidelite()
{
    id_fidelite=0;
    points_fidelite="";

}   //Constructeurs
    Fidelite::Fidelite(int id_fidelite, QString points_fidelite)
    {this->id_fidelite=id_fidelite; this->points_fidelite=points_fidelite;}

    //Getters
    int Fidelite::getid_fidelite(){return id_fidelite;}
    QString Fidelite::getpoints_fidelite() {return points_fidelite;}


    //Setters
    void Fidelite::setid_fidelite(int id_fidelite){this->id_fidelite=id_fidelite;}
    void Fidelite::setpoints_fidelite(QString points_fidelite){this->points_fidelite=points_fidelite;}


    //Creer carte fidelite
    bool Fidelite::creer_fidelite()
    {

        QSqlQuery query;
        QString res= QString::number(id_fidelite);
        //QString res1= QString::number(numtel);

        query.prepare("INSERT INTO FIDELITE (id_fidelite, points_fidelite)" "VALUES (:id_fidelite, :points_fidelite) ");

        query.bindValue(0, res);
        query.bindValue(1, points_fidelite);

        return query.exec();

    }
