#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dechet.h"
#include "collecteur.h"
#include <QValidator>
#include <QStackedWidget>
#include <QMessageBox>
#include <QPixmap>
#include <QPrinter>
#include <QPrintDialog>
#include<QPrintPreviewDialog>
#include<QPainter>
#include <QSystemTrayIcon>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_Ref->setValidator(new QIntValidator(0,999999999,this));
    ui->lineEdit_Volume->setValidator(new QIntValidator(0,999999999,this));
    ui->lineEdit_Id->setValidator(new QIntValidator(0,999999999,this));
    ui->tabDechet->setModel(d.afficher());
    ui->tabCollecteur->setModel(c.afficher());
    QPixmap a ("C:/Users/ahmed/OneDrive/Bureau/smart.jpg");
    ui->label_9->setPixmap(a);
    QPixmap z ("C:/Users/ahmed/OneDrive/Bureau/smart.jpg");
    ui->label_Pic->setPixmap(z);
    QPixmap e ("C:/Users/ahmed/OneDrive/Bureau/smart.jpg");
    ui->label_Pic2->setPixmap(e);
    QPixmap t ("C:/Users/ahmed/OneDrive/Bureau/smart.jpg");
    ui->label_Pic5->setPixmap(t);
    QPixmap y ("C:/Users/ahmed/OneDrive/Bureau/smart.jpg");
    ui->label_Pic6->setPixmap(y);
    QPixmap u ("C:/Users/ahmed/OneDrive/Bureau/smart.jpg");
    ui->label_Pic7->setPixmap(u);
    QPixmap i ("C:/Users/ahmed/OneDrive/Bureau/smart.jpg");
    ui->label_Pic8->setPixmap(i);
    QPixmap o ("C:/Users/ahmed/OneDrive/Bureau/smart.jpg");
    ui->label_Pic9->setPixmap(o);
    QPixmap x ("C:/Users/ahmed/OneDrive/Bureau/smart.jpg");
    ui->label_10->setPixmap(x);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_5_clicked()
{
 ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}

void MainWindow::on_pushButton_13_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_16_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_17_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_18_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_19_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_20_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_21_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_22_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_14_clicked()
{
    {
        QString Ref=ui->lineEdit_Ref->text();
        QString Volume=ui->lineEdit_Volume->text();
        QString Nature=ui->lineEdit_Nature->text();
        QString Mode=ui->lineEdit_Mode->text();
        QString Filiere=ui->lineEdit_Filiere->text();
        QString Lieu=ui->lineEdit_Lieu->text();
        Dechet d(Ref,Volume,Nature,Mode,Filiere,Lieu);

        bool test=d.ajouter();
        QMessageBox msgBox;

        if(test)
          {  msgBox.setText("Ajout avec succes.");
            ui->tabDechet->setModel(d.afficher());
        }
        else
            msgBox.setText("Echec d'ajout");
            msgBox.exec();
            notification_ajout();
    }
}

void MainWindow::on_pushButton_15_clicked()
{
    QString Id=ui->lineEdit_Id->text();
    QString Nom=ui->lineEdit_Nom->text();
    QString Adresse=ui->lineEdit_Adr->text();
    collecteur c(Id,Nom,Adresse);
    bool test=c.ajouter();
    QMessageBox msgBox;

    if(test)
      {  msgBox.setText("Ajout avec succes.");
        ui->tabCollecteur->setModel(c.afficher());
    }
    else
        msgBox.setText("Echec d'ajout");
        msgBox.exec();
        notification_ajout1();
}

void MainWindow::on_pushButton_11_clicked()
{
    collecteur c1;
    c1.setId(ui->lineEdit_sup->text());
    bool test=c1.supprimer(c1.get_Id());
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Suppression avec succes.");
    ui->tabCollecteur->setModel(c1.afficher());

    }
    else
        msgBox.setText("Echec de suppression");
        msgBox.exec();
}

