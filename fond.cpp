#include "fond.h"
#include "ui_fond.h"

FOND::FOND(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FOND)
{
    ui->setupUi(this);
}

FOND::~FOND()
{
    delete ui;
}
