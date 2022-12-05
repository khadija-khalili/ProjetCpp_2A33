#include "reservation.h"
#include<QSqlQuery>
#include<QtDebug>
#include <QMessageBox>
#include <QApplication>
#include <QMessageBox>
#include<QDebug>
#include<QLineEdit>
#include <QPixmap>
#include <QPropertyAnimation>
#include <QDialog>
#include <QPrinter>
#include <QPrintDialog>


reservation::reservation()
{
    num=0;
          heure_d="";
          heure_f="";
          nb_per=0;
          num_tel=0;
          type="";

}
reservation::reservation(int num,int nb_per,QString heure_d,QString heure_f,int num_tel,QString type)
{

    this->num=num;
   this->heure_d=heure_d;
   this->heure_f=heure_f;
   this->nb_per=nb_per;
   this->num_tel=num_tel;
    this->type=type;

}
bool reservation::ajouter()
{
    QSqlQuery query;
    QString res1 = QString::number(num);
    QString res2 = QString::number(nb_per);
    QString res3 = QString::number(num_tel);


    //prepare() prend la requête en paramétre pour la préparer a l'exécution
    query.prepare("insert into Reservation(num,nb_per,heure_d,heure_f,num_tel,type)""values( :num, :nb_per,:heure_d, :heure_f, :num_tel, :type)");

    //Création des variables liées
    query.bindValue(":num",res1);
    query.bindValue(":nb_per",res2);
    query.bindValue(":num_tel",res3);
    query.bindValue(":heure_d",heure_d);
    query.bindValue(":heure_f",heure_f);
    query.bindValue(":type",type);


    return query.exec();//exec() envoie la requête pour l'exécution





}
bool reservation::modifier()
{
    QSqlQuery query ;
    QSqlQuery query1;
    int b=0;
    QString res1 = QString::number(num);
    QString res2 = QString::number(nb_per);
    QString res3 = QString::number(num_tel);

    query1.prepare("SELECT num FROM Reservation WHERE num=:idA");
    query1.bindValue(":idA",res1);
    query1.exec();
    while(query1.next())
    {
        b++;
    }

    if (b!=0)
    {
    query.prepare("UPDATE Reservation set num = :num, nb_per = :nb_per,heure_d = :heure_d,heure_f = :heure_f,num_tel=:num_tel,type = :type WHERE num=:num");
    query.bindValue(":num",res1);
    query.bindValue(":nb_per",res2);

    query.bindValue(":num_tel",res3);

    query.bindValue(":heure_d",heure_d);
    query.bindValue(":heure_f",heure_f);

    query.bindValue(":type",type);


    return query.exec();//exec() envoie la requête pour l'exécution
}
    else
    {
        return false;
    }
}

QSqlQueryModel * reservation::afficher()
{


QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("select * from RESERVATION");
return model;

}




bool reservation::supprimer(int idA)
{

               QSqlQuery query;
               QSqlQuery query1;
               int b=0;
               QString res=QString::number(idA);

               query1.prepare("SELECT num FROM Reservation WHERE num=:idA");
               query1.bindValue(":idA",res);
               query1.exec();
               while(query1.next())
               {
                   b++;
               }

               if (b!=0)
               {


               query.prepare("Delete from Reservation where num=:idA");
               query.bindValue(":idA",res);
               return query.exec(); }

               else
               {
                   return false;
               }
    }

QString reservation:: apercu_pdf()
 {
    QString text="          ****** Les réservations  ******      \n \n " ;
     QSqlQuery query ;
     QString i,x,z,a,b,c,d,e;


      query.exec("select * from Reservation  ");
      while (query.next())
      {
         i=query.value(0).toString();
         x=query.value(1).toString();
         z=query.value(2).toString();
         a=query.value(3).toString();
         b=query.value(4).toString();
         e=query.value(5).toString();

        text += "\n Reservation Id : "+i+"\n\n - Nombre personnes : "+ x+"\n - Heure debut : "+ z+"\n - Heure Fin:"+a+"\n - num_tel :"+b+"\n - type :"+e+"\n" ;


     }

             return text ;
 }
QSqlQueryModel * reservation::rechercherID(QString id)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select * from Reservation where num like ?");
    q.addBindValue("%"+ id +"%");
    q.exec();
    model->setQuery(q);
    return (model);
}

QSqlQueryModel * reservation::AfficherTrieID()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM Reservation ORDER BY num");

    return model;
}
