#include "acceuil.h"
#include "ui_acceuil.h"
#include "materiaux.h"
#include "fournisseurs.h"
#include <QMessageBox>
#include <QDebug>
#include <QApplication>
#define colorFalse "color:red;"
#define colorTrue "color:rgb(28,255,33);"
#define Transparent "color:transparent;"
#include <QFontDialog>



acceuil::acceuil(QWidget *parent) : QDialog(parent), ui(new Ui::acceuil)
{

    musicClic->setMedia(QUrl("C:/Users/oussa/Downloads/Gestion personnel (1)/Integration/clic.mp3"));
    ui->setupUi(this);

    ui->stackedWidget_2->setCurrentIndex(0); // intialiser le deuxieme widget(fournisseur)
      ui->stackedWidget->setCurrentIndex(0);// initialiser le premier widget(materiaux)
      ui->pushButton_6->setVisible(false);

    musicClic->setVolume(10);



    QPixmap addemp("C:/Users/oussa/Downloads/Gestion personnel (1)/Integration/IMG/AjouterEmployé.png"),
            addcng("C:/Users/oussa/Downloads/Gestion personnel (1)/Integration/IMG/Ajoutercongé.png");
    ui->AjouterEmploye->setPixmap(addemp);ui->AjouterConge->setPixmap(addcng);
    ui->lineEdit->setValidator(new QIntValidator(0,99999999,this));
    ui->lineEdit_5->setValidator(new QIntValidator(0,99999999,this));
    ui->LinerechCong->setValidator(new QIntValidator(0,99999999,this));
    ui->modifierCong_ID->setValidator(new QIntValidator(0,999999999,this));
    ui->supprimerCong->setValidator(new QIntValidator(0,999999999,this));
    ui->supprimerEmp->setValidator(new QIntValidator(0,99999999,this));
    ui->modifierEmp_CIN_chercher->setValidator(new QIntValidator(0,99999999,this));
    ui->lineEdit_9->setValidator(new QIntValidator(0,99999999,this));

    // contrôle de saise pour materiaux et fournisseurs
     ui->lineEdit_20->setValidator(new  QDoubleValidator(-99.0,99.0,4,this));//prix_unitaire

    ui->lineEdit_13->setValidator(new QIntValidator(0,99999999,this));//quantite_dispo

        ui->lineEdit_12->setValidator(new QIntValidator(0,99999,this));//quantite


       ui->lineEdit_17->setValidator(new QIntValidator(0,99999,this));//quantite_dispoo
       ui->lineEdit_18->setValidator(new  QDoubleValidator(-99.0,99.0,4,this));//prix
       ui->lineEdit_19->setValidator(new QIntValidator(0,99999,this));//quantite_dispo


    ui->lineEdit_22->setValidator(new QIntValidator(0,99999999,this));//id_fournisseur

    ui->lineEdit_27->setValidator(new QIntValidator(0,99999,this));//id_fournisseur
    ui->lineEdit_24->setValidator(new QDoubleValidator(-99.0,99.0,4,this));//pr
    ui->lineEdit_28->setValidator(new  QDoubleValidator(-99.0,99.0,4,this));//prix

     ui->lineEdit_30->setValidator(new  QDoubleValidator(-99.0,99.0,4,this));//prix

      ui->lineEdit_26->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+"),NULL));
      //Rafinnement TableView

      ui->affiche_mat->resizeColumnsToContents();
      ui->affiche_mat->resizeRowsToContents();


 ui->control->setVisible(false);
      ui->affiche_mat->setSelectionBehavior(QAbstractItemView::SelectRows);




  }


  void acceuil::mailSent(QString status)
  {
      if(status == "Message sent")
          QMessageBox::warning( 0, tr( "E-mail" ), tr( "Le courrier a été envoyé!\n\n" ) );
  }

  acceuil::~acceuil()
  {
      delete ui;
  }

  void acceuil::on_tabWidget_currentChanged()
  {   musicClic->stop();
      musicClic->play();
  }

//******************************************************** Déconnexion **********************************************************************
  void acceuil::on_deconnexion_clicked()
  {
          musicClic->stop();
          musicClic->play();
          QString msg=ui->utilisateur_nom->text()+" Êtes-vous sûr de déconnecter ? ";
          int ret=QMessageBox::question(this,tr("Deconnexion"),msg,QMessageBox::Ok|QMessageBox::Cancel);

          switch (ret)
          {
          case QMessageBox::Ok:
          {c.fermerconnexion();this->close();}
              break;
          case QMessageBox::Cancel:
              break;
          }
  }
  //---------------------------------------------------------------------------------------------------\\
 // ******************************************** Gérer Employés ****************************************\\
//-------------------------------------------------------------------------------------------------------\\/



