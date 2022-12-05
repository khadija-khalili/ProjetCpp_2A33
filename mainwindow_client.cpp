#include <QMessageBox>
#include <QIntValidator>
#include <QListWidgetItem>
#include <QTableView>
#include <QListWidget>
#include <QPdfWriter>
#include <QPainter>
#include <QDesktopServices>
#include <QtPrintSupport/QtPrintSupport>
#include <QSqlQuery>
#include <QGraphicsView>
#include <QUrl>
#include <QDebug>

#include "mainwindow_client.h"
#include "ui_mainwindow_client.h"
#include "gestion_client.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{Gestion_client C;
    ui->setupUi(this);
    ui->le_id->setValidator( new QIntValidator(0, 99999999, this));
    ui->id_supp->setValidator( new QIntValidator(0, 99999999, this));
    ui->tab_client->setModel(C.afficher());
    ui->le_abo->addItem("Classique");
    ui->le_abo->addItem("Premium");
    ui->le_paiement->addItem("Espèces");
    ui->le_paiement->addItem("Par chéquier");
    ui->le_paiement->addItem("Prélèvement Bancaire");
    ui->le_rib->setValidator( new QIntValidator(0, 999999999, this));
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

    Gestion_client C(id,nom,prenom,numtel,abonnement);

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
{Gestion_client C;
        Gestion_client C1; C1.setid(ui->id_supp->text().toInt());
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
    int id=ui->le_id_2->text().toInt();
    QString nom=ui->le_nom_2->text();
    QString prenom=ui->le_prenom_2->text();
    int numtel=ui->le_numtel_2->text().toInt();
    QString abonnement=ui->le_type_abo_2->text();



       Gestion_client C(id,nom,prenom,numtel,abonnement);

       bool test=C.modifier();

       if (test)

       {


            QMessageBox::information(nullptr,QObject::tr("ok"),
                                     QObject::tr("Modification effectue\n ""click cancel"),
                                     QMessageBox::Cancel);
            ui->tab_client->setModel(C.afficher());

       }
       else
       {    QMessageBox::critical(nullptr,QObject::tr("not ok"),
                                  QObject::tr("Modification non fonctional\n""click to cancel"),
                                  QMessageBox::Cancel);}

}






void MainWindow::on_lineEdit_rech_textEdited(const QString &arg1)
{
    Gestion_client C;
    QString rech = ui->lineEdit_rech->text();
    ui->tab_client->setModel(C.chercher_client(rech));
}


void MainWindow::on_trier_desc_clicked()
{
    Gestion_client C;
    QString rech = ui->lineEdit_rech->text();
    ui->tab_client->setModel(C.trier_client(rech));
}

void MainWindow::on_trier_desc_2_clicked()
{
    Gestion_client C;
    QString rech = ui->lineEdit_rech->text();
    ui->tab_client->setModel(C.trier_client(rech));
}



void MainWindow::on_creer_abo_clicked()
{
    QString date_abo=ui->dateEdit->text();
    QString paiement=ui->le_paiement->currentText();
    QString type=ui->le_abo->currentText();
    int rib=ui->le_rib->text().toInt();
    QString nom_abo=ui->le_nom_abo->text();
    QString prenom_abo=ui->le_prenom_abo->text();

    Abonnement A(date_abo,paiement,type,rib,nom_abo,prenom_abo);

    bool test=A.creer_abo();

    if (test) {Gestion_client C;
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



void MainWindow::on_pdf_clicked()
{
    QPdfWriter pdf("C:/Users/Khadija Khalili/Desktop/kl.pdf");

                             QPainter painter(&pdf);

                             int i = 4000;

                             painter.setFont(QFont("Arial", 15));
                             painter.drawRect(0,3000,6300,2600);
                             painter.setPen(Qt::black);
                             painter.drawText(250,1500,"LISTE DES CLIENTS");



                             painter.drawRect(0,3000,9600,500);
                             painter.setPen(Qt::black);
                             painter.setFont(QFont("Arial", 10));
                             painter.drawText(250,3200,"ID");
                             painter.drawText(1200,3200,"NOM");
                             painter.drawText(2200,3200,"PRENOM");
                             painter.drawText(3200,3200,"NUM_TEL");
                             painter.drawText(4200,3200,"TYPE ABONNEMENT");

                             QSqlQuery query;
                             query.prepare("select * from CO_CLIENT");
                             query.exec();
                             while (query.next())
                             {
                                 painter.drawText(250,i,query.value(0).toString());
                                 painter.drawText(1200,i,query.value(1).toString());
                                 painter.drawText(2200,i,query.value(2).toString());
                                 painter.drawText(3200,i,query.value(3).toString());
                                 painter.drawText(4200,i,query.value(4).toString());


                                 i = i +500;
                             }

                             int reponse = QMessageBox::question(this, "PDF généré", "Afficher le PDF ?", QMessageBox::Yes |  QMessageBox::No);
                             if (reponse == QMessageBox::Yes)
                             {
                                 QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/Khadija Khalili/Desktop/kl.pdf"));

                                 painter.end();
                             }
                             if (reponse == QMessageBox::No)
                             {
                                 painter.end();
                             }

}




void MainWindow::on_creer_fidelite_clicked()
{

    int id_fidelite=ui->id_fidelite->text().toInt();
    QString points_fidelite=ui->points_fidelite->text();


    Fidelite F(id_fidelite, points_fidelite);

    bool test=F.creer_fidelite();

    if (test) {Gestion_client C;
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




/*void MainWindow::on_tabWidget_tabBarClicked(int index)
{


        qDeleteAll(ui->tabWidget_3->widget(1)->children());
        QWidget* piestats = new QWidget(this);
        piestats = piechart();
        QGridLayout* layout1 = new QGridLayout(this);
        layout1->addWidget(piestats, 0, 0); // Top-Left
        layout1->addWidget(NULL, 0, 1); // Top-Right
        layout1->addWidget(NULL, 1, 0); // Bottom-Left
        layout1->addWidget(NULL, 1, 1); // Bottom-Right
        ui->tab_9->setLayout(layout1);

}
*/
