#ifndef GESTION_RESERVATION_H
#define GESTION_RESERVATION_H



#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QDialog>
#include <QMouseEvent>
#include <QPoint>
#include <QtCharts>
# include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QAbstractItemModel>
class gestion_reservation
{
private:
    int num,nb_per,num_tel;
    QString heure_d,heure_f,type;
public:
    gestion_reservation();
    gestion_reservation(int,int,QString,QString,int,QString);
       QString get(){return heure_d;}
       QString getPrenom(){return heure_f;}
       QString gettype(){return type;}
       int getnum(){return num;}

       int getnb_per(){return nb_per;}
       int getNum_tel(){return num_tel;}

       void setheure_d(QString hf){heure_d=hf;}
       void setheure_f(QString hf){heure_d=hf;}
       void settype(QString tp){type=tp;}


       void setnum(int numr){this->num=numr;}
       void setnb_per(int nb_pers){nb_per=nb_pers;}
       void setnum_tel(int numt){num_tel=numt;}

       bool ajouter();
       bool modifier();

       QSqlQueryModel * afficher();
       bool supprimer(int);
       QString  apercu_pdf();
       QSqlQueryModel * rechercherID(QString);
       QSqlQueryModel * AfficherTrieID();

};


#endif // GESTION_RESERVATION_H
