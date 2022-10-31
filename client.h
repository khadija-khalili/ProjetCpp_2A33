#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QSqlQueryModel>

class Client
{
public:
    Client();
    Client(int, QString, QString, int, QString);

    int getid();
    QString getnom();
    QString getprenom();
    int getnumtel();
    QString getabonnement();

    void setid(int);
    void setnom(QString);
    void setprenom(QString);
    void setnumtel(int);
    void setabonnement(QString);

    bool ajouter();
    bool modifier();
    QSqlQueryModel* afficher();
    bool supprimer(int);

private:
   int id,numtel;
   QString nom, prenom, abonnement;
};

#endif // CLIENT_H
