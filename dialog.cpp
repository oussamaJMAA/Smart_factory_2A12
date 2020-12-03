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

void Dialog::setdechet(Dechet d)
{
    ui->lineEdit_RefD->setText(d.get_Ref());
    ui->lineEdit_VolumeD->setText(d.get_Volume());
    ui->lineEdit_NatureD->setText(d.get_Nature());
    ui->lineEdit_ModeD->setText(d.get_Mode());
    ui->lineEdit_FilierD->setText(d.get_Filiere());
    ui->lineEdit_LieuD->setText(d.get_Lieu());


}
