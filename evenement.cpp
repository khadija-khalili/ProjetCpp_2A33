#include "connection.h"
#include "dialog_stats.h"

#include <QIntValidator>
#include <QMessageBox>
#include <QDesktopServices>
#include <QFileDialog>
#include <QPushButton>
#include <QPdfWriter>
#include <QPainter>
#include <QTableView>
#include "evenement.h"
#include<QPainter>

#include "ui_evenement.h"
#include "gestion_evenement.h"
Evenement::Evenement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Evenement)
{
    ui->setupUi(this);

    ui->lineEdit_EventID->setValidator( new QIntValidator(0, 99999999, this));
    ui->lineEdit_NbPersonnes->setValidator( new QIntValidator(0, 99999999, this));
    ui->comboBox->setModel(E.afficher_numevent());
    //ui->tab_Events->setModel (E.afficher());
    ui->tab_Events->setModel(E.afficher());

}

Evenement::~Evenement()
{
    delete ui;
}


void Evenement::on_pB_AjouterP_clicked()
{
    int NUM_EVENT=ui->lineEdit_EventID->text().toInt();
    QString NOM=ui->lineEdit_Nom->text();
    QString TYPE=ui->LineEdit_Type->text();
    int NOMBRE_PERSONNES=ui->lineEdit_NbPersonnes->text().toInt();
    QDate DATE_E=ui->dateEdit_DateE->date();
    QTime TIME_E=ui->timeEdit_HeureE->time();
    gestion_evenement E(NUM_EVENT,NOM,TYPE,NOMBRE_PERSONNES,DATE_E,TIME_E);
    bool test=E.AjouterE();
    if(test)
    {
        ui->label_Info->setText("Ajout Effectué");
        ui->comboBox->setModel(E.afficher_numevent());
        ui->tab_Events->setModel(E.afficher());
    }
    else
    {
        ui->label_Info->setText("Ajout non effectué");
    }
}

void Evenement::on_pB_SupprimerP_clicked()
{
    gestion_evenement E;
    E.setnumevent(ui->comboBox->currentText().toInt());
    bool test=E.SupprimerE(E.getnumevent());
    if(test)
    {
        ui->label_Info->setText("Suppression effectué");
        ui->tab_Events->setModel(E.afficher());
        ui->comboBox->setModel(E.afficher_numevent());
    }
    else
    {
        ui->label_Info->setText("Suppression non effectué");
    }
}

void Evenement::on_pB_ModifierP_clicked()
{
    int NUM_EVENT=ui->lineEdit_EventID->text().toInt();
    QString NOM=ui->lineEdit_Nom->text();
    QString TYPE=ui->LineEdit_Type->text();
    int NOMBRE_PERSONNES=ui->lineEdit_NbPersonnes->text().toInt();
    QDate DATE_E=ui->dateEdit_DateE->date();
    QTime TIME_E=ui->timeEdit_HeureE->time();
    gestion_evenement E(NUM_EVENT,NOM,TYPE,NOMBRE_PERSONNES,DATE_E,TIME_E);
    bool test=E.ModifierE();
    if(test)
    {
        ui->label_Info->setText("Modification effectué");
        ui->tab_Events->setModel(E.afficher());
        ui->comboBox->setModel(E.afficher_numevent());
    }
    else
    {
        ui->label_Info->setText("Modification non effectué");
    }
}

void Evenement::on_pB_TirerParNom_clicked()
{
    ui->label_Info->setText("Tri par Nom effectué");
    ui->tab_Events->setModel(E.tri_nom());
}

void Evenement::on_pB_TireParType_clicked()
{
    ui->label_Info->setText("Tri par Type effectué");
    ui->tab_Events->setModel(E.tri_type());
}

void Evenement::on_pB_TirerParNbPersonnes_clicked()
{
    ui->label_Info->setText("Tri par Nbr Personnes effectué");
    ui->tab_Events->setModel(E.tri_nbrpersonnes());
}

void Evenement::on_pushButton_Fermer_clicked()
{
    close();
}