// ************************************ Ajouter Employé **************************

  void acceuil::on_ajouterEmploye_clicked()
  {
          musicClic->stop();
          musicClic->play();
          bool test=true;


          if(ui->lineEdit->text()=="" || ui->lineEdit->text().length()!=8)
          {test=false;ui->test1->setStyleSheet(colorFalse);}else ui->test1->setStyleSheet(colorTrue);
          if(verifALPHA(ui->lineEdit_2->text()))
          {test=false;ui->test2->setStyleSheet(colorFalse);}else ui->test2->setStyleSheet(colorTrue);
          if(verifALPHA(ui->lineEdit_3->text()))
          {test=false;ui->test3->setStyleSheet(colorFalse);}else ui->test3->setStyleSheet(colorTrue);
          if(verifALPHA(ui->lineEdit_4->text()))
          {test=false;ui->test4->setStyleSheet(colorFalse);}else ui->test4->setStyleSheet(colorTrue);
          if(ui->lineEdit_5->text()=="" || ui->lineEdit_5->text().length()<8)
          {test=false;ui->test5->setStyleSheet(colorFalse);}else ui->test5->setStyleSheet(colorTrue);
          if(verifEmail(ui->lineEdit_6->text()))
          {test=false;ui->test6->setStyleSheet(colorFalse);}
          else ui->test6->setStyleSheet(colorTrue);


          if(test)
             {QString nom=ui->lineEdit_3->text(),
                      CIN = ui->lineEdit->text(),
                      TEL= ui->lineEdit_5->text(),
                      prenom=ui->lineEdit_2->text(),
                      email=ui->lineEdit_6->text(),
                      adresse= ui->lineEdit_4->text(),
                      date_nais= ui->dateEdit->text(),
                      service=ui->comboBox->currentText();
                      employeurs e(CIN,nom,prenom,email,adresse,date_nais,service,TEL);
                      bool testajouter=e.ajouter();
                        if(testajouter)
                         {
                            ui->ajouter_succes->setText(" Ajouter Avec Succes ");
                            on_viderAjouterEmp_clicked();
                         }
               }

         if(!test)
         {QMessageBox::information(nullptr,QObject::tr("Aide"),QObject::tr("Tout les champs est obligatoire.\n"),QMessageBox::Ok);
          ui->ajouter_succes->setText("");
         }

  }                                                     // FIN ************ on_ajouterEmploye_clicked()



 // ************************************ Afficher Employés **************************

  void acceuil::on_AfficherEmp_clicked()
  {
          musicClic->stop();
          musicClic->play();
          if(ui->radioAfficherttemp->isChecked())
          {
              int tri=0;

              //****** 1 + 2
              if( ui->tri_emp->isChecked() && ui->tri_emp_2->isChecked())
                  tri=3;
              //****** 1 + 3
              if( ui->tri_emp->isChecked() && ui->tri_emp_3->isChecked())
                  tri=5;
              //****** 2 + 3
              if(ui->tri_emp_2->isChecked() && ui->tri_emp_3->isChecked())
                  tri=6;
              //****** 1 + 2 + 3
              if( ui->tri_emp->isChecked() && ui->tri_emp_3->isChecked() && ui->tri_emp_2->isChecked())
                  tri=7;
              if( ui->tri_emp->isChecked())
                  tri=1;
              if(ui->tri_emp_2->isChecked())
                  tri=2;
              if(ui->tri_emp_3->isChecked())
                  tri=4;
              ui->tabemployeurs->setModel(tmpemployeurs.afficherEmp(tri,"all"));
          }

  }

  // ************************************ Supprimer Employé **************************
  void acceuil::on_SupprimerEmp_clicked()
  {
      musicClic->stop();
      musicClic->play();

      QString cin=ui->supprimerEmp->text();
      bool test=tmpemployeurs.supprimerEmp(cin);
      if (test)
      {
          ui->tabemployeurs->setModel(tmpemployeurs.afficherEmp(0,""));//refrech
          QMessageBox::information(nullptr,QObject::tr("Supprimer d'un employé "),QObject::tr("avec Succès.\n"),QMessageBox::Ok);

      }
  }


 // ************************************ Modifier Employé **************************
  void acceuil::on_ModifierEmp_clicked()
  {

      bool test=false;
      QString CIN_recherche=ui->modifierEmp_CIN_chercher->text();
       if(CIN_recherche!= "")
           test=true;
       else
           QMessageBox::information(nullptr,QObject::tr("ALERT"),QObject::tr("Le CIN est obligatoire.\n8 caractères"),QMessageBox::Ok);

      if(test)
        {
                    QString nom=ui->modifierEmp_nom->text(),
                            CIN = ui->modifierEmp_CIN_chercher->text(),
                            TEL= ui->modifierEmp_tel->text(),
                            prenom=ui->modifierEmp_prenom->text(),
                            email=ui->modifierEmp_email->text(),
                            adresse= ui->modifierEmp_adresse->text(),
                            date_nais= ui->modifierDate_Nais->text(),
                            service=ui->comboBox_modifieremp->currentText();
                            date_nais=verifDate(date_nais);
                            employeurs e(CIN,nom,prenom,email,adresse,date_nais,service,TEL);
                            bool test_modifier=e.modifierEmp(CIN_recherche);

                            if(test_modifier)
                               {qDebug()<<"Modification Terminer";
                                ui->modifierEmp_CIN_chercher->clear();ui->comboBox_modifieremp->clear();
                                ui->modifierEmp_nom->clear();ui->modifierEmp_prenom->clear();
                                ui->modifierEmp_tel->clear();ui->modifierEmp_adresse->clear();
                                ui->modifierEmp_email->clear();ui->modifierDate_Nais->clear();
                                ui->tabemployeurs->setModel(tmpemployeurs.afficherEmp(0,""));
                                QMessageBox::information(nullptr,QObject::tr("Modifier d'un employé"),QObject::tr("Terminer avec Succès.\n"),QMessageBox::Ok);
                                }
          }




  }
  // ************************************ Vider Employé **************************

  void acceuil::on_viderAjouterEmp_clicked()
  {
          musicClic->stop();
          musicClic->play();
          ui->lineEdit->clear();ui->lineEdit_2->clear();ui->lineEdit_3->clear();
          ui->lineEdit_4->clear();ui->dateEdit->clear();ui->lineEdit_5->clear();ui->lineEdit_6->clear();

          ui->test1->setStyleSheet(Transparent);ui->test2->setStyleSheet(Transparent);ui->test3->setStyleSheet(Transparent);
          ui->test4->setStyleSheet(Transparent);ui->test5->setStyleSheet(Transparent);ui->test6->setStyleSheet(Transparent);
  }



  //---------------------------------------------------------------------------------------------------\\
 // ******************************************** Gérer Congés ******************************************\\/
