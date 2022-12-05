#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "reservation.h"
#include <QMessageBox>
#include <QApplication>
#include <QMessageBox>
#include<QDebug>
#include<QLineEdit>
#include <QPixmap>
#include <QPropertyAnimation>
#include <QDialog>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include<QDebug>
#include<QLineEdit>
#include <QPixmap>
#include <QPropertyAnimation>
#include <QDialog>
#include <QPrinter>
#include <QPrintDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

      setAttribute(Qt::WA_TranslucentBackground);
  //update_id();
      //setWindowFlags(Qt::FramelessWindowHint);
      ui->tableView->setModel(r.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int num=ui->num->text().toInt();
    QString heure_d=ui->hd->text();
    QString heure_f=ui->hf->text();
    QString type=ui->tp->currentText();
    int nb_per=ui->nb->text().toInt();
    int num_tel=ui->nt->text().toInt();


    reservation r (num,nb_per,heure_d,heure_f,num_tel,type);
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





void MainWindow::on_tableView_activated(const QModelIndex &index)
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

void MainWindow::on_pushButton_2_clicked()
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
void MainWindow::update_id()
{

       QSqlQueryModel *m=new QSqlQueryModel();
       QSqlQuery *querry=new QSqlQuery();
       querry->prepare("SELECT num FROM Reservation");
       querry->exec();
       m->setQuery(*querry);

}

void MainWindow::on_Impdos_2_clicked()
{
    reservation r;

             QString text=r.apercu_pdf();
             ui->imp->setText(text);
             QPrinter printer ;

             printer.setPrinterName("imprim");
             QPrintDialog dialog (&printer,this);
             if(dialog.exec()==QDialog::Rejected) return ;
             ui->imp->print(&printer);
}

void MainWindow::on_Ajouter_clicked()
{
    int num=ui->num->text().toInt();
    QString heure_d=ui->hd->text();
    QString heure_f=ui->hf->text();
    QString type=ui->tp->currentText();
    int nb_per=ui->nb->text().toInt();
    int num_tel=ui->nt->text().toInt();


    reservation r (num,nb_per,heure_d,heure_f,num_tel,type);
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

void MainWindow::on_tabWidget_3_tabBarClicked(int index)
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

void MainWindow::on_LeIdRT_textChanged(const QString &arg1)
{
    ui->tableView->setModel(r.rechercherID(arg1));
}

void MainWindow::on_pushButton_3_clicked()
{
     ui->tableView->setModel(r.AfficherTrieID());
}
