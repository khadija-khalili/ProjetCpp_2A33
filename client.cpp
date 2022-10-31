#include "client.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>

Client::Client()
{
    id=0;
    nom="";
    prenom="";
    numtel=0;
    abonnement="";

}   //Constructeurs
    Client::Client(int id, QString nom, QString prenom, int numtel, QString abonnement)
    {this->id=id; this->nom=nom; this->prenom=prenom; this->numtel=numtel; this->abonnement=abonnement;}

    //Getters
    int Client::getid() {return id;}
    QString Client::getnom(){return nom;}
    QString Client::getprenom(){return prenom;}
    int Client::getnumtel() {return numtel;}
    QString Client::getabonnement(){return abonnement;}

    //Setters
    void Client::setid(int id){this->id=id;}
    void Client::setnom(QString nom){this->nom=nom;}
    void Client::setprenom(QString prenom){this->prenom=prenom;}
    void Client::setnumtel(int numtel){this->numtel=numtel;}
    void Client::setabonnement(QString abonnement){this->abonnement=abonnement;}

    //Ajouter
    bool Client::ajouter()
    {

        QSqlQuery query;
        QString res= QString::number(id);
        QString res1= QString::number(numtel);

        query.prepare("INSERT INTO CLIENT (id, nom, prenom, numtel, abonnement)" "VALUES (:id, :nom, :prenom, :numtel, :abonnement) ");

        query.bindValue(0, res);
        query.bindValue(1, nom);
        query.bindValue(2, prenom);
        query.bindValue(3, res1);
        query.bindValue(4, abonnement);
        return query.exec();

    }


    //Afficher
    QSqlQueryModel* Client::afficher()
    {
        QSqlQueryModel* model=new QSqlQueryModel();

             model->setQuery("SELECT* FROM CLIENT");
             model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
             model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
             model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
             model->setHeaderData(3, Qt::Horizontal, QObject::tr("Num Tel"));
             model->setHeaderData(4, Qt::Horizontal, QObject::tr("Abonnement"));

        return model;

    }

    //Supprimer
    bool Client::supprimer(int id)
    {

        QSqlQuery query;
        QString res= QString::number(id);


        query.prepare("DELETE FROM CLIENT where id= :id");
        query.bindValue(0, res);

        return query.exec();

    }

    //Modifier
    bool Client::modifier()
    {

        QSqlQuery query;
        QString res= QString::number(id);
        QString res1= QString::number(numtel);

        query.prepare(" UPDATE CLIENT SET (nom, prenom, numtel, abonnement)=( :nom, :prenom, :numtel, :abonnement) ");

        query.bindValue(0, res);
        query.bindValue(1, nom);
        query.bindValue(2, prenom);
        query.bindValue(3, res1);
        query.bindValue(4, abonnement);
        return query.exec();

    }





