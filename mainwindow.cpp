#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <materiaux.h>
#include <fournisseurs.h>
#include <QApplication>
#include "dialog.h"
QT_CHARTS_USE_NAMESPACE
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{

    ui->setupUi(this);
//initialisation  et controle de saisie
    //commment
    //lol

ui->stackedWidget_2->setCurrentIndex(0); // intialiser le deuxieme widget(fournisseur)
  ui->stackedWidget->setCurrentIndex(0);// initialiser le premier widget(materiaux)
    //controle de saisie pour les nombres
ui->lineEdit_20->setValidator(new QIntValidator(0,99999999,this));//id_fournisseur
//ui->lineEdit_23->setValidator(new QIntValidator(0,99999,this));//ref_materiel
ui->lineEdit_22->setValidator(new QIntValidator(0,99999999,this));//numero tel(8 chiffres)

ui->lineEdit_29->setValidator(new QIntValidator(0,99999,this));//remise materiel
ui->lineEdit_27->setValidator(new QIntValidator(0,99999,this));//id_fournisseur
ui->lineEdit_15->setValidator(new QIntValidator(0,99999,this));//id
ui->lineEdit_17->setValidator(new QDoubleValidator(-99.0,99.0,4,this));//prix
ui->lineEdit_19->setValidator(new QIntValidator(0,99999,this));//quantite
ui->lineEdit_10->setValidator(new QIntValidator(0,99999,this));//quantite
ui->lineEdit_11->setValidator(new QIntValidator(0,99999,this));//quantite_dispo
ui->lineEdit_13->setValidator(new  QDoubleValidator(-99.0,99.0,4,this));//prix
ui->lineEdit_14->setValidator(new QIntValidator(0,99999,this));//id
ui->lineEdit_19->setValidator(new QIntValidator(0,9999,this));//quantite
ui->lineEdit_28->setValidator(new  QDoubleValidator(-99.0,99.0,4,this));//prix
    //animation pour logo fusesmart
    int w=ui->logo->width();
    int h=ui->logo->height();
    animation = new QPropertyAnimation(ui->logo,"geometry");
    animation->setDuration(10000);
    animation->setStartValue(ui->logo->geometry());
    animation->setEndValue(QRect(0,20,w,h));

    QEasingCurve curve;
    curve.setType(QEasingCurve::OutBounce);
    animation->setEasingCurve(curve);
    //curve.setAmplitude(2.00);
    curve.setOvershoot(1.30);
    curve.setPeriod(0.50);
    animation->setLoopCount(-1);

    animation->start();
 //animation pour logo sofap

    int w1=ui->label_7->width();
    int h1=ui->label_7->height();
    animation1 = new QPropertyAnimation(ui->label_7,"geometry");
    animation1->setDuration(10000);
    animation1->setStartValue(ui->label_7->geometry());
    animation1->setEndValue(QRect(500,200,w1,h1));
    QEasingCurve curve2;
    curve2.setType(QEasingCurve::OutBounce);
    animation1->setEasingCurve(curve2);
    curve2.setOvershoot(1.30);
    curve2.setPeriod(0.50);
    animation1->setLoopCount(-1);

      animation1->start();

//animation logo sofap dans le tab fournisseur

      int w2=ui->sopal->width();
      int h2=ui->sopal->height();
      animation2 = new QPropertyAnimation(ui->sopal,"geometry");
      animation2->setDuration(10000);
      animation2->setStartValue(ui->sopal->geometry());
      animation2->setEndValue(QRect(500,400,w2,h2));
    /*  QEasingCurve curve3;
      curve3.setType(QEasingCurve::OutBounce);
      animation1->setEasingCurve(curve3);
      curve3.setOvershoot(1.30);
      curve3.setPeriod(0.50);*/
      animation2->setLoopCount(-1);

        animation2->start();


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked() // boutton ajouter materiaux
{
    QMediaPlayer *musicLogin= new QMediaPlayer;
   musicLogin->setMedia(QUrl("C:/Users/oussa/Desktop/bouttonsound.mp3"));
       musicLogin->play();
     ui->stackedWidget->setCurrentIndex(1);



}

void MainWindow::on_pushButton_2_clicked() // boutton afficher materiaux

{ui->stackedWidget->setCurrentIndex(2);
    QMediaPlayer *musicLogin= new QMediaPlayer;
   musicLogin->setMedia(QUrl("C:/Users/oussa/Desktop/bouttonsound.mp3"));
       musicLogin->play();
ui->tableView->setModel(Etmp.afficher());
//ui->comboBox->setModel(Etmp.afficher());
//ui->lineEdit_10
}

void MainWindow::on_modifier_2_clicked() // boutton modifier
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_10_clicked() // boutton retour du widget modifier
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_supprimer_2_clicked() // boutton supprimer
{


     ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_15_clicked() // boutton retour du widget supprimer
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_quitter_2_clicked() // retour du menu afficher
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_3_clicked() // quitter l'application


{
    QMediaPlayer *musicLogin= new QMediaPlayer;
   musicLogin->setMedia(QUrl("C:/Users/oussa/Desktop/applepay.mp3"));
       musicLogin->play();


    QMessageBox::StandardButton reply = QMessageBox::question(this,"fenêtre","voulez vous quittez",QMessageBox::Yes| QMessageBox::No);

    if(reply==QMessageBox::Yes){
        QApplication::quit();
    }else{
        qDebug()<<"no is clicked";
    }




}



void MainWindow::on_pushButton_16_clicked()// boutton ajouter
{
    QString ref_materiel=ui->lineEdit_15->text();
   QString nom_materiel=ui->lineEdit_16->text();
          double prix=ui->lineEdit_17->text().toDouble();
           int quantite_res=ui->lineEdit_18->text().toInt();
            int quantite=ui->lineEdit_19->text().toInt();
QDate date_achat= ui->date->date();

                   materiaux m(ref_materiel,nom_materiel,prix,quantite,quantite_res,date_achat);
                   bool test=m.ajouter();
                   if (test){
                      ui->tableView->setModel(Etmp.afficher());

                       QMessageBox::information(nullptr,QObject::tr("OK"),
                                                QObject::tr("Ajouter Effectuer\n"
                                                            "click cancel to exit"),QMessageBox::Cancel);
                       }
                       else
                           QMessageBox::critical(nullptr,QObject::tr("Nor OK"),
                                                 QObject::tr("Ajouter non Effectuer"),QMessageBox::Cancel);




}


void MainWindow::on_pushButton_17_clicked() // boutton undo (ajouter)
{
    ui->lineEdit_15->setText("");
    ui->lineEdit_16->setText("");
    ui->lineEdit_17->setText("");
    ui->lineEdit_18->setText("");
    ui->lineEdit_19->setText("");

}


void MainWindow::on_pushButton_18_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_12_clicked() //boutton modifier (dans le widget modifier)
{
    QString ref_materiel=ui->lineEdit_31->text();
    QString nom_materiel=ui->lineEdit_12->text();
   int quantite =ui->lineEdit_10->text().toInt();
          int  quantite_res=ui->lineEdit_11->text().toInt();
           double prix=ui->lineEdit_13->text().toDouble();
           QDate date_achat = ui->date_modifier->date();
           materiaux m(ref_materiel,nom_materiel,prix,quantite,quantite_res,date_achat);
           bool test=m.modifier(ref_materiel);
           if (test){
              ui->tableView->setModel(Etmp.afficher());

               QMessageBox::information(nullptr,QObject::tr("OK"),
                                        QObject::tr("modifier Effectuer\n"
                                                    "click cancel to exit"),QMessageBox::Cancel);
               }
               else
                   QMessageBox::critical(nullptr,QObject::tr("Nor OK"),
                                         QObject::tr("modifier non Effectuer"),QMessageBox::Cancel);




}



void MainWindow::on_pushButton_11_clicked() // boutton undo (modifier)
{
    ui->lineEdit_12->setText("");
    ui->lineEdit_10->setText("");
    ui->lineEdit_11->setText("");
    ui->lineEdit_13->setText("");

}


void MainWindow::on_pushButton_13_clicked() // boutton supprimer(widget supprimer)
{
   QString ref_materiel= ui->lineEdit_14->text();
   /*if(ref_materiel==""){
        QMessageBox::warning(this,"ERROR","Veuillez remplir le champ requis");
       */  QItemSelectionModel *select=ui->tableView->selectionModel();
 QString idd=select->selectedRows(0).value(0).data().toString();
         bool test=Etmp.supprimer(ref_materiel);
         if(test){
ui->tableView->setModel(Etmp.afficher());
             QMessageBox::information(nullptr,QObject::tr("OK"),
                                      QObject::tr("supprimer Effectuer\n"
                                                  "click cancel to exit"),QMessageBox::Cancel);
             }
             else
                 QMessageBox::critical(nullptr,QObject::tr("Not OK"),

                                       QObject::tr("supprimer non Effectuer"),QMessageBox::Cancel);
         }






void MainWindow::on_pushButton_14_clicked() //boutton undo supprimer
{

ui->lineEdit_14->setText("");
}

void MainWindow::on_pushButton_19_clicked() //boutton ajouter
{
     ui->stackedWidget_2->setCurrentIndex(1);



}

void MainWindow::on_pushButton_21_clicked() // retour (ajouter fournisseur)
{
    QMediaPlayer *musicLogin= new QMediaPlayer;
   musicLogin->setMedia(QUrl("C:/Users/oussa/Desktop/bouttonsound.mp3"));
       musicLogin->play();
    ui->stackedWidget_2->setCurrentIndex(0);

}

void MainWindow::on_pushButton_20_clicked() //boutton afficher fournisseur
{ QMediaPlayer *musicLogin= new QMediaPlayer;
    musicLogin->setMedia(QUrl("C:/Users/oussa/Desktop/bouttonsound.mp3"));
        musicLogin->play();
        ui->tableView_2->setModel(Etmp1.afficher_fournisseur());
     ui->stackedWidget_2->setCurrentIndex(2);
}

void MainWindow::on_quitter_3_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);//retour aprés afficher fournisseur
}

