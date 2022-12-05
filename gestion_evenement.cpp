
#include "gestion_evenement.h"
#include <QtDebug>
#include <QObject>
#include <QMainWindow>
#include <QMessageBox>
#include <QDateTime>
#include <QDate>
#include <QFile>
#include <QTime>
#include<QPainter>

gestion_evenement::gestion_evenement()
{
    NUM_EVENT=0;
    NOM=" ";
    TYPE=" ";
    NOMBRE_PERSONNES=0;
   // DATE_E;
    //TIME_E;
}
gestion_evenement::gestion_evenement(int NUM_EVENT, QString NOM, QString TYPE,int NOMBRE_PERSONNES, QDate DATE_E, QTime TIME_E)
{
    this->NUM_EVENT=NUM_EVENT;
    this->NOM=NOM;
    this->TYPE=TYPE;
    this->NOMBRE_PERSONNES=NOMBRE_PERSONNES;
    this->DATE_E=DATE_E;
    this->TIME_E=TIME_E;
}
/**************************************/
int gestion_evenement::getnumevent()
{
    return NUM_EVENT;
}
QString gestion_evenement::getnom()
{
    return NOM;
}
QString gestion_evenement::gettype()
{
    return TYPE;
}
int gestion_evenement::getnbrpersonnes()
{
    return NOMBRE_PERSONNES;
}
QDate gestion_evenement::getdate()
{
    return DATE_E;
}
QTime gestion_evenement::gettime()
{
    return TIME_E;
}
/**************************************/
void gestion_evenement::setnumevent(int NUM_EVENT)
{
    this->NUM_EVENT=NUM_EVENT;
}
void gestion_evenement::setnom(QString NOM)
{
    this->NOM=NOM;
}
void gestion_evenement::settype(QString TYPE)
{
    this->TYPE=TYPE;
}
void gestion_evenement::setnbrpersonnes(int NOMBRE_PERSONNES)
{
    this->NOMBRE_PERSONNES=NOMBRE_PERSONNES;
}
void gestion_evenement::setdate(QDate DATE_E)
{
    this->DATE_E=DATE_E;
}
void gestion_evenement::settime(QTime TIME_E)
{
    this->TIME_E=TIME_E;
}
/**************************************/
bool gestion_evenement::AjouterE()
{
    QSqlQuery query;
    QString id_string=QString::number(NUM_EVENT);
         query.prepare("INSERT INTO EVENEMENT(NUM_EVENT,NOM,TYPE,NOMBRE_PERSONNES,DATE_E,TIME_E)" "VALUES (:NUM_EVENT,:NOM,:TYPE,:NOMBRE_PERSONNES,:DATE_E,:TIME_E)");
         query.bindValue(":NUM_EVENT", NUM_EVENT);
         query.bindValue(":NOM", NOM);
         query.bindValue(":TYPE", TYPE);
         query.bindValue(":NOMBRE_PERSONNES", NOMBRE_PERSONNES);
         query.bindValue(":DATE_E", DATE_E);
         query.bindValue(":TIME_E", TIME_E);
    return query.exec();
}
bool gestion_evenement::SupprimerE(int NUM_EVENT)
{
    QSqlQuery query;
         query.prepare("DELETE FROM EVENEMENT where NUM_EVENT= :NUM_EVENT");
         query.bindValue(0, NUM_EVENT);
    return query.exec();
}
bool gestion_evenement::ModifierE()
{
    QSqlQuery query;
        query.prepare("UPDATE EVENEMENT SET NOM=:NOM, TYPE=:TYPE, NOMBRE_PERSONNES=:NOMBRE_PERSONNES, DATE_E=:DATE_E, TIME_E=:TIME_E WHERE NUM_EVENT=:NUM_EVENT");
        query.bindValue(":NUM_EVENT", NUM_EVENT);
        query.bindValue(":NOM", NOM);
        query.bindValue(":TYPE", TYPE);
        query.bindValue(":NOMBRE_PERSONNES", NOMBRE_PERSONNES);
        query.bindValue(":DATE_E", DATE_E);
        query.bindValue(":TIME_E", TIME_E);
    return query.exec();
}
/**************************************/
QSqlQueryModel* gestion_evenement::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
          model->setQuery("SELECT* FROM EVENEMENT");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM_EVENT"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("NOMBRE_PERSONNES"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_E"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("TIME_E"));
    return  model;
}
QSqlQueryModel* gestion_evenement::afficher_numevent()
{
    QSqlQueryModel* model=new QSqlQueryModel();
        model->setQuery("SELECT NUM_EVENT from EVENEMENT");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("NUM_EVENT"));
    return model;
}
/**************************************/
QSqlQueryModel * gestion_evenement::tri_nom()
{
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("SELECT * from EVENEMENT order by NUM_EVENT");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM_EVENT"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("NOMBRE_PERSONNES"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_E"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("TIME_E"));
    return model;
}
QSqlQueryModel * gestion_evenement::tri_type()
{
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("SELECT * from EVENEMENT order by TYPE");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM_EVENT"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("NOMBRE_PERSONNES"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_E"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("TIME_E"));
    return model;
}
QSqlQueryModel * gestion_evenement::tri_nbrpersonnes()
{
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("select * from EVENEMENT order by NOMBRE_PERSONNES");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM_EVENT"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("NOMBRE_PERSONNES"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_E"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("TIME_E"));
    return model;
}
/**************************************/
void gestion_evenement::clearTable(QTableView *table)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->clear();
    table->setModel(model);
}
void gestion_evenement::chercheID(QTableView *table, int x)
{
   QSqlQueryModel *model=new QSqlQueryModel();
   QSqlQuery *query =new QSqlQuery;
   query->prepare("select * from EVENEMENT where regexp_like(NUM_EVENT,:NUM_EVENT);");
   query->bindValue(":NUM_EVENT",x);
   if(x==0)
   {
       query->prepare("select * from EVENEMENT;");
   }
   query->exec();
   model->setQuery(*query);
   table->setModel(model);
   table->show();
}

void gestion_evenement::chercheNom(QTableView *table, QString x)
{
   QSqlQueryModel *model=new QSqlQueryModel();
   QSqlQuery *query =new QSqlQuery;
   query->prepare("select * from EVENEMENT where regexp_like(NOM,:NOM);");
   query->bindValue(":NOM",x);
   if(x==0)
   {
       query->prepare("select * from EVENEMENT;");
   }
   query->exec();
   model->setQuery(*query);
   table->setModel(model);
   table->show();
}
void gestion_evenement::chercheType(QTableView *table, QString x)
{
   QSqlQueryModel *model=new QSqlQueryModel();
   QSqlQuery *query =new QSqlQuery;
   query->prepare("select * from EVENEMENT where regexp_like(TYPE,:TYPE);");
   query->bindValue(":TYPE",x);
   if(x==0)
   {
       query->prepare("select * from EVENEMENT;");
   }
   query->exec();
   model->setQuery(*query);
   table->setModel(model);
   table->show();
}
