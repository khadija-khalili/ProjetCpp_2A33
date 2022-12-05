#include "evenement.h"
#include <QtDebug>
#include <QObject>
#include <QMainWindow>
#include <QMessageBox>
#include <QDateTime>
#include <QDate>
#include <QFile>
#include <QTime>

evenement::evenement()
{
    NUM_EVENT=0;
    NOM=" ";
    TYPE=" ";
    NOMBRE_PERSONNES=0;
    DATE_E;
    TIME_E;
}
evenement::evenement(int NUM_EVENT, QString NOM, QString TYPE,int NOMBRE_PERSONNES, QDate DATE_E, QTime TIME_E)
{
    this->NUM_EVENT=NUM_EVENT;
    this->NOM=NOM;
    this->TYPE=TYPE;
    this->NOMBRE_PERSONNES=NOMBRE_PERSONNES;
    this->DATE_E=DATE_E;
    this->TIME_E=TIME_E;
}
/**************************************/
int evenement::getnumevent()
{
    return NUM_EVENT;
}
QString evenement::getnom()
{
    return NOM;
}
QString evenement::gettype()
{
    return TYPE;
}
int evenement::getnbrpersonnes()
{
    return NOMBRE_PERSONNES;
}
QDate evenement::getdate()
{
    return DATE_E;
}
QTime evenement::gettime()
{
    return TIME_E;
}
/**************************************/
void evenement::setnumevent(int NUM_EVENT)
{
    this->NUM_EVENT=NUM_EVENT;
}
void evenement::setnom(QString NOM)
{
    this->NOM=NOM;
}
void evenement::settype(QString TYPE)
{
    this->TYPE=TYPE;
}
void evenement::setnbrpersonnes(int NOMBRE_PERSONNES)
{
    this->NOMBRE_PERSONNES=NOMBRE_PERSONNES;
}
void evenement::setdate(QDate DATE_E)
{
    this->DATE_E=DATE_E;
}
void evenement::settime(QTime TIME_E)
{
    this->TIME_E=TIME_E;
}
/**************************************/
bool evenement::AjouterE()
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
bool evenement::SupprimerE(int NUM_EVENT)
{
    QSqlQuery query;
         query.prepare("DELETE FROM EVENEMENT where NUM_EVENT= :NUM_EVENT");
         query.bindValue(0, NUM_EVENT);
    return query.exec();
}
bool evenement::ModifierE()
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
QSqlQueryModel* evenement::afficher()
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
QSqlQueryModel* evenement::afficher_numevent()
{
    QSqlQueryModel* model=new QSqlQueryModel();
        model->setQuery("SELECT NUM_EVENT from EVENEMENT");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("NUM_EVENT"));
    return model;
}
/**************************************/
QSqlQueryModel * evenement::tri_nom()
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
QSqlQueryModel * evenement::tri_type()
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
QSqlQueryModel * evenement::tri_nbrpersonnes()
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
void evenement::clearTable(QTableView *table)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->clear();
    table->setModel(model);
}
void evenement::chercheID(QTableView *table, int x)
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

void evenement::chercheNom(QTableView *table, QString x)
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
void evenement::chercheType(QTableView *table, QString x)
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
