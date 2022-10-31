#ifndef FOND_H
#define FOND_H

#include <QDialog>

namespace Ui {
class FOND;
}

class FOND : public QDialog
{
    Q_OBJECT

public:
    explicit FOND(QWidget *parent = nullptr);
    ~FOND();

private:
    Ui::FOND *ui;
};

#endif // FOND_H
