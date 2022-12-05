#include <QSqlQuery>
#include <QtDebug>
#include <QSqlQueryModel>
#include <QObject>
#include "gestion_personnel.h"
#include<QMessageBox>
#include <QIntValidator>
#include<QPdfWriter>
#include<QPainter>
#include <QDesktopServices>
#include <QtPrintSupport/QtPrintSupport>
gestion_personnel::gestion_personnel()
{
id_personnel=0;
nom="";
prenom="";
num_tel=0;
email="";
sexe="";
}

gestion_personnel::gestion_personnel(int id_personnel,QString nom ,QString prenom,QString email,int num_tel,QString sexe)
{
this-> id_personnel=id_personnel;
this->nom=nom;
this ->prenom=prenom;
this-> email=email;
this-> num_tel=num_tel;
    this->sexe=sexe;
}
int gestion_personnel::getid_personnel(){return id_personnel;}
QString gestion_personnel::getnom(){return nom;}
QString gestion_personnel::getprenom(){return prenom;}
QString gestion_personnel::getemail(){return email;}
int gestion_personnel::getnum_tel(){return num_tel;}
QString gestion_personnel::getsexe(){return sexe;}

void gestion_personnel::setid_personnel(int id_personnel){this->id_personnel=id_personnel;}
void gestion_personnel::setnom(QString nom){this->nom=nom;}
void gestion_personnel::setprenom(QString prenom){this->prenom=prenom;}
void gestion_personnel::setemail(QString email ){this->email=email;}
void gestion_personnel::setnum_tel(int num_tel){this->num_tel=num_tel;}
void gestion_personnel::setsexe(QString sexe){this->sexe=sexe;}

bool gestion_personnel::ajouter()
{
 QSqlQuery query;
 //QString id_string= QString:: number (id_personnel);
// QString id_stringg= QString:: number (num_tel);
       query.prepare("INSERT INTO Personnel (id_personnel,nom,prenom,email,num_tel,sexe) "
                     "VALUES (:id_personnel,:nom,:prenom,:email,:num_tel,:sexe)");
       query.bindValue(":id_personnel",id_personnel);
       query.bindValue(":nom", nom);
       query.bindValue(":prenom", prenom);
       query.bindValue(":email", email);
       query.bindValue(":num_tel", num_tel);
       query.bindValue(":sexe", sexe);

       return query.exec();
}
bool gestion_personnel::supprimer(int id_personnel )
{
    QSqlQuery query;

          query.prepare(" Delete from Personnel where id_personnel=:id_personnel");
          query.bindValue(":id_personnel",id_personnel);
          return query.exec();
}



QSqlQueryModel* gestion_personnel::afficher()
{
   QSqlQueryModel* model=new QSqlQueryModel();


    model->setQuery("SELECT* FROM personnel");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("E-mail"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("num_tel"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("sexe"));

    return model;
}

QSqlQueryModel * gestion_personnel::AfficherTrieprenom()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM personnel ORDER BY prenom");

    return model;
}

QSqlQueryModel * gestion_personnel::AfficherTrieNom()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM personnel ORDER BY nom");


    return model;
}

QSqlQueryModel * gestion_personnel::AfficherTrieID()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM personnel ORDER BY ID");


    return model;
}

QSqlQueryModel * gestion_personnel::rechercherprenom(QString prenom)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select * from personnel where prenom like ?");
    query.addBindValue("%"+ prenom +"%");
    query.exec();
    model->setQuery(query);
    return (model);
}



QSqlQueryModel *gestion_personnel::rechercherNom(QString nom)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select * from personnel where nom like ?");
    query.addBindValue("%"+ nom +"%");
    query.exec();
    model->setQuery(query);
    return (model);

}

QSqlQueryModel *gestion_personnel::rechercherID(int id_personnel)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select * from personnel where id_personnel like ?");
    query.bindValue(":id_personnel",id_personnel);
    query.exec();
    model->setQuery(query);
    return (model);

}




