#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "contrat.h"
#include "QString"
#include "dialog.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_p->setValidator(new QIntValidator(0,99999999,this));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
     Contrat c;

     c.setnum(ui->lineEdit_num->text());
     c.setdate(ui->date->date());
     c.setprixelement(ui->lineEdit_p->text().toFloat());
     c.setqte(ui->lineEdit_qte->text().toInt());
     c.setpt(ui->lineEdit_p->text().toFloat());

     Dialog d;
     d.setcontact(c);
     d.exec();

}
