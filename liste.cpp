#include "liste.h"
#include "ui_dialogg.h"

Dialogg::Dialogg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogg)
{
    ui->setupUi(this);
}

Dialogg::~Dialogg()
{
    delete ui;
}
