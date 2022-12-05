#ifndef EVENEMENT_H
#define EVENEMENT_H

#include <QMainWindow>
#include <QFileDialog>
#include <QProgressBar>
#include <QSlider>

#include <QMainWindow>
#include"gestion_evenement.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Evenement; }
QT_END_NAMESPACE

class Evenement : public QDialog
{
    Q_OBJECT

public:
    Evenement(QWidget *parent = nullptr);
    ~Evenement();

private slots:
    void on_pB_AjouterP_clicked();

    void on_pB_SupprimerP_clicked();

    void on_pB_ModifierP_clicked();

    void on_pB_TirerParNom_clicked();

    void on_pB_TireParType_clicked();

    void on_pB_TirerParNbPersonnes_clicked();

    void on_pushButton_Fermer_clicked();

    void on_pB_Recherche_clicked();

    void on_pB_export_pdf_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_pB_Recherche_2_clicked();

private:
    Ui::Evenement *ui;
    gestion_evenement E;
    QProgressBar* bar;
    QSlider* slider;
};


#endif // EVENEMENT_H
