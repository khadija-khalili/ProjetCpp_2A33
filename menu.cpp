#include "menu.h"
#include "ui_menu.h"
#include "login.h"
#include "reservation.h"
#include"personnel.h"
#include"evenement.h"
#include"mainwindow_client.h"
#include"gestion_client.h"
#include"gestion_evenement.h"
#include"gestion_personnel.h"
#include"gestion_reservation.h"
Menu::Menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
}

Menu::~Menu()
{
    delete ui;
}


void Menu::on_gestionClients_clicked()
{
    khadija.show();
}


void Menu::on_gestionReservations_clicked()
{
    adam.show();
}


void Menu::on_GestionPersonnel_clicked()
{
    youssef.show();
}


void Menu::on_GestionEvenement_clicked()
{
    iyed.show();
}



void Menu::on_gestionMateriels_clicked()
{
    ranim.show();
}
