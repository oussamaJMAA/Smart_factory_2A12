#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::setcontact(Contrat c)
{
      QString res = QString::number(c.get_pt());
       QString pri = QString::number(c.get_prixelement());
        QString quantite = QString::number(c.get_qte());
    ui->lineEdit_numd->setText(c.get_num());
    ui->lineEdit_dated->setDate(c.get_date());
    ui->lineEdit_qted->setText(quantite);
    ui->lineEdit_ptd->setText(res);
    ui->lineEdit_pd->setText(pri);


}
