#ifndef PERSONNEL_H
#define PERSONNEL_H
#include <QMainWindow>
#include<QPdfWriter>
#include<QPainter>
#include <QDesktopServices>
#include <QtPrintSupport/QtPrintSupport>
#include <QSqlQuery>
#include <QtCharts>
#include <QMainWindow>
#include <QDialog>

#include <QPixmap>
#include <QFile>
#include <QDialog>
#include <QFileDialog>

#include <QUrl>
#include <QSystemTrayIcon>
#include<QPropertyAnimation>
#include <QRegularExpression>
#include <QTranslator>
#include <QPixmap>

#include <QtNetwork/QAbstractSocket>
#include <QtNetwork/QSslSocket>
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
#include <QMainWindow>
#include <QStackedWidget>
#include <QtGui>
#include <QMainWindow>

#include <QtNetwork/QAbstractSocket>
#include <QtNetwork/QSslSocket>
#include <QPixmap>
#include <QFile>
#include <QDialog>
#include <QFileDialog>

#include <QMainWindow>
#include <string>
#include <cstring>
#include <cctype>
#include <QMessageBox>
#include <iostream>
#include <bitset>
#include <sstream>
#include <algorithm>
#include <QUrl>
#include <QSystemTrayIcon>

#include<QPropertyAnimation>
#include <QRegularExpression>
#include <QTranslator>
#include <QPixmap>
#include <QMainWindow>
#include <QStackedWidget>
#include <QtGui>
#include <QMainWindow>

#include <QtNetwork/QAbstractSocket>
#include <QtNetwork/QSslSocket>
#include <QPixmap>
#include <QFile>
#include <QDialog>
#include <QFileDialog>

#include <QMainWindow>
#include <string>
#include <cstring>
#include <cctype>
#include <QMessageBox>
#include <iostream>
#include <bitset>
#include <sstream>
#include <algorithm>
#include <QUrl>
#include <QSystemTrayIcon>
#include"gestion_personnel.h"

#include<QPropertyAnimation>
#include <QRegularExpression>
#include <QTranslator>
#include <QPixmap>

#include<QCamera>
#include<QCameraViewfinder>
#include<QCameraImageCapture>
#include<QVBoxLayout>
#include<QMenu>
#include<QAction>
QT_BEGIN_NAMESPACE



class QCamera;
class QCameraViewfinder;
class QCameraImageCapture;
class QVBoxLayout;
class QMenu;
class QAction;

namespace Ui {
class Personnel;
}

class Personnel : public QDialog
{
    Q_OBJECT

public:
    explicit Personnel(QWidget *parent = nullptr);
    ~Personnel();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supp_clicked();

    void on_pb_pdf_clicked();

    void on_Search_Nom_textChanged(const QString &arg1);

    void on_Search_Prenom_textChanged(const QString &arg1);

    void on_pb_tri_nom_clicked();

    void on_pb_tri_prenom_clicked();

    void on_pb_tri_ID_clicked();





   // void on_pushButton_5_clicked();

   // void on_stat_tab_tabBarClicked(int index);

   // void update_label();

   // void on_pb_ON_clicked();

  //  void on_pb_OFF_clicked();

  //  void on_pb_up_clicked();

 ///   void on_pb_down_clicked();

    void on_qrcodegen_clicked();

private:
    Ui::Personnel *ui;
    gestion_personnel P ;
    QPainter painter;
    QByteArray data;
    //arduino a;
    QCamera *mCamera;
    QCameraViewfinder *mCameraViewfinder;
    QCameraImageCapture *mCameraImageCapture;
    QVBoxLayout *mLayout;
    QMenu *mOpcionesMenu;
    QAction *mEncenderAction;
    QAction *mApagarAction;
    QAction *mCapturarAction;
};

#endif // PERSONNEL_H
