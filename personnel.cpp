#include "personnel.h"
#include "ui_personnel.h"
#include "personnel.h"
#include <QIntValidator>
#include <QMessageBox>
#include<QPdfWriter>
#include<QPainter>
#include <QDesktopServices>
#include <QtPrintSupport/QtPrintSupport>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>
#include <QIntValidator>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QDebug>
#include <QSqlQueryModel>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>




#include <QIntValidator>
#include "QSqlQuery"
#include "QStringListModel"
#include<QFileDialog>
#include<QTextDocument>
#include<QTextStream>
#include<QGraphicsView>
#include<QtPrintSupport/QPrintDialog>
#include<QPdfWriter>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QSystemTrayIcon>
#include<QUrlQuery>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonArray>
#include <QDate>
#include <QTime>
#include<QMessageBox>
#include<QSqlTableModel>
#include<QItemSelectionModel>
#include<QTableWidgetItem>
#include <QtPrintSupport/QPrinter>
#include <QDesktopServices>
#include <QDesktopWidget>
#include <QCoreApplication>
#include <QDebug>
#include <QIntValidator>
#include <QSqlQueryModel>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>
#include<QDesktopServices>
#include<QUrl>
#include <QTextStream>
#include <QTextDocument>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QtWidgets>
#include<QFileDialog>
#include<QGraphicsView>
#include<QPdfWriter>
#include<QSqlQuery>
#include<QSystemTrayIcon>
#include <QtNetwork/QAbstractSocket>
#include <QtNetwork/QSslSocket>
#include<QUrlQuery>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonArray>
#include <QDate>
#include <QTime>
#include<QSqlTableModel>
#include<QItemSelectionModel>
#include<QTableWidgetItem>
#include <QDesktopWidget>
#include <QCoreApplication>
#include <QDateEdit>
#include <QComboBox>

#include <QPixmap>
#include <QMediaPlayer>

#include <QTabWidget>
#include <QObject>
#include <QDialog>
#include <QValidator>
#include <QPropertyAnimation>
#include <QEasingCurve>
#include <QSequentialAnimationGroup>
#include <QState>
#include <QStateMachine>
#include <QSignalTransition>
#include <QPainter>

#include<QString>
#include<QStatusBar>

#include <QSound>

#include <QDebug>
#include <QIntValidator>
#include <QSqlQueryModel>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>
#include<QDesktopServices>
#include<QUrl>
#include <QTextStream>
#include <QTextDocument>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QtWidgets>
#include<QFileDialog>
#include<QGraphicsView>
#include<QPdfWriter>
#include<QSqlQuery>
#include<QSystemTrayIcon>
#include <QtNetwork/QAbstractSocket>
#include <QtNetwork/QSslSocket>
#include<QUrlQuery>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonArray>
#include <QDate>
#include <QTime>
#include<QSqlTableModel>
#include<QItemSelectionModel>
#include<QTableWidgetItem>
#include <QDesktopWidget>
#include <QCoreApplication>
#include <QDateEdit>
#include <QComboBox>
#include <QPixmap>
#include <QMediaPlayer>
#include <QTabWidget>
#include <QObject>
#include <QDialog>
#include <QValidator>
#include <QPropertyAnimation>
#include <QEasingCurve>
#include <QSequentialAnimationGroup>
#include <QState>
#include <QStateMachine>
#include <QSignalTransition>
#include <QPainter>
#include<QString>
#include<QStatusBar>
#include <QSound>
#include<QTimer>
#include<QDateTime>
 #include <QApplication>
#include<QTimer>
#include<QDateTime>
 #include <QApplication>
