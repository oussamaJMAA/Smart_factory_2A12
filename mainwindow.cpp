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


    if(username=="" && password=="")
    {
        ui->label_errur->setText("Entrer votre compte .");
        errur=1;
    }

    else if(password=="")
    {
        ui->label_errur->setText("Entrer votre Mot de passe .");
        errur=1;
    }

    else if(username=="")
    {

        errur=1;
        ui->label_errur->setText("Entrer votre Utilisateur .");
    }



    // ********************************************   Login   ****************************************


    username=username.toUpper();
    password=password.toUpper();
    qDebug()<<username +" "+password ;

    if(!e.login(username,password))
    {errur=1;
        ui->label_errur->setText("Votre Utilisateur ou Mot de passe  est incorrect  .");
           }

    if (errur==0)
       {
        this->hide();
          GetMusic();
          a.Set_Identifiant(username);
          a.Get_utilisateur();
          a.show();
          a.showFullScreen();
          a.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

          a.exec();

       }





}

void MainWindow::on_exit_clicked()
{
    this->close();
}