void MainWindow::on_modifier_3_clicked() // boutton modifier fournisseur
{
    ui->stackedWidget_2->setCurrentIndex(3);
}

void MainWindow::on_pushButton_25_clicked() //boutton retour (widget modifier fournisseur)
{
    ui->stackedWidget_2->setCurrentIndex(2);
}


void MainWindow::on_supprimer_3_clicked() // boutton supprimer (affichage fournisseur)
{

    ui->stackedWidget_2->setCurrentIndex(4);
}


void MainWindow::on_pushButton_28_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(2);
}

void MainWindow::on_pushButton_4_clicked()//"editer statistique

{ QMediaPlayer *musicLogin= new QMediaPlayer;
    musicLogin->setMedia(QUrl("C:/Users/oussa/Desktop/bouttonsound.mp3"));
        musicLogin->play();
   ui->stackedWidget->setCurrentIndex(5);

 ui->tableView_3->setModel(Etmp.stat());

 //ui->tableView_3->setModel(Etmp.stat_2());
}




void MainWindow::on_retour_clicked()
{
       ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_24_clicked() //quitter l'application du widget fournisseur

{
    QMediaPlayer *musicLogin= new QMediaPlayer;
   musicLogin->setMedia(QUrl("C:/Users/oussa/Desktop/applepay.mp3"));
       musicLogin->play();


    QMessageBox::StandardButton reply = QMessageBox::question(this,"fenêtre","voulez vous quittez",QMessageBox::Yes| QMessageBox::No);

    if(reply==QMessageBox::Yes){
        QApplication::quit();
    }else{
        qDebug()<<"no is clicked";
    }


}




void MainWindow::on_pushButton_22_clicked() // ajouter  fournisseur dans le widget ajouter
{
    QString reference_materiel=ui->lineEdit_23->text();

   QString mail_fournisseur=ui->lineEdit_21->text();
           QString nom_fournisseur=ui->lineEdit_24 ->text();
          double solde=ui->lineEdit_28->text().toDouble();
           int id_fournisseur=ui->lineEdit_20->text().toInt();
            int tel_founrisseur=ui->lineEdit_22->text().toInt();


                   fournisseurs f(nom_fournisseur, mail_fournisseur,reference_materiel, tel_founrisseur, id_fournisseur, solde);
                   bool test=f.ajouter_fournisseur();
                   if (test){
                      ui->tableView_2->setModel(Etmp1.afficher_fournisseur());

                       QMessageBox::information(nullptr,QObject::tr("OK"),
                                                QObject::tr("Ajouter Effectuer\n"
                                                            "click cancel to exit"),QMessageBox::Cancel);
                       }
                       else
                           QMessageBox::critical(nullptr,QObject::tr("Nor OK"),
                                                 QObject::tr("Ajouter non Effectuer"),QMessageBox::Cancel);

}

void MainWindow::on_pushButton_29_clicked() // supprimer dans le widget supprimer
{int id_fournisseur = ui->lineEdit_27->text().toInt();

          bool test=Etmp1.supprimer_fournisseur(id_fournisseur);
          if(test){
 ui->tableView_2->setModel(Etmp1.afficher_fournisseur());
              QMessageBox::information(nullptr,QObject::tr("OK"),
                                       QObject::tr("supprimer Effectuer\n"
                                                   "click cancel to exit"),QMessageBox::Cancel);
              }
              else
                  QMessageBox::critical(nullptr,QObject::tr("Not OK"),

                                        QObject::tr("supprimer non Effectuer"),QMessageBox::Cancel);

}

void MainWindow::on_pushButton_26_clicked() // modifier fournisseur (modifier)
{
    QString reference_materiel=ui->lineEdit_29->text();
    QString nommateriel=ui->lineEdit_26->text();



           bool test=Etmp1.modifier_fournisseur(reference_materiel,nommateriel);
           if (test){
              ui->tableView_2->setModel(Etmp1.afficher_fournisseur());

               QMessageBox::information(nullptr,QObject::tr("OK"),
                                        QObject::tr("modifier Effectuer\n"
                                                    "click cancel to exit"),QMessageBox::Cancel);
               }
               else
                   QMessageBox::critical(nullptr,QObject::tr("Nor OK"),
                                         QObject::tr("modifier non Effectuer"),QMessageBox::Cancel);
}

void MainWindow::on_supprimer_4_clicked() // trier materiaux
{

     ui->tableView->setModel(Etmp.trier());
}

void MainWindow::on_trier_clicked() // trier fournisseur
{

 ui->tableView_2->setModel(Etmp1.trier1());
}




void MainWindow::on_tableView_2_activated(const QModelIndex &index)
{



     QString id = ui->tableView_2->model()->data(index).toString();
     QSqlQuery query;
     query.prepare(" select * from fournisseur  where id_fournisseur = '"+id+"'");

   //  ui->tableView_2->setStyleSheet("QTableView { selection-color: black; selection-background-color: green; }");
     if(query.exec())
     {
         while (query.next())
         {
 ui->lineEdit_29->setText(query.value(0).toString());
             ui->lineEdit_26->setText(query.value(1).toString());


         }
}
}

void MainWindow::on_tableView_activated(const QModelIndex &index)
{
    QString ref_materiel = ui->tableView->model()->data(index).toString();
    QSqlQuery query;
    query.prepare(" select * from materiaux where ref_materiel = '"+ref_materiel+"'");
    if(query.exec())
    {
        while (query.next())
        {
ui->lineEdit_31->setText(query.value(0).toString());
         ui->lineEdit_12->setText(query.value(1).toString());
            ui->lineEdit_10->setText(query.value(2).toString());
            ui->lineEdit_11->setText(query.value(3).toString());
            ui->lineEdit_13->setText(query.value(4).toString());
            ui->date_modifier->setDate(query.value(5).toDate());


        }
}

}



void MainWindow::on_rechercher_ref_cursorPositionChanged()
{
    materiaux m;
    ui->tableView->setModel(m.rechercher(ui->rechercher_ref->text()));
    m.afficher();
}

void MainWindow::on_rechercher_id_cursorPositionChanged()
{
    fournisseurs f ;
    ui->tableView_2->setModel(f.rechercher1(ui->rechercher_id->text()));
            f.afficher_fournisseur();
}


void MainWindow::on_tableView_3_activated(const QModelIndex &index)
{
int x = ui->tableView_3->model()->data(index).toInt();
//int y = ui->tableView_3->SelectedClicked;
    Dialog d;

    QPieSeries *series1 = new QPieSeries();

    series1->append("Quantite Materiaux",1444);


    QPieSeries *series3 = new QPieSeries();

    series3->append("quantite restante",x);

    DonutBreakdownChart *donutBreakdown = new DonutBreakdownChart();
    donutBreakdown->setAnimationOptions(QChart::AllAnimations);
    donutBreakdown->setTitle("Materiaux");
    donutBreakdown->legend()->setAlignment(Qt::AlignRight);
   donutBreakdown->addBreakdownSeries(series1, Qt::red);

    donutBreakdown->addBreakdownSeries(series3, Qt::darkBlue);
    //![2]

    //![3]
    QMainWindow window;
    QChartView *chartView = new QChartView(donutBreakdown);
    chartView->setRenderHint(QPainter::Antialiasing);
    window.setCentralWidget(chartView);
    window.resize(800, 500);
    window.show();
    d.exec();
}

void MainWindow::on_pushButton_23_clicked() // undo fournisseur (ajouter  )
{
    ui->lineEdit_20->setText("");
    ui->lineEdit_21->setText("");
    ui->lineEdit_22->setText("");
    ui->lineEdit_23->setText("");
    ui->lineEdit_24->setText("");

     ui->lineEdit_28->setText("");

}

void MainWindow::on_pushButton_27_clicked() // undo fournisseur (modifier)
{
    ui->lineEdit_29->setText("");
    ui->lineEdit_26->setText("");
}

void MainWindow::on_pushButton_30_clicked() // undo fournisseur (supprimer)
{
    ui->lineEdit_27->setText("");
}