void MainWindow::on_pushButton_12_clicked()
{
    Dechet d1;
    d1.setRef(ui->lineEdit_sup2->text());
    bool test=d1.supprimer(d1.get_Ref());
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Suppression avec succes.");
    ui->tabCollecteur->setModel(d1.afficher());

    }
    else
        msgBox.setText("Echec de suppression");
        msgBox.exec();
}

void MainWindow::on_pushButton_9_clicked()
{
    QString Ref=ui->lineEdit_Ref2->text();
    QString Volume=ui->lineEdit_Volume2->text();
    QString Nature=ui->lineEdit_Nature2->text();
    QString Mode=ui->lineEdit_Mode2->text();
    QString Filiere=ui->lineEdit_Filiere2->text();
    QString Lieu=ui->lineEdit_Lieu2->text();
    Dechet d;
    bool test=d.modifier(Ref,Volume,Nature,Mode,Filiere,Lieu);
    ui->tabDechet->setModel(tabd.afficher());

    if(test)
    {ui->tabDechet->setModel(tabd.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("modifier un Dechet"),
                    QObject::tr("Dechet modifié.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("modifier un Dechet"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    notification_modifier();
}

void MainWindow::on_pushButton_10_clicked()
{
    QString Id=ui->lineEdit_Id2->text();
    QString Nom=ui->lineEdit_Nom2->text();
    QString Adresse=ui->lineEdit_Adr2->text();
    collecteur c;
    bool test=c.modifier(Id,Nom,Adresse);
    ui->tabCollecteur->setModel(tabc.afficher());

    if(test)
    {ui->tabCollecteur->setModel(tabc.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("modifier un Collecteur"),
                    QObject::tr("Collecteur modifié.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("modifier un Collecteur"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    notification_modifier1();
}

void MainWindow::on_pushButton_23_clicked()
{
    QPrinter printer;
        printer.setResolution(QPrinter::HighResolution);
            printer.setPaperSize(QPrinter::A4);
            printer.setOrientation(QPrinter::Landscape);
            printer.setFullPage(true);


            QPrintPreviewDialog *printPreview = new QPrintPreviewDialog(&printer);
            connect(printPreview, SIGNAL(paintRequested(QPrinter*)), this, SLOT(print(QPrinter*)));

            printPreview->setWindowTitle("Dechets");
            Qt::WindowFlags flags(Qt::WindowTitleHint);
            printPreview->setWindowFlags(flags);
            printPreview->exec();

}
void MainWindow::print(QPrinter* printer)
{
        QPainter painter(printer);

            painter.setRenderHints(QPainter::Antialiasing |
                               QPainter::TextAntialiasing |
                               QPainter::SmoothPixmapTransform, true);

           painter.setWindow(ui->tabWidget->rect());
           ui->tabWidget->render(&painter);

}
void MainWindow::notification_ajout()
{
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    notifyIcon->show();
    notifyIcon->setIcon(QIcon("icon.png"));
    notifyIcon->showMessage("Ajout","Un nouveau Dechet a été ajouté",QSystemTrayIcon::Information,15000);
}
void MainWindow::notification_ajout1()
{
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    notifyIcon->show();
    notifyIcon->setIcon(QIcon("icon.png"));
    notifyIcon->showMessage("Ajout","Un nouveau collecteur a été ajouté",QSystemTrayIcon::Information,15000);
}

void MainWindow::notification_modifier()
{
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    notifyIcon->show();
    notifyIcon->setIcon(QIcon("icon.png"));
    notifyIcon->showMessage("Modification","Un Dechet a été modifié",QSystemTrayIcon::Information,15000);
}
void MainWindow::notification_modifier1()
{
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    notifyIcon->show();
    notifyIcon->setIcon(QIcon("icon.png"));
    notifyIcon->showMessage("Modification","Un collecteur a été modifié",QSystemTrayIcon::Information,15000);
}