void Evenement::on_pB_Recherche_clicked()
{
    gestion_evenement E;
    QString text;
    if (ui->rB_ID->isChecked()==true)
    {
        E.clearTable(ui->tab_Events);
        int ID=ui->lineEdit_Recherche->text().toInt();
        E.chercheID(ui->tab_Events,ID);
    }
    if (ui->rb_Nom->isChecked()==true)
    {
        E.clearTable(ui->tab_Events);
        QString Nom=ui->lineEdit_Recherche->text();
        E.chercheNom(ui->tab_Events,Nom);
    }
    if (ui->rB_Type->isChecked()==true)
    {
        E.clearTable(ui->tab_Events);
        QString Type=ui->lineEdit_Recherche->text();
        E.chercheType(ui->tab_Events,Type);
    }
}

void Evenement::on_pB_export_pdf_clicked()
{
    QPdfWriter pdf("C:/Users/Lenovo/Desktop/GestionDesEvenements/listeEvent.pdf");

    QPainter painter(&pdf);

    int i = 4000;
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 30));
    painter.drawPixmap(QRect(100,400,2000,2000),QPixmap("C:/Users/Lenovo/Desktop/GestionDesEvenements/logo.png"));
    painter.drawText(3000,1500,"LISTE DES EVENEMENTS");
    painter.setPen(Qt::blue);
    painter.setFont(QFont("Arial", 50));
    //painter.drawRect(2700,200,6300,2600);
    painter.drawRect(0,3000,9600,500);
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 9));
    painter.drawText(300,3300,"NOM");
    painter.drawText(2300,3300,"TYPE");
    painter.drawText(4300,3300,"NOMBRE_PERSONNES");
    painter.drawText(6300,3300,"DATE_E");
    painter.drawText(8000,3300,"TIME_E");
    QSqlQuery query;
    query.prepare("<SELECT CAST( GETDATE() AS Date ) ");
    time_t tt;
    struct tm* ti;
    time(&tt);
    ti=localtime(&tt);
    asctime(ti);
    painter.drawText(500,300, asctime(ti));
    query.prepare("select * from EVENEMENT");
    query.exec();
    while (query.next())
    {
        painter.drawText(300,i,query.value(0).toString());
        painter.drawText(2300,i,query.value(1).toString());
        painter.drawText(4300,i,query.value(2).toString());
        painter.drawText(6300,i,query.value(3).toString());
        painter.drawText(8000,i,query.value(4).toString());
        painter.drawText(10000,i,query.value(5).toString());
        i = i +500;
    }

    int reponse = QMessageBox::question(this, "PDF généré", "Afficher le PDF ?", QMessageBox::Yes |  QMessageBox::No);
    if (reponse == QMessageBox::Yes)
    {
        QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/Lenovo/Desktop/GestionDesEvenements/listeEvent.pdf"));

        painter.end();
    }
    if (reponse == QMessageBox::No)
    {
        painter.end();
    }
}

void Evenement::on_comboBox_currentIndexChanged(int)
{
    int id=ui->comboBox->currentText().toInt();
    QString id_1=QString::number(id);
    QSqlQuery query;
    query.prepare("SELECT * FROM EVENEMENT where NUM_EVENT='"+id_1+"'");
    if(query.exec())
    {
        while (query.next())
        {
            ui->lineEdit_EventID->setText(query.value(0).toString());
            ui->lineEdit_Nom->setText(query.value(1).toString());
            ui->LineEdit_Type->setText(query.value(2).toString());
            ui->lineEdit_NbPersonnes->setText(query.value(3).toString()) ;
            ui->dateEdit_DateE->setDate(query.value(4).toDate()) ;
            ui->timeEdit_HeureE->setTime(query.value(5).toTime()) ;
        }
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("NOT OK "),
                              QObject::tr("ECHEC DE chargement .\n""Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void Evenement::on_pB_Recherche_2_clicked()
{
    Dialog_Stats stats;
    stats.setModal(true);
    stats.exec();
}
