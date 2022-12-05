#ifndef FIDELITE_H
#define FIDELITE_H

#include <QString>
#include <QSqlQueryModel>

class Fidelite
{
public:
    Fidelite();
    Fidelite(int, QString);


    int getid_fidelite();
    QString getpoints_fidelite();

    void setid_fidelite(int);
    void setpoints_fidelite(QString);



    bool creer_fidelite();

private:
   int id_fidelite;
   QString points_fidelite ;
};


#endif // FIDELITE_H