//-------------------------------------------------------------------------------------------------------\\/
  void acceuil::on_ajouterConge_clicked()
  {

           musicClic->stop();
           musicClic->play();
           bool test=true;

           QString date1=ui->dateEdit_2->text(),date2=ui->dateEdit_3->text();

               date1.remove(7,1);date1.remove(4,1);
               qDebug()<<date1;
               date2.remove(7,1);date2.remove(4,1);
               qDebug()<<date2;
               int dateA= date1.toInt(),dateB=date2.toInt();


               if (dateA-dateB >0)
                  { test=false;
                   QMessageBox::information(nullptr,QObject::tr("Alert Date "),
                                            QObject::tr("Il faut utiliser une date correct ...\n"),QMessageBox::Ok);
                  }

                QString date_deb= ui->dateEdit_2->text(),date_fin=ui->dateEdit_3->text();
               if(dateA-dateB >= 0 || date_deb.length()!=10 || date_fin.length()!=10)
               {test=false;ui->test_4->setStyleSheet(colorFalse);ui->test_5->setStyleSheet(colorFalse);}
                else {ui->test_4->setStyleSheet(colorTrue);ui->test_5->setStyleSheet(colorTrue);}
               if(verifALPHA(ui->lineEdit_10->text()))
               {test=false;ui->test_2->setStyleSheet(colorFalse);}else ui->test_2->setStyleSheet(colorTrue);
               if(verifALPHA(ui->lineEdit_11->text()))
               {test=false;ui->test_3->setStyleSheet(colorFalse);}else ui->test_3->setStyleSheet(colorTrue);
               if(ui->lineEdit_9->text()=="" || ui->lineEdit_9->text().length()<8)
               {test=false;ui->test_1->setStyleSheet(colorFalse);}else ui->test_1->setStyleSheet(colorTrue);

                    if(test)
                    {
                       QString cin=ui->lineEdit_9->text(),
                       typeconge=ui->comboBox_2->currentText();
                       conges c(cin,typeconge,ui->dateEdit_2->text(),ui->dateEdit_3->text());
                       bool testajouter=c.ajouterConge();
                         if(testajouter)
                          {
                             ui->ajouter_succes->setText(" Ajouter Avec Succes ");
                             if(ui->notification->isChecked())
                                {
                                 QString name=ui->lineEdit_10->text().toUpper(),lastname=ui->lineEdit_11->text().toUpper();
                                 QString chaine;
                                 chaine=name+" "+lastname;
                                 chaine=chaine+"\n Votre congé de '"+ui->dateEdit_2->text();
                                 chaine=chaine+"' Au '"+ui->dateEdit_3->text();
                                 chaine=chaine+"'\nCette Message est automatique merci de ne réponds pas";
                                 qDebug() <<chaine;
                                 sendMail("Congé",chaine);
                                }
                             on_ViderAjouterConge_clicked();
                             QMessageBox::information(nullptr,QObject::tr("Ajouter Congé"),
                             QObject::tr("avec Succès.\n"),QMessageBox::Ok);
                          }else QMessageBox::critical(nullptr,QObject::tr("Congé non ajouté"),
                                                         QObject::tr("Errur\n"),QMessageBox::Ok);
                }
  }
           //************************ Fin on_pushButton_ajouterConge_clicked()


  // ************************************ Afficher Congé **************************
 void acceuil::on_AfficherCong_clicked()
  {
      musicClic->stop();
      musicClic->play();
      if(ui->radioAfficherttcong->isChecked())
      {bool tri=false;
          if( ui->tri_cong->isChecked() )
              tri=true;
          ui->tabConge->setModel(tmpconges.afficherConge(tri,"all"));
      }
  }
 // ************************************ Rechercher Congé **************************
  void acceuil::on_rechercherCong_clicked()
  {
      QString cin= ui->LinerechCong->text();
      ui->tabConge->setModel(tmpconges.afficherConge(false,cin));
  }


  // ************************************ Supprimer Congé **************************
  void acceuil::on_SupprimerCong_clicked()
  {
      musicClic->stop();
      musicClic->play();

      int id=ui->supprimerCong->text().toInt();
      bool test=tmpconges.supprimerConge(id);
      if (test)
      {
          ui->tabConge->setModel(tmpconges.afficherConge(false,"all"));//refrech
          QMessageBox::information(nullptr,QObject::tr("Supprimer d'un Congé "),QObject::tr("avec Succès.\n"),QMessageBox::Ok);

      }
  }

  // ************************************ Modifier Congé **************************

  void acceuil::on_ModifierCong_clicked()
  {
      bool test=false;
      if(ui->modifierCong_ID->text()!="" )
          test=true;
      else
          QMessageBox::information(nullptr,QObject::tr("Alert CIN"),QObject::tr("Le CIN est obligatoire.\n8 caractères.\n"),QMessageBox::Ok);

      if(test)
        {         QString ID= ui->modifierCong_ID->text(),
                  date_debut=ui->modifierDate_deb->text(),
                  date_fin  =ui->modifierDate_fin->text(),
                  type_conge=ui->comboBox_modifierconge->currentText();
                    date_debut=verifDate(date_debut);
                    date_fin=verifDate(date_fin);
                     qDebug()<<date_debut + " "+date_fin;
                    conges c(ID,type_conge,date_debut,date_fin);
                    bool test_modifier=c.modifierconge(ID);
                            if(test_modifier)
                               {
                                ui->tabConge->setModel(tmpconges.afficherConge(false,"all"));//refrech
                                qDebug()<<"Modification Terminer";
                                ui->modifierCong_ID->clear();ui->comboBox_modifierconge->clear();
                                ui->modifierDate_deb->clear();ui->modifierDate_fin->clear();
                                QMessageBox::information(nullptr,QObject::tr("Modifier d'un Congé"),QObject::tr("Terminer avec Succès.\n"),QMessageBox::Ok);
                                }
          }

  }





  // ************************************ Vider Congé **************************
  void acceuil::on_ViderAjouterConge_clicked()
  {

              //************* Vidé les champs AjoutéCoungé *************

      ui->lineEdit_10->clear();ui->lineEdit_11->clear();
      ui->lineEdit_9->clear();ui->dateEdit_2->clear();ui->dateEdit_3->clear();
      ui->test_1->setStyleSheet(Transparent);ui->test_2->setStyleSheet(Transparent);ui->test_3->setStyleSheet(Transparent);
      ui->test_4->setStyleSheet(Transparent);ui->test_5->setStyleSheet(Transparent);

          musicClic->stop();
          musicClic->play();
  }





  //---------------------------------------------------------------------------------------------------\\
 // ******************************************** Menu Button *******************************************\\
