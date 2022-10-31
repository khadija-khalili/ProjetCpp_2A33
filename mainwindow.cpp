#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include <QMessageBox>
#include <QIntValidator>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_id->setValidator( new QIntValidator(0, 99999999, this));
    ui->id_supp->setValidator( new QIntValidator(0, 99999999, this));
    ui->tab_client->setModel(C.afficher());
    ui->comboBox->addItem("Classique");
    ui->comboBox->addItem("Premium");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{
    int id=ui->le_id->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    int numtel=ui->le_numtel->text().toInt();
    QString abonnement=ui->le_type_abo->text();

    Client C(id,nom,prenom,numtel,abonnement);

    bool test=C.ajouter();

    if (test) {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                     QObject::tr("Ajout Effectué\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab_client->setModel(C.afficher());

              }
    else {

        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                     QObject::tr("Ajout non effectué\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pb_supprimer_clicked()
{
        Client C1; C1.setid(ui->id_supp->text().toInt());
        bool test=C1.supprimer(C1.getid());

        if (test) {
            QMessageBox::information(nullptr, QObject::tr("OK"),
                         QObject::tr("Suppression Effectuée\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tab_client->setModel(C.afficher());

                  }
        else {

            QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                         QObject::tr("Suppression non effectuée\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
        }
}

void MainWindow::on_pb_edit_clicked()
{
    int id=ui->le_id->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    int numtel=ui->le_numtel->text().toInt();
    QString abonnement=ui->le_type_abo->text();

    Client C(id,nom,prenom,numtel,abonnement);

    bool test=C.modifier();

    if (test) {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                     QObject::tr("Modification Effectuée\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab_client->setModel(C.afficher());

              }
    else {

        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                     QObject::tr("Modification non effectuée\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
    }
}
