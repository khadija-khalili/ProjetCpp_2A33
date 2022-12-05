#ifndef MENU_H
#define MENU_H

#include <QDialog>
#include "mainwindow_client.h"
#include "reservation.h"
#include"personnel.h"
#include"evenement.h"
#include"mainwindow_client.h"
#include "gestion_client.h"
#include"gestion_evenement.h"
#include"gestion_personnel.h"
#include"gestion_reservation.h"
#include"materiel.h"
#include"gestion_materiel.h"

namespace Ui {
class Menu;
}

class Menu : public QDialog
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();

private slots:

    void on_gestionClients_clicked();
  void  on_gestionReservations_clicked();
  void on_GestionPersonnel_clicked();
 void   on_GestionEvenement_clicked();
  void on_gestionMateriels_clicked();



public:
    Ui::Menu *ui;
private:
    MainWindow khadija;
    Reservation adam;
    Personnel youssef;
    Evenement iyed;
    Materiel ranim;
  //  materiel ranim;

};

#endif // MENU_H