//-------------------------------------------------------------------------------------------------------\\/

void acceuil::on_afficher_employes_pressed()
{
    ui->afficher_employes->setStyleSheet("background:	rgb(255, 232, 103);border-radius:10px;");
    ui->afficher_conge->setStyleSheet("border-radius:15px;background :qlineargradient(spread:repeat, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(139, 140, 138, 255), stop:1 rgba(255, 255, 255, 255));color:white; color:white;");
    ui->ajouter_employe->setStyleSheet("border-radius:15px;background :qlineargradient(spread:repeat, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(139, 140, 138, 255), stop:1 rgba(255, 255, 255, 255));color:white; color:white;");
    ui->ajouter_conge->setStyleSheet("border-radius:15px;background :qlineargradient(spread:repeat, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(139, 140, 138, 255), stop:1 rgba(255, 255, 255, 255));color:white; color:white;");

    musicClic->stop();
    musicClic->play();
}

void acceuil::on_ajouter_employe_pressed()
{
    ui->ajouter_succes->setText("");
    ui->ajouter_employe->setStyleSheet("background:	rgb(255, 232, 103);border-radius:10px;");
    ui->ajouter_conge->setStyleSheet("border-radius:15px;background :qlineargradient(spread:repeat, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(139, 140, 138, 255), stop:1 rgba(255, 255, 255, 255));color:white; color:white;");
    ui->afficher_conge->setStyleSheet("border-radius:15px;background :qlineargradient(spread:repeat, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(139, 140, 138, 255), stop:1 rgba(255, 255, 255, 255));color:white; color:white;");
    ui->afficher_employes->setStyleSheet("border-radius:15px;background :qlineargradient(spread:repeat, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(139, 140, 138, 255), stop:1 rgba(255, 255, 255, 255));color:white; color:white;");

    musicClic->stop();
    musicClic->play();
}

void acceuil::on_ajouter_conge_pressed()
{
    ui->ajouter_conge->setStyleSheet("background:	rgb(255, 232, 103);border-radius:10px;");
    ui->afficher_conge->setStyleSheet("border-radius:15px;background :qlineargradient(spread:repeat, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(139, 140, 138, 255), stop:1 rgba(255, 255, 255, 255));color:white; color:white;");
    ui->afficher_employes->setStyleSheet("border-radius:15px;background :qlineargradient(spread:repeat, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(139, 140, 138, 255), stop:1 rgba(255, 255, 255, 255));color:white; color:white;");
    ui->ajouter_employe->setStyleSheet("border-radius:15px;background :qlineargradient(spread:repeat, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(139, 140, 138, 255), stop:1 rgba(255, 255, 255, 255));color:white; color:white;");
    musicClic->stop();
    musicClic->play();
}

void acceuil::on_afficher_conge_pressed()
{
   ui->afficher_conge->setStyleSheet("background:	rgb(255, 232, 103);border-radius:10px;");
   ui->ajouter_employe->setStyleSheet("border-radius:15px;background :qlineargradient(spread:repeat, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(139, 140, 138, 255), stop:1 rgba(255, 255, 255, 255));color:white; color:white;");
   ui->ajouter_conge->setStyleSheet("border-radius:15px;background :qlineargradient(spread:repeat, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(139, 140, 138, 255), stop:1 rgba(255, 255, 255, 255));color:white; color:white;");
   ui->afficher_employes->setStyleSheet("border-radius:15px;background :qlineargradient(spread:repeat, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(139, 140, 138, 255), stop:1 rgba(255, 255, 255, 255));color:white; color:white;");
   musicClic->stop();
   musicClic->play();
}




