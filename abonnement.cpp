#include "abonnement.h"
#include "ui_abonnement.h"

abonnement::abonnement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::abonnement)
{
    ui->setupUi(this);
}

abonnement::~abonnement()
{
    delete ui;
}
