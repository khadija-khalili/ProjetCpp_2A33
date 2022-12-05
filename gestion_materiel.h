#ifndef GESTION_MATERIEL_H
#define GESTION_MATERIEL_H
#include <QSqlQuery>
#include <QSqlQueryModel>

class gestion_materiel
{
    QString nature;
    int id, reference, prix, etat;

public:
    //constructeurs
    gestion_materiel(){};
    gestion_materiel (int,QString,int,int,int);

    //getters
    QString getnature(){return nature;}
    int getid(){return id;}
    int getreference(){return reference;}
    int getprix(){return prix;}
    int getetat(){return etat;}


    //setters
    void setnature(QString n){nature= n;}
    void setid(int id){this->id=id;}
    void setreference(int reference){this->reference=reference;}
    void setprix(int prix){this->prix=prix;}
    void setetat(int etat){this->etat=etat;}


    //fonctionnalites de base relatives a l'entite materiel
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();

    QSqlQueryModel* rechercher(QString arg1);
    QSqlQueryModel* trier(QString);
};

#endif // GESTION_MATERIEL_H