void acceuil::Get_utilisateur()
{
    QSqlQuery qry;
    qry.prepare("SELECT prenom,nom FROM employeurs where CIN=?");
    qry.addBindValue(identifiant);

    if(qry.exec())
        if(qry.next())
            {

            QString prenom = QVariant(qry.value(0)).toString();
            qDebug()<<prenom;

                ui->utilisateur_nom->setText(prenom);

            }
}





bool acceuil::verifEmail(QString chaine)
{
        if(chaine=="")
            return true;
        if( chaine[0]=="@" || chaine[0]=="." || chaine[chaine.length()-1]=="@" || chaine[chaine.length()-1]=="." )
            return true;
        else
        {   int testALT=0,testpoint=0;
            for(int i=0;i<chaine.length();i++)
            {
                if( (chaine[i]<"a"|| chaine[i]>"z") && ( chaine[i]<"A" || chaine[i]>"Z") && (chaine[i]<"0"|| chaine[i]>"9")
                     && chaine[i]!="." && chaine[i]!="_" && chaine[i]!="@")
                    return true;
                if (chaine[i]=="@" && testALT==1)
                    return true;
                if(testpoint==1 && chaine[i]==".")
                    return true;
                if(chaine[i]=="@")
                    testALT=1;
                if(chaine[i]=="@" && (chaine[i+1]=="." || chaine[i-1]=="." ) )
                    return true;
                if(testALT==1 && chaine[i]=="." )
                    testpoint=1;
                if(chaine[i]=="." && chaine[i+1]==".")
                    return true;
            }
            if(testALT==0 || testpoint==0)
                return true;
        }
 return false;
}




void acceuil::on_tabemployeurs_activated(const QModelIndex &index)
{

    if(ui->tabemployeurs->DoubleClicked && (ui->tabemployeurs->model()->data(index).toString()[0]>'0' &&  ui->tabemployeurs->model()->data(index).toString()[0]<'9') )
    {   QString val=ui->tabemployeurs->model()->data(index).toString();

        if (ui->radiosuppemploye->isChecked())
            ui->supprimerEmp->setText(val);
        if (ui->radiomodifemploye->isChecked())
            ui->modifierEmp_CIN_chercher->setText(val);
    }


}
void acceuil::on_Linerechemp_textChanged(const QString &arg1)
{
    ui->tabemployeurs->setModel(tmpemployeurs.afficherEmp(10,arg1));

}









void acceuil::on_pushButton_clicked() // boutton ajouter materiaux
{
    QMediaPlayer *musicLogin= new QMediaPlayer;
   musicLogin->setMedia(QUrl("C:/Users/oussa/Desktop/bouttonsound.mp3"));
       musicLogin->play();
     ui->stackedWidget->setCurrentIndex(1);



}

void acceuil::on_pushButton_2_clicked() // boutton afficher materiaux

{ui->stackedWidget->setCurrentIndex(2);
    QMediaPlayer *musicLogin= new QMediaPlayer;
   musicLogin->setMedia(QUrl("C:/Users/oussa/Desktop/bouttonsound.mp3"));
       musicLogin->play();
ui->affiche_mat->setModel(Etmp.afficher());


}

void acceuil::on_modifier_2_clicked() // boutton modifier
{
    ui->stackedWidget->setCurrentIndex(3);
}

void acceuil::on_pushButton_10_clicked() // boutton retour du widget modifier
{
    ui->stackedWidget->setCurrentIndex(2);
}


void acceuil::on_supprimer_2_clicked() // boutton supprimer materiel
{
    QString idd=ui->lineEdit_21->text();
    materiaux *Etmp=new materiaux();
    if (idd=="")
    { QMessageBox::information(this,"non existe","id n'existe pas");}
    else
    {
        QString str = " Vous voulez vraiment supprimer le materiel \n ayant la reference:"+ ui->lineEdit_21->text();
        int ret = QMessageBox::question(this, tr("Suppression"),str,QMessageBox::Yes|QMessageBox::Cancel);
        switch (ret) {
        case QMessageBox::Yes:

            if (Etmp->supprimer(idd))
            {
                ui->affiche_mat->setModel(Etmp->afficher());
            }
            break;


        }
    }
     //ui->stackedWidget->setCurrentIndex(4);
}

void acceuil::on_pushButton_15_clicked() // boutton retour du widget supprimer
{
    ui->stackedWidget->setCurrentIndex(2);
}

void acceuil::on_quitter_2_clicked() // retour du menu afficher
{
    ui->stackedWidget->setCurrentIndex(0);
}

void acceuil::on_pushButton_3_clicked() // Afficher les statistiques


{


    int x= ui->calcul->text().toInt();
    int y=ui->calcul2->text().toInt();
    QPieSeries *series = new QPieSeries();
       series->setHoleSize(0.40);
            series->append("Quantite global %",x);
       QPieSlice *slice = series->append("Quantite   restante %", y);
       slice->setExploded();
       slice->setLabelVisible();
        QChartView *chartView = new QChartView();
       chartView->setRenderHint(QPainter::Antialiasing);
       chartView->chart()->setTitle("Statistique Materiaux");
       chartView->chart()->addSeries(series);
       chartView->chart()->legend()->setAlignment(Qt::AlignBottom);
       chartView->chart()->setTheme(QChart::ChartThemeDark);
       chartView->chart()->legend()->setFont(QFont("Arial", 7));

chartView->show();

 chartView->resize(800,600);



}



