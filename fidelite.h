#ifndef FIDELITE_H
#define FIDELITE_H

#include <QDialog>

namespace Ui {
class fidelite;
}

class fidelite : public QDialog
{
    Q_OBJECT

public:
    explicit fidelite(QWidget *parent = nullptr);
    ~fidelite();

private:
    Ui::fidelite *ui;
};

#endif // FIDELITE_H
