#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent):QMainWindow(parent) , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap logo("C:/Users/Nasreddine/Documents/FuseSmart/logo.png");




    musicLogin->setMedia(QUrl("C:/Users/Nasreddine/Documents/FuseSmart/loginmp3.mp3"));


    ui->FuseSmart->setPixmap(logo);

}
void MainWindow::GetMusic()
{
    musicLogin->play();
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::GetLogin()
{
    username=ui->user->text();
    password=ui->password->text();
}

void MainWindow::on_pushButton_clicked()
{

    acceuil a;

    int errur =0;

    connection c;

    GetLogin();


    if(username!="" && password!="")
        errur=0;
    else if(username=="" && password=="")
    {
        ui->label_errur->setText("Utilisateur et Mot de passe entré ne correspond à aucun compte.");
        errur=1;
    }

    else if(password=="")
    {
        ui->label_errur->setText("Mot de passe entré ne correspond à aucun compte.");
        errur=1;
    }

    else if(username=="")
    {

        errur=1;
        ui->label_errur->setText("l'utilisateur entré ne correspond à aucun compte.");
    }



    // ********************************************   Login   ****************************************
    username=username.toUpper();
    password=password.toUpper();
    QSqlQuery qry;
    qry.prepare("SELECT CIN FROM employeurs where CIN=? and prenom=?;");
    qry.addBindValue(username);
    qry.addBindValue(password);
    errur=1;
    if(qry.exec())
        if(qry.next())
            {
            QVariant ch=qry.value(0);
            QString verif = QVariant(ch).toString();
            qDebug()<<verif;
            if(verif==username)
                errur=0;
            }
    if (errur==0)
       { this->hide();
          GetMusic();
          a.show();
          a.exec();
       }






}