void acceuil::on_pushButton_16_clicked()// boutton ajouter
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
                      ui->affiche_mat->setModel(Etmp.afficher());

                       QMessageBox::information(nullptr,QObject::tr("OK"),
                                                QObject::tr("Ajouter Effectuer\n"
                                                            "click cancel to exit"),QMessageBox::Cancel);
                       }
                       else
                           QMessageBox::critical(nullptr,QObject::tr("Nor OK"),
                                                 QObject::tr("Ajouter non Effectuer"),QMessageBox::Cancel);




}


void acceuil::on_pushButton_17_clicked() // boutton undo (ajouter)
{
    ui->lineEdit_15->setText("");
    ui->lineEdit_16->setText("");
    ui->lineEdit_17->setText("");
    ui->lineEdit_18->setText("");
    ui->lineEdit_19->setText("");

}


void acceuil::on_pushButton_18_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void acceuil::on_pushButton_12_clicked() //boutton modifier (dans le widget modifier)
{
    QString ref_materiel=ui->lineEdit_31->text();
    QString nom_materiel=ui->lineEdit_14->text();
   int quantite =ui->lineEdit_12->text().toInt();
          int  quantite_res=ui->lineEdit_13->text().toInt();
           double prix=ui->lineEdit_20->text().toDouble();
           QDate date_achat = ui->date_modifier->date();
           materiaux m(ref_materiel,nom_materiel,prix,quantite,quantite_res,date_achat);
           bool test=m.modifier(ref_materiel);
           if (test){
              ui->affiche_mat->setModel(Etmp.afficher());

               QMessageBox::information(nullptr,QObject::tr("OK"),
                                        QObject::tr("modifier Effectuer\n"
                                                    "click cancel to exit"),QMessageBox::Cancel);
               }
               else
                   QMessageBox::critical(nullptr,QObject::tr("Nor OK"),
                                         QObject::tr("modifier non Effectuer"),QMessageBox::Cancel);




}



void acceuil::on_pushButton_11_clicked() // boutton undo (modifier)
{
    ui->lineEdit_12->setText("");
    ui->lineEdit_14->setText("");
    ui->lineEdit_20->setText("");
    ui->lineEdit_13->setText("");

}


void acceuil::on_pushButton_13_clicked() // boutton supprimer(widget supprimer)
{
   QString ref_materiel= ui->lineEdit_21->text();
   materiaux m;

         bool test=m.supprimer(ref_materiel);
         if(test){
ui->affiche_mat->setModel(Etmp.afficher());
             QMessageBox::information(nullptr,QObject::tr("OK"),
                                      QObject::tr("supprimer Effectuer\n"
                                                  "click cancel to exit"),QMessageBox::Cancel);
             }
             else
                 QMessageBox::critical(nullptr,QObject::tr("Not OK"),

                                       QObject::tr("supprimer non Effectuer"),QMessageBox::Cancel);
         }






void acceuil::on_pushButton_14_clicked() //boutton undo supprimer
{

ui->lineEdit_21->setText("");
}

void acceuil::on_pushButton_19_clicked() //boutton ajouter
{
     ui->stackedWidget_2->setCurrentIndex(1);



}

void acceuil::on_pushButton_21_clicked() // retour (ajouter fournisseur)
{
    QMediaPlayer *musicLogin= new QMediaPlayer;
   musicLogin->setMedia(QUrl("C:/Users/oussa/Desktop/bouttonsound.mp3"));
       musicLogin->play();
    ui->stackedWidget_2->setCurrentIndex(0);

}

void acceuil::on_pushButton_20_clicked() //boutton afficher fournisseur
{ QMediaPlayer *musicLogin= new QMediaPlayer;
    musicLogin->setMedia(QUrl("C:/Users/oussa/Desktop/bouttonsound.mp3"));
        musicLogin->play();
        ui->tableView_2->setModel(Etmp1.afficher_fournisseur());
     ui->stackedWidget_2->setCurrentIndex(2);
}

void acceuil::on_quitter_3_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);//retour aprés afficher fournisseur
}

void acceuil::on_modifier_3_clicked() // boutton modifier fournisseur
{
    ui->stackedWidget_2->setCurrentIndex(3);
}

void acceuil::on_pushButton_25_clicked() //boutton retour (widget modifier fournisseur)
{
    ui->stackedWidget_2->setCurrentIndex(2);
}


void acceuil::on_supprimer_3_clicked() // boutton supprimer (affichage fournisseur)
{

    int idd=ui->lineEdit_30->text().toInt();
    fournisseurs *f=new fournisseurs();
    if (idd==0)
    { QMessageBox::information(this,"non existe","id n'existe pas");}
    else
    {
        QString str = " Vous voulez vraiment supprimer le fournisseur\n ayant l' ID:"+ ui->lineEdit_30->text();
        int ret = QMessageBox::question(this, tr("Suppression"),str,QMessageBox::Yes|QMessageBox::Cancel);
        switch (ret) {
        case QMessageBox::Yes:

             f->supprimer_fournisseur(idd);

                ui->tableView_2->setModel(f->afficher_fournisseur());

            break;


        }
    }
}


void acceuil::on_pushButton_28_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(2);
}






void acceuil::on_retour_clicked()
{
       ui->stackedWidget->setCurrentIndex(0);
}






