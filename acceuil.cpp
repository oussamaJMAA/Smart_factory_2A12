#include "acceuil.h"
#include "ui_acceuil.h"


acceuil::acceuil(QWidget *parent) : QDialog(parent), ui(new Ui::acceuil)
{

    musicClic->setMedia(QUrl("C:/Users/Nasreddine/Documents/FuseSmart/clic.mp3"));
    ui->setupUi(this);


    musicClic->setVolume(10);
    QPixmap addemp("C:/Users/Nasreddine/Documents/FuseSmart/AjouterEmployé.png"),
            addcng("C:/Users/Nasreddine/Documents/FuseSmart/Ajoutercongé.png");
    ui->AjouterEmploye->setPixmap(addemp);ui->AjouterConge->setPixmap(addcng);


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
  {     connection c  ;
          musicClic->stop();
          musicClic->play();




        c.fermerconnexion();

  }


  //---------------------------------------------------------------------------------------------------\\
 // ******************************************** Gérer Employés ****************************************\\
//-------------------------------------------------------------------------------------------------------\\/

  void acceuil::on_ajouterEmploye_clicked()
  {
          musicClic->stop();
          musicClic->play();
          bool test=true;

          if(ui->lineEdit->text()=="" ||ui->lineEdit_2->text()=="" ||
                  ui->lineEdit_3->text()=="" ||ui->lineEdit_4->text()==""
                  || ui->lineEdit_5->text()=="" || ui->lineEdit_6->text()=="")
             {
              test=false;
             }


          if(test)
             { int CIN = ui->lineEdit->text().toInt(),TEL= ui->lineEdit_5->text().toInt();
              QString nom=ui->lineEdit_3->text(),
                      prenom=ui->lineEdit_2->text(),
                      email=ui->lineEdit_6->text(),
                      adresse= ui->lineEdit_4->text(),
                      date_nais= ui->dateEdit->text(),
                      service=ui->comboBox->currentText();
                      employeurs e(CIN,nom,prenom,email,adresse,date_nais,service,TEL);
                      bool testajouter=e.ajouter();
                        if(testajouter)
                         ui->ajouter_succes->setText(" Ajouter Avec Succes ");

                }
          //**** vider les champs****
         if(test){ui->lineEdit->clear();ui->lineEdit_2->clear();ui->lineEdit_3->clear();
          ui->lineEdit_4->clear();ui->dateEdit->clear();ui->lineEdit_5->clear();ui->lineEdit_6->clear();}


         if(!test)
         {QMessageBox::information(nullptr,QObject::tr("Aide"),QObject::tr("Tout les champs est obligatoire.\nClick OK To EXIT ."),QMessageBox::Ok);
          ui->ajouter_succes->setText("");
         }

  }                                                     // FIN ************ on_ajouterEmploye_clicked()




  void acceuil::on_AfficherEmp_clicked()
  {
          musicClic->stop();
          musicClic->play();
          if(ui->radioAfficherttemp->isChecked())
          {
              bool tri=false;
              if( ui->tri_emp->isChecked() )
                  tri=true;
              ui->tabemployeurs->setModel(tmpemployeurs.afficherEmp(tri,"all"));
          }

  }
  void acceuil::on_rechercherEmp_clicked()
  {
      QString cin= ui->Linerechemp->text();
      ui->tabemployeurs->setModel(tmpemployeurs.afficherEmp(false,cin));
  }



  void acceuil::on_SupprimerEmp_clicked()
  {
      musicClic->stop();
      musicClic->play();

      QString cin=ui->supprimerEmp->text();
      bool test=tmpemployeurs.supprimerEmp(cin);
      if (test)
      {
          ui->tabemployeurs->setModel(tmpemployeurs.afficherEmp(false,"all"));//refrech
          QMessageBox::information(nullptr,QObject::tr("Supprimer d'un employé "),QObject::tr("avec Succès.\n"),QMessageBox::Ok);

      }
  }




  void acceuil::on_viderAjouterEmp_clicked()
  {
          musicClic->stop();
          musicClic->play();
          ui->lineEdit->clear();ui->lineEdit_2->clear();ui->lineEdit_3->clear();
          ui->lineEdit_4->clear();ui->dateEdit->clear();ui->lineEdit_5->clear();ui->lineEdit_6->clear();
  }



  //---------------------------------------------------------------------------------------------------\\
 // ******************************************** Gérer Congés ******************************************\\/
//-------------------------------------------------------------------------------------------------------\\/
  void acceuil::on_ajouterConge_clicked()
  {

           musicClic->stop();
           musicClic->play();
           bool test=true;

           if(ui->lineEdit_9->text()=="" )
              {
               test=false;
              }


           if(test)
              {
                       QString cin=ui->lineEdit_9->text(),
                       date_deb= ui->dateEdit_2->text(),date_fin=ui->dateEdit_3->text(),
                       typeconge=ui->comboBox_2->currentText();
                       conges c(cin,typeconge,date_deb,date_fin);
                       bool testajouter=c.ajouterConge();
                         if(testajouter)
                          {
                             ui->ajouter_succes->setText(" Ajouter Avec Succes ");
                             if(ui->notification->isChecked())
                                {
                                 QString chaine;
                                 chaine=ui->lineEdit_9->text()+" "+ui->lineEdit_11->text();
                                 chaine=chaine+"\n Votre congé de '"+ui->dateEdit_2->text();
                                 chaine=chaine+"' Au '"+ui->dateEdit_3->text();
                                 chaine=chaine+"'\nCette Message est automatique merci de ne réponds pas";
                                 qDebug() <<chaine;
                                 sendMail("Congé",chaine);
                                }
                             //Vidé les champs AjoutéCoungé
                             ui->lineEdit_10->clear();ui->lineEdit_11->clear();
                             ui->lineEdit_9->clear(); ui->dateEdit_2->clear(); ui->dateEdit_3->clear();
                             QMessageBox::information(nullptr,QObject::tr("Ajouter Congé"),
                                                      QObject::tr("avec Succès.\nClick OK To EXIT ."),QMessageBox::Ok);
                          }

                }





  }

           //************************ Fin on_pushButton_ajouterConge_clicked()


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

  void acceuil::on_rechercherCong_clicked()
  {
      QString cin= ui->LinerechCong->text();
      ui->tabConge->setModel(tmpconges.afficherConge(false,cin));
  }



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









  void acceuil::on_ViderAjouterConge_clicked()
  {

              //************* Vidé les champs AjoutéCoungé *************

      ui->lineEdit_10->clear();ui->lineEdit_11->clear();
      ui->lineEdit_9->clear();ui->dateEdit_2->clear();ui->dateEdit_3->clear();

          musicClic->stop();
          musicClic->play();
  }





  //---------------------------------------------------------------------------------------------------\\
 // ******************************************** Menu Button *******************************************\\
//-------------------------------------------------------------------------------------------------------\\/
  void acceuil::on_ajouter_conge_clicked()
  {
      musicClic->stop();
      musicClic->play();
  }

  void acceuil::on_ajouter_employe_clicked()
  {   ui->ajouter_succes->setText("");

      musicClic->stop();
      musicClic->play();
  }

  void acceuil::on_afficher_conge_clicked()
  {
      musicClic->stop();
      musicClic->play();
  }

  void acceuil::on_afficher_employes_clicked()
  {
      musicClic->stop();
      musicClic->play();
  }



















