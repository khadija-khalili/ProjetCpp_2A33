#ifndef ABONNEMENT_H
#define ABONNEMENT_H

#include <QDialog>

namespace Ui {
class abonnement;
}

class abonnement : public QDialog
{
    Q_OBJECT

public:
    explicit abonnement(QWidget *parent = nullptr);
    ~abonnement();

private:
    Ui::abonnement *ui;
};

#endif // ABONNEMENT_H
