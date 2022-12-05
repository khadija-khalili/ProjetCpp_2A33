#include "ui_reservation.h"

#include "gestion_reservation.h"
#include "reservation.h"
#include <QMessageBox>
#include <QApplication>
#include <QMessageBox>
#include<QDebug>
#include<QLineEdit>
#include <QPixmap>
#include <QPropertyAnimation>
#include <QDialog>
#include<QPainter>

#include <QApplication>
#include <QMessageBox>

#include <QApplication>
#include <QMessageBox>
#include<QDebug>
#include<QLineEdit>
#include <QPixmap>
#include <QPropertyAnimation>
#include <QDialog>
#include <QPrinter>
#include <QPrintDialog>
#include "reservation.h"

#include "ui_reservation.h"
#include "gestion_reservation.h"
#include<QThread>
#include<QMessageBox>
#include <QString>
#include<QDateEdit>
#include <QTableWidget>
#include<QMessageBox>
#include<QSqlDatabase>
#include<QSqlError>
#include<QSqlQuery>
#include<QIntValidator>
#include<QFile>
#include<QFileDialog>
#include<QThread>
#include <QDebug>
#include <QPdfWriter>
#include <QDesktopServices>
#include <QPainter>
#include <QtCharts>
#include <QLineSeries>
#include "materiel.h"

#include "ui_materiel.h"
#include "gestion_materiel.h"
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
Reservation::Reservation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Reservation)
{
    ui->setupUi(this);

      setAttribute(Qt::WA_TranslucentBackground);
  //update_id();
      //setWindowFlags(Qt::FramelessWindowHint);
      ui->tableView->setModel(r.afficher());
}

Reservation::~Reservation()
{
    delete ui;
}

void Reservation::on_pushButton_clicked()
{
    int num=ui->num->text().toInt();
    QString heure_d=ui->hd->text();
    QString heure_f=ui->hf->text();
    QString type=ui->tp->currentText();
    int nb_per=ui->nb->text().toInt();
    int num_tel=ui->nt->text().toInt();


    gestion_reservation r (num,nb_per,heure_d,heure_f,num_tel,type);
    //ui->tableView->setModel(k.afficher());

    bool test= r.modifier();


      if(test)//si requête executée ==>QMessageBox::information
      {


          QMessageBox::information(nullptr,QObject::tr("ok"),
                  QObject::tr("modification effectué \n Click Cancel to exit."), QMessageBox::Cancel);
      }

      else //si requête non exécutée ==>QMessageBox::critical
          QMessageBox::critical(nullptr,QObject::tr("Not Ok"),
                                QObject::tr("modification non effectué. \n ""Click Cancel to exit."),QMessageBox::Cancel);
  ui->tableView->setModel(r.afficher());

}





void Reservation::on_tableView_activated(const QModelIndex &index)
{
    QString val=ui->tableView->model()->data(index).toString();
           QSqlQuery qry;
           qry.prepare("select * from Reservation where"
                       " num='"+val+"' or nb_per='"+val+"' or heure_d='"+val+"' or heure_f='"+val+"' or num_tel ='"+val+" 'or type ='"+val+"'");
           if(qry.exec())
             {while (qry.next())
            { ui->num->setText(qry.value(0).toString());
              ui->nb->setText(qry.value(1).toString());
              ui->hd->setText(qry.value(2).toString());
              ui->hf->setText(qry.value(3).toString());
              ui->nt->setText(qry.value(4).toString());

              ui->tp->setCurrentText(qry.value(5).toString());


             }
         }
}

void Reservation::on_pushButton_2_clicked()
{
    int idaa =ui->num->text().toInt();
               bool test = r.supprimer(idaa);
               if(test)
               {
                   //refresh affichage
                   ui->tableView->setModel(r.afficher());
                  // update_id();
                   QMessageBox::information(nullptr,QObject::tr("ok"),
                                            QObject::tr("suppression effectué \n ""Click Cancel to exit."),QMessageBox::Cancel);

               }
               else
                   QMessageBox::critical(nullptr,QObject::tr("not ok"),

        QObject::tr("suppression non effectué.\n""Click Cancel to exit."),QMessageBox::Cancel);

}
void Reservation::update_id()
{

       QSqlQueryModel *m=new QSqlQueryModel();
       QSqlQuery *querry=new QSqlQuery();
       querry->prepare("SELECT num FROM Reservation");
       querry->exec();
       m->setQuery(*querry);

}

void Reservation::on_Impdos_2_clicked()
{
    gestion_reservation r;

             QString text=r.apercu_pdf();
             ui->imp->setText(text);
             QPrinter printer ;

             printer.setPrinterName("imprim");
             QPrintDialog dialog (&printer,this);
             if(dialog.exec()==QDialog::Rejected) return ;
             ui->imp->print(&printer);
}

void Reservation::on_Ajouter_clicked()
{
    int num=ui->num->text().toInt();
    QString heure_d=ui->hd->text();
    QString heure_f=ui->hf->text();
    QString type=ui->tp->currentText();
    int nb_per=ui->nb->text().toInt();
    int num_tel=ui->nt->text().toInt();


    gestion_reservation r (num,nb_per,heure_d,heure_f,num_tel,type);
    //ui->tableView->setModel(k.afficher());

    bool test= r.ajouter();


      if(test)//si requête executée ==>QMessageBox::information
      {


          QMessageBox::information(nullptr,QObject::tr("ok"),
                  QObject::tr("Ajout effectué \n Click Cancel to exit."), QMessageBox::Cancel);
      }

      else //si requête non exécutée ==>QMessageBox::critical
          QMessageBox::critical(nullptr,QObject::tr("Not Ok"),
                                QObject::tr("Ajout non effectué. \n ""Click Cancel to exit."),QMessageBox::Cancel);
  ui->tableView->setModel(r.afficher());
}

void Reservation::on_tabWidget_3_tabBarClicked(int index)
{
    qDeleteAll(ui->tabWidget_3->widget(0)->children());
    QWidget* piestats = new QWidget(this);
    piestats = piechart();
    QGridLayout* layout1 = new QGridLayout(this);
    layout1->addWidget(piestats, 0, 0); // Top-Left
    layout1->addWidget(NULL, 0, 1); // Top-Right
    layout1->addWidget(NULL, 1, 0); // Bottom-Left
    layout1->addWidget(NULL, 1, 1); // Bottom-Right
    ui->tab_9->setLayout(layout1);

}

void Reservation::on_LeIdRT_textChanged(const QString &arg1)
{
    ui->tableView->setModel(r.rechercherID(arg1));
}

void Reservation::on_pushButton_3_clicked()
{
     ui->tableView->setModel(r.AfficherTrieID());
}
void Reservation::on_qrcodegen_clicked()
{
    int tabeq=ui->tableView->currentIndex().row();
           QVariant idd=ui->tableView->model()->data(ui->tableView->model()->index(tabeq,0));
           QString id= idd.toString();
           QSqlQuery qry;
           qry.prepare("select * from reservation where num=:id");
           qry.bindValue(":CIN_I",id);
           qry.exec();
           QString heure_d,heure_f,type;

           while(qry.next()){


               heure_d=qry.value(2).toString();
               heure_f=qry.value(3).toString();
               type=qry.value(4).toString();


           }

                  id="heure_d:"+heure_d+"heure_f:"+heure_f,"type:"+type;
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


