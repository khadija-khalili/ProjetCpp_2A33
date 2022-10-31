#include "fidelite.h"
#include "ui_fidelite.h"

fidelite::fidelite(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fidelite)
{
    ui->setupUi(this);
}

fidelite::~fidelite()
{
    delete ui;
}