#include<QCamera>
#include <QCameraViewfinder>
#include<QCameraImageCapture>
#include<QVBoxLayout>
#include<QMenu>
#include<QAction>
#include<QFileDialog>
#include "QrCode.hpp"
using namespace qrcodegen;
Personnel::Personnel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Personnel)
{
 /*   ui->setupUi(this);
    ui->id_personnel->setValidator (new QIntValidator(0,99999999, this));
    ui->le_num_tel->setValidator (new QIntValidator(0,99999999, this));
    ui->table_personnel->setModel(P.afficher());

   int ret=a.connect_arduino();
    switch (ret) {
    case(0):qDebug()<<"arduino is available and connected to : "<< a.getarduino_port_name();
        break;
    case(1):qDebug()<<"arduino is available but not connected to: "<< a.getarduino_port_name();
        break;
    case(-1):qDebug()<<"arduino is not available";
     }
    QObject::connect(a.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));*/


ui->setupUi(this);
ui->table_personnel->setModel(P.afficher());
mCamera = new QCamera (this);
mCameraViewfinder= new QCameraViewfinder(this);
mCameraImageCapture= new QCameraImageCapture(mCamera,this);
mLayout=new QVBoxLayout;
mOpcionesMenu =new QMenu("Allumer",this);
mEncenderAction=new QAction("Ouvrir",this);
mApagarAction=new QAction("Eteindre",this);
mCapturarAction =new QAction ("Capturer",this);
mOpcionesMenu->addActions({mEncenderAction,mApagarAction,
                      mCapturarAction});
ui->opcionesPushButton->setMenu(mOpcionesMenu);
mCamera->setViewfinder(mCameraViewfinder);

mLayout->addWidget(mCameraViewfinder);
mLayout->setMargin(0);


ui->scrollArea->setLayout(mLayout);
connect(mEncenderAction,&QAction::triggered,[&]() {
mCamera->start();

});
connect(mApagarAction,&QAction::triggered,[&]() {
mCamera->stop();
});
connect(mCapturarAction, &QAction::triggered, [&]() {
auto filename= QFileDialog::getSaveFileName(this,"Capturer","/",
                             "Imagen(*.jpg;*.jpeg)");
if (filename.isEmpty()) {
   return;
}
mCameraImageCapture->setCaptureDestination(
           QCameraImageCapture::CaptureToFile);
QImageEncoderSettings imageEcoderSettings;
imageEcoderSettings.setCodec("image/jpeg");
imageEcoderSettings.setResolution(1600,1200);
mCameraImageCapture->setEncodingSettings(imageEcoderSettings);
mCamera->setCaptureMode(QCamera::CaptureStillImage);
mCamera->start();
mCamera->searchAndLock();
mCameraImageCapture->capture(filename);
mCamera->unlock();

});
}

Personnel::~Personnel()
{
    delete ui;
}

void Personnel::on_pb_ajouter_clicked()
{
    int id_personnel=ui->id_personnel->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString email=ui->le_email->text();
    int num_tel=ui->le_num_tel->text().toInt();
    QString sexe=ui->le_sexe->currentText();

    gestion_personnel P (id_personnel,nom,prenom,email,num_tel,sexe);
    bool test=P.ajouter();
    QMessageBox msgBox;
    if(test){
        msgBox.setText("Ajout avec succes.");
        msgBox.exec();


    }
    else{
        msgBox.setText("Echec d'ajout");
        msgBox.exec();
    }
    ui->table_personnel->setModel(P.afficher());

}

void Personnel::on_pb_supp_clicked()
{
 gestion_personnel P1;P1.setid_personnel(ui->le_id->text().toInt());
 bool test=P1.supprimer(P1.getid_personnel());
 QMessageBox msgBox;
 if(test){
     msgBox.setText("Suppression avec succes.");
     msgBox.exec();
 }
 else{
     msgBox.setText("Echec de suppresion.");
     msgBox.exec();
 }
 ui->table_personnel->setModel(P.afficher());
}



void Personnel::on_Search_Nom_textChanged(const QString &arg1)
{
    ui->table_personnel->setModel(P.rechercherNom(arg1));
}

void Personnel::on_Search_Prenom_textChanged(const QString &arg1)
{
    ui->table_personnel->setModel(P.rechercherprenom(arg1));
}

void Personnel::on_pb_tri_nom_clicked()
{
     ui->table_personnel->setModel(P.AfficherTrieNom());
     ui->table_personnel->setModel(P.afficher());
}

void Personnel::on_pb_tri_prenom_clicked()
{
    ui->table_personnel->setModel(P.AfficherTrieprenom());

}

