#include "materiel.h"
#include <QSqlDatabase>
#include <QSqlQueryModel>

gestion_materiel::gestion_materiel(int id,QString nature,int reference,int prix,int etat)
{
    this->id=id;
    this->nature=nature;
    this->reference=reference;
    this->prix=prix;
    this->etat=etat;
}
bool gestion_materiel::ajouter()
{
    QSqlQuery query;
    query.prepare("insert into materiel (id,nature,reference,prix,etat) values (:id,:nature,:reference,:prix,:etat)");
    query.bindValue(":id",id);
    query.bindValue(":nature",nature);
    query.bindValue(":reference",reference);
    query.bindValue(":prix",prix);
    query.bindValue(":etat",etat);
    return query.exec();
}

QSqlQueryModel * gestion_materiel::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
        model->setQuery("select id,nature,reference,prix from materiel");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("nature"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("reference"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("prix"));
        return model;
}

bool gestion_materiel::supprimer(int id)
{
    QSqlQuery query;

    query.prepare("Delete from materiel where id= :id");
    query.bindValue(":id",id);
    return query.exec();
}
bool gestion_materiel::modifier()
{
    QSqlQuery query ;
    QSqlQuery query1;
    int b=0;
    QString res1 = QString::number(id);
    QString res2 = QString::number(reference);
    QString res3 = QString::number(prix);

    query1.prepare("SELECT id FROM materiel WHERE id=:idA");
    query1.bindValue(":idA",res1);
    query1.exec();
    while(query1.next())
    {
        b++;
    }

    if (b!=0)
    {
    query.prepare("UPDATE materiel set id = :id, nature = :nature,reference = :reference,prix=:prix,etat=:etat WHERE id=:id");
    query.bindValue(":id",res1);
    query.bindValue(":reference",res2);
    query.bindValue(":prix",res3);

    query.bindValue(":nature",nature);
    query.bindValue(":etat",etat);


    return query.exec();//exec() envoie la requête pour l'exécution
}
    else
    {
        return false;
    }
}

QSqlQueryModel * gestion_materiel:: trier(QString input){
QSqlQueryModel *model=new QSqlQueryModel();
model->setQuery("select id,nature,reference,prix from materiel  order by "+input);
model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("nature"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("reference"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("prix"));

return  model;
}
QSqlQueryModel * gestion_materiel::rechercher(QString arg1){
    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery   query;
    query.prepare("SELECT id,nature,reference,prix FROM materiel WHERE id  LIKE'%"+arg1+"%' or nature  LIKE'%"+arg1+"%' or reference LIKE'%"+arg1+"%' or prix LIKE'%"+arg1+"%' ");
     query.exec();
    model->setQuery(query);

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nature"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("reference"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("prix"));

   return model;
}
