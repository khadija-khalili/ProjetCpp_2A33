#include "login.h"
#include "ui_login.h"
#include <QSqlQuery>
#include <QDebug>
#include <QTextLength>
#include "menu.h"
#include "mainwindow_client.h"
#include"reservation.h"
#include"personnel.h"
#include"evenement.h"

#include"gestion_client.h"
#include"gestion_evenement.h"
#include"gestion_personnel.h"
#include"gestion_reservation.h"


#include "ui_menu.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}


void Login::on_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    QString user ;
    QString pswd ;
    QSqlQuery test ;
    test.prepare("SELECT COUNT(*) from LOGIN where USERNAME= :username");
    test.bindValue(":username",username);
    test.exec();
    if (test.next())
    {
    if (test.value(0).toInt() == 1)
    {
    QSqlQuery query ;
    query.prepare("SELECT USERNAME,PASSWORD FROM LOGIN WHERE USERNAME= :username");
    query.bindValue(":username",username);
    query.exec();
    if (query.next())
    {
    user = query.value(0).toString();
    pswd = query.value(1).toString();
    if (username == user && password == pswd)
    {
        QStringList myOptions;
        myOptions << "khadija" << "adam" << "youssef" << "iyed"  <<"ranim";
                 // << "admin"
        switch(myOptions.indexOf(user))
        {
          case 0://pour khadija
            hide();

                    m.show();
                    //m.ui->gestionClients->setEnabled(false);
                    m.ui->gestionReservations->setEnabled(false);
                    m.ui->GestionPersonnel->setEnabled(false);
                    m.ui->GestionEvenement->setEnabled(false);
                    m.ui->gestionMateriels->setEnabled(false);
            break;
          case 1://pour adam
            hide();

                   m.show();
                   // m.ui->gestionReservations->setEnabled(false);

                   m.ui->gestionClients->setEnabled(false);
                   m.ui->GestionPersonnel->setEnabled(false);
                   m.ui->GestionEvenement->setEnabled(false);
                   m.ui->gestionMateriels->setEnabled(false);
            break;
        case 2 ://pour youssef
            hide();
                   m.show();
                   m.ui->gestionClients->setEnabled(false);
                   m.ui->gestionReservations->setEnabled(false);
                   //m.ui->GestionPersonnel->setEnabled(false);
                   m.ui->GestionEvenement->setEnabled(false);
                   m.ui->gestionMateriels->setEnabled(false);

            break ;
        case 3 ://pour iyed
            hide();
                   m.show();
                   m.ui->gestionClients->setEnabled(false);
                   m.ui->gestionReservations->setEnabled(false);
                   m.ui->GestionPersonnel->setEnabled(false);
                //   m.ui->GestionEvenement->setEnabled(false);
                   m.ui->gestionMateriels->setEnabled(false);
            break ;
      case 4 ://pour ranim
            hide();
                    m.show();
                    m.ui->gestionClients->setEnabled(false);
                    m.ui->gestionReservations->setEnabled(false);
                    m.ui->GestionPersonnel->setEnabled(false);
                    m.ui->GestionEvenement->setEnabled(false);
                  //  m.ui->gestionMateriels->setEnabled(false);
            break ;

       /* case 6 ://pour admin
            m.show();
            break ;*/
    }
    }
    else
    {
        QMessageBox::information(nullptr, QObject::tr("ERROR"),
                                        QObject::tr("INCORRECT USERNAME OR PASSWORD.\nCLICK CANCEL TO RETURN."), QMessageBox::Ok);
    }
    }
    }
}}
