#include "welcome.h"
#include "ui_welcome.h"
#include "login.h"

welcome::welcome(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::welcome)
{
    ui->setupUi(this);
}

welcome::~welcome()
{
    delete ui;
}

void welcome::on_pushButton_clicked()
{
    login login;
    login.setModal(true);
    login.exec();
}
