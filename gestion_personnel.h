#ifndef GESTION_PERSONNEL_H
#define GESTION_PERSONNEL_H


#include <QString>
#include <QSqlQueryModel>
# include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QAbstractItemModel>
class gestion_personnel
{
public:
    gestion_personnel();
    gestion_personnel (int,QString,QString,QString,int,QString);
    int getid_personnel();
    QString getnom();
    QString getprenom();
    QString getemail();
    int getnum_tel();
    QString getsexe();
    void setid_personnel(int);
    void setnom(QString);
    void setprenom(QString);
    void setemail(QString);
    void setnum_tel(int);
    void setsexe(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    QSqlQueryModel* AfficherTrieprenom();
    QSqlQueryModel* AfficherTrieNom();
    QSqlQueryModel* AfficherTrieID();
    QSqlQueryModel* rechercherprenom(QString);
    QSqlQueryModel* rechercherNom(QString);
    QSqlQueryModel* rechercherID(int);
    private:
    int id_personnel,num_tel;
    QString nom,prenom,email,sexe;
};





#endif // GESTION_PERSONNEL_H
