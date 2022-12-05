#include "abonnement.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>

Abonnement::Abonnement()
{
    date_abo="";
    paiement="";
    type="";
    rib=0;
    nom_abo="";
    prenom_abo="";

}   //Constructeurs
    Abonnement::Abonnement(QString date_abo,QString paiement, QString type, int rib, QString nom_abo, QString prenom_abo)
    {this->date_abo=date_abo; this->paiement=paiement; this->type=type; this->rib=rib; this->nom_abo=nom_abo; this->prenom_abo=prenom_abo;}

    //Getters
    QString Abonnement::getdate_abo() {return date_abo;}
    QString Abonnement::getpaiement() {return paiement;}
    QString Abonnement::gettype(){return type;}
    int Abonnement::getrib(){return rib;}
    QString Abonnement::getnom_abo() {return nom_abo;}
    QString Abonnement::getprenom_abo(){return prenom_abo;}

    //Setters
    void Abonnement::setdate_abo(QString date_abo){this->date_abo=date_abo;}
    void Abonnement::setpaiement(QString paiement){this->paiement=paiement;}
    void Abonnement::settype(QString type){this->type=type;}
    void Abonnement::setrib(int rib){this->rib=rib;}
    void Abonnement::setnom_abo(QString nom_abo){this->nom_abo=nom_abo;}
    void Abonnement::setprenom_abo(QString prenom_abo){this->prenom_abo=prenom_abo;}

    //Creer abonnement
    bool Abonnement::creer_abo()
    {

        QSqlQuery query;
        QString res= QString::number(rib);
        //QString res1= QString::number(numtel);

        query.prepare("INSERT INTO CO_ABONNEMENT (date_abo, paiement, type, rib, nom_abo, prenom_abo)" "VALUES (:date_abo, :paiement, :type, :rib, :nom_abo, :prenom_abo) ");

        query.bindValue(0, date_abo);
        query.bindValue(1, paiement);
        query.bindValue(2, type);
        query.bindValue(3, res);
        query.bindValue(4, nom_abo);
        query.bindValue(5, prenom_abo);
        return query.exec();

    }
