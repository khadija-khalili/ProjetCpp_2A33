#ifndef PERSONNEL_H
#define PERSONNEL_H
#include <QString>
#include <QSqlQueryModel>
class Personnel
{
public:
    Personnel();
    Personnel (int,QString,QString,QString,int,QString);
    int getid_personnel();
    QString getnom();
    QString getprenom();
    QString getemail();
    QString getsexe();
    int getnum_tel();
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


#endif // PERSONNEL_H