void acceuil::on_pushButton_22_clicked() // ajouter  fournisseur dans le widget ajouter
{

/*
            Smtp* smtp = new Smtp("jemaaoussama64@gmail.com","Sousou22658131","smtp.gmail.com", 465);
            connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
            smtp->sendMail("jemaaoussama64@gmail.com", "oussama.jmaa@esprit.tn" , "Test","msg");
*/










    QString reference_materiel=ui->lineEdit_25->text();
   QString mail_fournisseur=ui->lineEdit_23->text();
           QString nom_fournisseur=ui->lineEdit_26 ->text();
          double solde=ui->lineEdit_28->text().toDouble();
           int id_fournisseur=ui->lineEdit_22->text().toInt();
            int tel_founrisseur=ui->lineEdit_24->text().toInt();


                   fournisseurs f( reference_materiel, id_fournisseur,mail_fournisseur, tel_founrisseur, solde, nom_fournisseur);
                   bool test2=f.ajouter_fournisseur();
                   if (test2){
                      ui->tableView_2->setModel(Etmp1.afficher_fournisseur());

                       QMessageBox::information(nullptr,QObject::tr("OK"),
                                                QObject::tr("Ajouter Effectuer\n"
                                                            "click cancel to exit"),QMessageBox::Cancel);
                       }
                       else
                           QMessageBox::critical(nullptr,QObject::tr("Nor OK"),
                                                 QObject::tr("Ajouter non Effectuer"),QMessageBox::Cancel);

}

