#ifndef DIALOG_H
#define DIALOG_H
#include "dechet.h"

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    void setdechet(Dechet d);
    ~Dialog();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