void Personnel::on_pb_tri_ID_clicked()
{
    ui->table_personnel->setModel(P.AfficherTrieID());

}




void Personnel::on_pb_pdf_clicked()
{
    QPdfWriter pdf("C:/Users/pc/Documents/Atelier_Connexion/.pdf");

                             QPainter painter(&pdf);

                             int i = 4000;


                             painter.drawText(3000,1500,"LISTE DES PERSONNELS");
                             painter.setPen(Qt::blue);
                             painter.setFont(QFont("Arial", 50));
                             painter.drawRect(2700,200,6300,2600);
                             painter.drawRect(0,3000,9600,500);
                             painter.setPen(Qt::black);
                             painter.setFont(QFont("Arial", 9));
                             painter.drawText(200,3200,"ID");
                             painter.drawText(2200,3200,"nom");
                             painter.drawText(4200,5200,"prenom");

                             painter.drawText(6000,3300,"email");
                             painter.drawText(6000,3400,"num_tel");


                             QSqlQuery query;
                             query.prepare("select * from Personnel");
                             query.exec();
                             while (query.next())
                             {
                                 painter.drawText(300,i,query.value(0).toString());
                                 painter.drawText(1300,i,query.value(1).toString());
                                 painter.drawText(2300,i,query.value(2).toString());
                                 painter.drawText(3300,i,query.value(3).toString());
                                 painter.drawText(4300,i,query.value(4).toString());


                                 i = i +500;
                             }

                             int reponse = QMessageBox::question(this, "PDF généré", "Afficher le PDF ?", QMessageBox::Yes |  QMessageBox::No);
                             if (reponse == QMessageBox::Yes)
                             {
                                 QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/pc/Documents/Atelier_Connexion/.pdf"));

                                 painter.end();
                             }
                             if (reponse == QMessageBox::No)
                             {
                                 painter.end();
                             }

    }



void Personnel::on_qrcodegen_clicked()
{
    int tabeq=ui->table_personnel->currentIndex().row();
           QVariant idd=ui->table_personnel->model()->data(ui->table_personnel->model()->index(tabeq,0));
           QString id= idd.toString();
           QSqlQuery qry;
           qry.prepare("select * from personnel whereid_personnel=:id");
           qry.bindValue(":CIN_I",id);
           qry.exec();
           QString NOM,PRENOM,EMAIL,SEXE;

           while(qry.next()){


               NOM=qry.value(2).toString();
               PRENOM=qry.value(3).toString();
               EMAIL=qry.value(4).toString();
               SEXE=qry.value(5).toString();


           }

                  id="NOM:"+NOM+"PRENOM:"+PRENOM,"EMAIL:"+EMAIL,"SEXE:"+SEXE;
           QrCode qr = QrCode::encodeText(id.toUtf8().constData(), QrCode::Ecc::HIGH);

           // Read the black & white pixels
           QImage im(qr.getSize(),qr.getSize(), QImage::Format_RGB888);
           for (int y = 0; y < qr.getSize(); y++) {
               for (int x = 0; x < qr.getSize(); x++) {
                   int color = qr.getModule(x, y);  // 0 for white, 1 for black

                   // You need to modify this part
                   if(color==0)
                       im.setPixel(x, y,qRgb(254, 254, 254));
                   else
                       im.setPixel(x, y,qRgb(0, 0, 0));
               }
           }
           im=im.scaled(200,200);
           ui->qrcodecommande->setPixmap(QPixmap::fromImage(im));

}




/*
void MainWindow:: update_label(){
    data=a.read_from_arduino();
    if(data=="1")
        ui->L_Etat->setText("ON");
    else if(data=="0")
      ui->L_Etat->setText("OFF");
}

void MainWindow::on_pb_ON_clicked()
{
a.write_to_arduino("1");
}

void MainWindow::on_pb_OFF_clicked()
{
a.write_to_arduino("0");
}

void MainWindow::on_pb_up_clicked()
{
a.write_to_arduino("2");
}

void MainWindow::on_pb_down_clicked()
{
a.write_to_arduino("3");
}
*/