void acceuil::on_pushButton_29_clicked() // supprimer dans le widget supprimer
{int id_fournisseur = ui->lineEdit_30->text().toInt();

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

void acceuil::on_pushButton_26_clicked() // modifier fournisseur (modifier)
{
   int id_fournisseur=ui->lineEdit_8->text().toInt();
   QString ref_mat=ui->lineEdit_7->text();
   QString mail=ui->lineEdit_29->text();
   int tel =ui->lineEdit_27->text().toInt();
   int solde =ui->lineEdit_32->text().toInt();
   QString nom = ui->lineEdit_33->text();

fournisseurs f(ref_mat,id_fournisseur,mail,tel,solde,nom);
bool test = f.modifier_fournisseur(id_fournisseur);

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

void acceuil::on_supprimer_4_clicked() // trier materiaux
{

     ui->affiche_mat->setModel(Etmp.trier());
}

void acceuil::on_trier_clicked() // trier fournisseur
{

 ui->tableView_2->setModel(Etmp1.trier1());
}




void acceuil::on_tableView_2_activated(const QModelIndex &index)
{



     QString id = ui->tableView_2->model()->data(index).toString();
     QSqlQuery query;
     query.prepare(" select * from fournisseur   where id_fournisseur = '"+id+"'");

   //  ui->tableView_2->setStyleSheet("QTableView { selection-color: black; selection-background-color: green; }");
     if(query.exec())
     {
         while (query.next())
         {
ui->lineEdit_27->setText(query.value(3).toString());
ui->lineEdit_7->setText(query.value(0).toString());
ui->lineEdit_8->setText(query.value(1).toString());
ui->lineEdit_29->setText(query.value(2).toString());
ui->lineEdit_33->setText(query.value(5).toString());
ui->lineEdit_32->setText(query.value(4).toString());
ui->lineEdit_30->setText(query.value(1).toString());

         }
}
}

void acceuil::on_affiche_mat_activated()
{

const QModelIndex index;

    QSqlQueryModel * model = new QSqlQueryModel();

              model->setQuery("select * from materiaux");

             ui->affiche_mat->setModel(model);
             int result = 0;
               const int column = 2;

               for (int row = 0; row < model->rowCount(); ++row) {
                   result += model->data(model->index(row, column)).toInt();
               }
               ui->calcul->setText( QString::number(result) ); // show sum in label
int result1=0;
               const int column2 = 4;

               for (int row = 0; row < model->rowCount(); ++row) {
                   result1 += model->data(model->index(row, column2)).toInt();
               }
               ui->calcul2->setText( QString::number(result1) ); // show sum in label


    QString ref_materiel = ui->affiche_mat->model()->data(index).toString();
    QSqlQuery query;
    query.prepare(" select * from materiaux where ref_materiel = '"+ref_materiel+"'");
    if(query.exec())
    {
        while (query.next())
        {
ui->lineEdit_31->setText(query.value(0).toString());
         ui->lineEdit_14->setText(query.value(1).toString());
            ui->lineEdit_12->setText(query.value(2).toString());
            ui->lineEdit_20->setText(query.value(3).toString());
            ui->lineEdit_13->setText(query.value(4).toString());
            ui->date_modifier->setDate(query.value(5).toDate());


        }
}

}



void acceuil::on_rechercher_ref_cursorPositionChanged()
{
    materiaux m;
    ui->affiche_mat->setModel(m.rechercher(ui->rechercher_ref->text()));
    m.afficher();
}

void acceuil::on_rechercher_id_cursorPositionChanged()
{
    fournisseurs f ;
    ui->tableView_2->setModel(f.rechercher1(ui->rechercher_id->text()));
            f.afficher_fournisseur();
}



void acceuil::on_pushButton_23_clicked() // undo fournisseur (ajouter  )
{
    ui->lineEdit_28->setText("");
    ui->lineEdit_25->setText("");
    ui->lineEdit_22->setText("");
    ui->lineEdit_23->setText("");
    ui->lineEdit_24->setText("");

     ui->lineEdit_26->setText("");

}

void acceuil::on_pushButton_27_clicked() // undo fournisseur (modifier)
{

    ui->lineEdit_27->setText("");
}

void acceuil::on_pushButton_30_clicked() // undo fournisseur (supprimer)
{
    ui->lineEdit_30->setText("");
}

void acceuil::on_pushButton_5_clicked() // dark theme
{
    ui->tabWidget->setStyleSheet("background-color:black;color:white");
    ui->frame_2->setStyleSheet("background-color:qlineargradient(spread:pad, x1:0.467, y1:0, x2:0.482, y2:1, stop:0 rgb(0,0,0), stop:1 rgba(0,255,0)) ");
    ui->frame_3->setStyleSheet("background-color:qlineargradient(spread:pad, x1:0.467, y1:0, x2:0.482, y2:1, stop:0 rgb(0,0,0), stop:1 rgba(34,139,34)) ");
    ui->frame_4->setStyleSheet("background-color:qlineargradient(spread:pad, x1:0.467, y1:0, x2:0.482, y2:1, stop:0 rgb(0,0,0), stop:1 rgba(34,139,34)) ");

ui->pushButton_5->setVisible(false);
ui->pushButton_6->setVisible(true);
}

void acceuil::on_pushButton_6_clicked() // dark theme
{

    ui->tabWidget->setStyleSheet("background-color:white;color:black");
    ui->frame_2->setStyleSheet("background-color:qlineargradient(spread:pad, x1:0.467, y1:0, x2:0.482, y2:1, stop:0 rgb(0,0,0), stop:1 rgba(0,255,0)) ");
    ui->frame_3->setStyleSheet("background-color:qlineargradient(spread:pad, x1:0.467, y1:0, x2:0.482, y2:1, stop:0 rgb(0,0,0), stop:1 rgba(34,139,34)) ");
    ui->frame_4->setStyleSheet("background-color:qlineargradient(spread:pad, x1:0.467, y1:0, x2:0.482, y2:1, stop:0 rgb(0,0,0), stop:1 rgba(34,139,34))");

 ui->pushButton_5->setVisible(true);
 ui->pushButton_6->setVisible(false);
}


void acceuil::on_lineEdit_26_textChanged() // control de saisie pour nom fournisseur
{
    if(control_saisie_chaine(ui->lineEdit_26->text()))


ui->lineEdit_26->setStyleSheet("background-color: rgb(255, 160, 157)");

else ui->lineEdit_26->setStyleSheet("background-color: rgb(0, 0, 0,0)");
}

void acceuil::on_lineEdit_27_textChanged()
{
    if(control_saisie_chaine(ui->lineEdit_27->text()))


ui->lineEdit_27->setStyleSheet("background-color: rgb(255, 160, 157)");

else ui->lineEdit_27->setStyleSheet("background-color: rgb(0, 0, 0,0)");

}

void acceuil::on_lineEdit_16_textChanged()
{if(control_saisie_chaine(ui->lineEdit_16->text()))
{
        ui->lineEdit_16->setStyleSheet("background-color: rgb(255, 160, 157)");

    ui->control->setVisible(true);
}
        else {ui->lineEdit_16->setStyleSheet("background-color: rgb(0, 0, 0,0)");
ui->control->setVisible(false);

}
}


void acceuil::on_lineEdit_14_textChanged()
{
    if(control_saisie_chaine(ui->lineEdit_14->text()))


            ui->lineEdit_14->setStyleSheet("background-color: rgb(255, 160, 157)");

            else ui->lineEdit_14->setStyleSheet("background-color: rgb(0, 0, 0,0)");
}









void acceuil::on_affiche_mat_activated(const QModelIndex &index)
{
    QString ref_materiel = ui->affiche_mat->model()->data(index).toString();
    QSqlQuery query;
    query.prepare(" select * from materiaux where ref_materiel = '"+ref_materiel+"'");
    if(query.exec())
    {
        while (query.next())
        {
ui->lineEdit_31->setText(query.value(0).toString());
         ui->lineEdit_14->setText(query.value(1).toString());
            ui->lineEdit_12->setText(query.value(2).toString());
            ui->lineEdit_20->setText(query.value(3).toString());
            ui->lineEdit_13->setText(query.value(4).toString());
            ui->date_modifier->setDate(query.value(5).toDate());
            ui->lineEdit_21->setText(query.value(0).toString());


        }
}
}

void acceuil::on_pushButton_31_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(2);
}



void acceuil::on_pushButton_4_clicked()
{
    QPrinter *printer = new QPrinter(QPrinter::HighResolution);
                   printer->setOutputFormat(QPrinter::NativeFormat);
                   printer->setPageSize(QPrinter::A4);
                   printer->setOrientation(QPrinter::Portrait);
                   printer->setFullPage(true);


               QPrintDialog *printDialog = new QPrintDialog(printer,this);
               printDialog->setWindowTitle("Impression PDF");
               if(printDialog->exec())
               {
                  QPainter painter;
                  if(painter.begin(printer))
                  {
                      double xscale = double(ui->stackedWidget->width()  );
                      double yscale = double(ui->stackedWidget->height() );
                      painter.scale(xscale, yscale);
                      ui->stackedWidget->render(&painter);
                      painter.end();
                  }
                  else
                  {
                      qWarning("failed to open file");
                     QMessageBox::warning(nullptr,QObject::tr("PDF echoue"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);
                  }
               }
}
