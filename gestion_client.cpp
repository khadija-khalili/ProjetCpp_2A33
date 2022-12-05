#include "gestion_client.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QItemSelection>
#include <QTableView>
#include<QPainter>

Gestion_client::Gestion_client()
{
    id=0;
    nom="";
    prenom="";
    numtel=0;
    abonnement="";

}   //Constructeurs
    Gestion_client::Gestion_client(int id, QString nom, QString prenom, int numtel, QString abonnement)
    {this->id=id; this->nom=nom; this->prenom=prenom; this->numtel=numtel; this->abonnement=abonnement;}

    //Getters
    int Gestion_client::getid() {return id;}
    QString Gestion_client::getnom(){return nom;}
    QString Gestion_client::getprenom(){return prenom;}
    int Gestion_client::getnumtel() {return numtel;}
    QString Gestion_client::getabonnement(){return abonnement;}

    //Setters
    void Gestion_client::setid(int id){this->id=id;}
    void Gestion_client::setnom(QString nom){this->nom=nom;}
    void Gestion_client::setprenom(QString prenom){this->prenom=prenom;}
    void Gestion_client::setnumtel(int numtel){this->numtel=numtel;}
    void Gestion_client::setabonnement(QString abonnement){this->abonnement=abonnement;}

    //Ajouter
    bool Gestion_client::ajouter()
    {

        QSqlQuery query;
        QString res= QString::number(id);
        QString res1= QString::number(numtel);

        query.prepare("INSERT INTO CO_CLIENT (id, nom, prenom, numtel, abonnement)" "VALUES (:id, :nom, :prenom, :numtel, :abonnement) ");

        query.bindValue(0, res);
        query.bindValue(1, nom);
        query.bindValue(2, prenom);
        query.bindValue(3, res1);
        query.bindValue(4, abonnement);
        return query.exec();

    }


    //Afficher
    QSqlQueryModel* Gestion_client::afficher()
    {
        QSqlQueryModel* model=new QSqlQueryModel();

             model->setQuery("SELECT* FROM CO_CLIENT");
             model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
             model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
             model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
             model->setHeaderData(3, Qt::Horizontal, QObject::tr("Num Tel"));
             model->setHeaderData(4, Qt::Horizontal, QObject::tr("Abonnement"));

        return model;

    }

    //Supprimer
    bool Gestion_client::supprimer(int id)
    {

        QSqlQuery query;
        QString res= QString::number(id);


        query.prepare("DELETE FROM CO_CLIENT where id= :id");
        query.bindValue(0, res);

        return query.exec();

    }

    //Modifier
    bool Gestion_client::modifier()
    {
        QSqlQuery query;


            query.prepare("UPDATE CO_CLIENT set nom=:nom,prenom=:prenom,numtel=:numtel,abonnement=:abonnement where id=:id ");



            query.bindValue(":id", id);
            query.bindValue(":nom",nom);
            query.bindValue(":prenom", prenom);
            query.bindValue(":numtel", numtel);
            query.bindValue(":abonnement", abonnement);

              return query.exec();


        }


    //Recherher

    QSqlQueryModel* Gestion_client::chercher_client(QString rech)
    {
        QString sQuery="SELECT id,nom,prenom,numtel,abonnement FROM CO_CLIENT WHERE id LIKE'%"+rech+"%' or nom LIKE'%"+rech+"%' or prenom LIKE '%"+rech+"%' or numtel LIKE '%"+rech+"%' or abonnement  LIKE '%"+rech+"%'";

        QSqlQueryModel*model4=new QSqlQueryModel();

        QSqlQuery qry;

        qry.prepare(sQuery);

        qry.exec();
        model4->setQuery(qry);
        return model4;
    }

        //Trier par nom

    QSqlQueryModel* Gestion_client::trier_client(QString rech)
    {
        QString sQuery="SELECT id,nom,prenom,numtel,abonnement FROM CO_CLIENT ORDER BY nom ASC";

        QSqlQueryModel*model4=new QSqlQueryModel();

        QSqlQuery qry;

        qry.prepare(sQuery);

        qry.exec();
        model4->setQuery(qry);
        return model4;
    }

    //Trier par id

    QSqlQueryModel* Gestion_client::trier_client_id(QString rech)
    {
        QString sQuery="SELECT id,nom,prenom,numtel,abonnement FROM CO_CLIENT ORDER BY id ASC";

        QSqlQueryModel*model4=new QSqlQueryModel();

        QSqlQuery qry;

        qry.prepare(sQuery);

        qry.exec();
        model4->setQuery(qry);
        return model4;
    }







