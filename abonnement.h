#ifndef ABONNEMENT_H
#define ABONNEMENT_H
#include <QString>
#include <QSqlQueryModel>

class Abonnement
{
public:
    Abonnement();
    Abonnement(QString, QString, QString, int, QString, QString);

    QString getdate_abo();
    QString getpaiement();
    QString gettype();
    int getrib();
    QString getnom_abo();
    QString getprenom_abo();

    void setdate_abo(QString);
    void setpaiement (QString);
    void settype(QString);
    void setrib(int);
    void setnom_abo(QString);
    void setprenom_abo(QString);


    bool creer_abo();

private:
   int rib;
   QString date_abo, type, nom_abo, prenom_abo, paiement ;
};


#endif // ABONNEMENT_H
