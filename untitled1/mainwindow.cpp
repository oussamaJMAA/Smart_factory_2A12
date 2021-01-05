#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include <QValidator>
#include"contrat.h"
#include<QDate>
#include <QMessageBox>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap x ("C:/Users/Mega Pc/Desktop/c qt/img/green101.jpg");
    ui->label_pic_2->setPixmap(x);
    QPixmap fspic ("C:/Users/Mega Pc/Desktop/c qt/fs/Capture.png");
    ui->label_fs->setPixmap(fspic);
    QPixmap fcspi ("C:/Users/Mega Pc/Desktop/c qt/fs/Capture.png");
    ui->label_fs_2->setPixmap(fcspi);
    QPixmap smart ("C:/Users/Mega Pc/Desktop/c qt/img/green101.jpg");
    ui->label_pic_x->setPixmap(smart);
    QPixmap llll ("C:/Users/Mega Pc/Desktop/c qt/fs/Capture.png");
    ui->label_10->setPixmap(llll);
    QPixmap pics ("C:/Users/Mega Pc/Desktop/SF.jpg");
    ui->label_smartfactory->setPixmap(pics);
    QPixmap a ("C:/Users/Mega Pc/Desktop/SF.jpg");
    ui->label_10->setPixmap(a);
    QPixmap z ("C:/Users/Mega Pc/Desktop/SF.jpg");
    ui->label_16->setPixmap(z);
    QPixmap e ("C:/Users/Mega Pc/Desktop/c qt/fs/Capture.png");
    ui->label_18->setPixmap(e);
    QPixmap f ("C:/Users/Mega Pc/Desktop/SF.jpg");
    ui->label_20->setPixmap(f);
    QPixmap u ("C:/Users/Mega Pc/Desktop/SF.jpg");
    ui->label_21->setPixmap(u);
    QPixmap k ("C:/Users/Mega Pc/Desktop/c qt/fs/Capture.png");
    ui->label_3->setPixmap(k);
    QPixmap j("C:/Users/Mega Pc/Desktop/c qt/fs/Capture.png");
    ui->label_2->setPixmap(j);


    ui->lineEdit_id->setValidator(new QIntValidator(0,9999999,this));
    ui->lineEdit_p->setValidator(new QIntValidator(0,999999,this));
    ui->lineEdit_pt->setValidator(new QIntValidator(0,999999,this));
    ui->lineEdit_p->setValidator(new QIntValidator(0,999999,this));
    ui->lineEdit_p_2->setValidator(new QIntValidator(0,999999,this));
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
    QString idclient=ui->lineEdit_idclient->text();
    QString REf_mat=ui->lineEdit_ref->text();
     Contrat co(num ,type,  prix , qte,  datec , pt , idclient , REf_mat);
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



void MainWindow::on_pushButton_3_clicked()
{

   ui->stackedWidget->setCurrentIndex(7);

}
void MainWindow::on_pushButton_19_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_20_clicked()
{
    QString id=ui->lineEdit_id_2->text();
    QString nom=ui->lineEdit_m->text();
    QString adr=ui->lineEdit_adrm->text();
    Client c;
    bool test=c.modifier(id,nom,adr);
    ui->tabClient->setModel(tabc.afficher());

    if(test)
    {ui->tabClient->setModel(tabc.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("modifier un Client"),
                    QObject::tr("client modifier.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("modifier un Client"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}




void MainWindow::on_pushButton_22_clicked()
{
    QString num=ui->lineEdit_num_2->text();
    QString type=ui->lineEdit_type_2->text();
    QDate datec=ui->dateEdit_2->date();
    float prix=ui->lineEdit_p_2->text().toFloat();
    float pt=ui->lineEdit_pt_2->text().toFloat();
    int qte=ui->lineEdit_qte_2->text().toInt();
     Contrat co;
    bool test=co.modifier(num,type,prix,qte,pt);
    ui->tabContrat->setModel(tabco.afficher());

    if(test)
    {ui->tabContrat->setModel(tabco.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("modifier un Contrat"),
                    QObject::tr("client modifier.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("modifier un Contrat"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}




void MainWindow::on_pushButton_21_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}




void MainWindow::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}





void MainWindow::on_pushButton_23_clicked()
{
    ui->tabClient->setModel(tabc.trier());
}





void MainWindow::on_pushButton_24_clicked()
{
   ui->tabContrat->setModel(tabco.trierc());
}





void MainWindow::on_pushButton_25_clicked()
{
    QString chaine;
    chaine=ui->lineEdit_recherche->text();
    Client cl;

    QSqlQueryModel * model =new QSqlQueryModel();
    model = cl.rechercher(chaine);
    ui->tabClient->setModel(model);

}





void MainWindow::on_pushButton_26_clicked()
{
    QString chaine1;
    chaine1=ui->lineEdit_recherche_2->text();
    Contrat col;
    QSqlQueryModel * model1 =new QSqlQueryModel();
    model1 = col.rechercherc(chaine1);
    ui->tabContrat->setModel(model1);
}

void MainWindow::on_print_clicked()
{
    QPrinter printer;
      printer.setPrinterName("desired printer name");
      QPrintDialog dialog(&printer,this);
      if (dialog.exec() == QDialog::Rejected) return ;
      ui->tabContrat->render(&printer);
}

void MainWindow::on_pushButton_29_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_pushButton_28_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}



void MainWindow::on_pushButton_27_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_30_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}
