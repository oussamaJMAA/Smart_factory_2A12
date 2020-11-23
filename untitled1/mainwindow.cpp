#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include <QValidator>
#include"contrat.h"
#include<QDate>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_id->setValidator(new QIntValidator(0,9999999,this));
    ui->lineEdit_p->setValidator(new QIntValidator(0,999999,this));
    ui->lineEdit_pt->setValidator(new QIntValidator(0,999999,this));
    ui->lineEdit_qte->setValidator(new QIntValidator(0,999,this));
    ui->tabClient->setModel(c.afficher());
    ui->tabContrat->setModel(co.afficher());


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_14_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_11_clicked()
{
    QString id=ui->lineEdit_id->text();
    QString nom=ui->lineEdit_nom->text();
    QString adr=ui->lineEdit_adr->text();
    Client c(id,nom,adr);

    bool test=c.ajouter();
    QMessageBox msgBox;

    if(test)
      {  msgBox.setText("Ajout avec succes.");
        ui->tabClient->setModel(c.afficher());
    }
    else
        msgBox.setText("Echec d'ajout");
        msgBox.exec();
}

void MainWindow::on_pushButton_10_clicked()
{
    QString num=ui->lineEdit_num->text();
    QString type=ui->lineEdit_type->text();
    QDate datec=ui->dateEdit->date();
    int qte=ui->lineEdit_qte->text().toInt();
    float pt=ui->lineEdit_pt->text().toInt();
    float prix=ui->lineEdit_p->text().toInt();
     Contrat co(num ,type,  prix , qte,  datec , pt);
     bool test=co.ajouter();
     QMessageBox msgBox;

     if(test)
       {  msgBox.setText("Ajout avec succes.");
         ui->tabContrat->setModel(co.afficher());
     }
     else
         msgBox.setText("Echec d'ajout");
         msgBox.exec();

}

void MainWindow::on_pushButton_12_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_13_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_16_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}




void MainWindow::on_pushButton_18_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_17_clicked()
{
    Contrat co1;
    co1.setnum(ui->lineEdit_supn->text());
    bool test=co1.supprimer(co1.get_num());
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Suppression avec succes.");
    ui->tabContrat->setModel(co1.afficher());

    }
    else
        msgBox.setText("Echec de suppression");
        msgBox.exec();
}



void MainWindow::on_pushButton_15_clicked()
{

    Client c1;
    c1.setid(ui->lineEdit_supi->text());
    bool test=c1.supprimer(c1.get_id());
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Suppression avec succes.");
    ui->tabClient->setModel(c.afficher());

    }
    else
        msgBox.setText("Echec de suppression");
        msgBox.exec();
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}





void MainWindow::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}
