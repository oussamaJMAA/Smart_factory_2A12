#include "acceuil.h"
#include "ui_acceuil.h"

#define colorFalse "color:red;"
#define colorTrue "color:rgb(28,255,33);"
#define Transparent "color:transparent;"

acceuil::acceuil(QWidget *parent) : QDialog(parent), ui(new Ui::acceuil)
{

    musicClic->setMedia(QUrl("C:/Users/Nasreddine/Documents/FuseSmart/clic.mp3"));
    ui->setupUi(this);


    musicClic->setVolume(10);

    QPixmap addemp("C:/Users/Nasreddine/Documents/FuseSmart/AjouterEmployé.png"),
            addcng("C:/Users/Nasreddine/Documents/FuseSmart/Ajoutercongé.png");
    ui->AjouterEmploye->setPixmap(addemp);ui->AjouterConge->setPixmap(addcng);
    ui->lineEdit->setValidator(new QIntValidator(0,99999999,this));
    ui->lineEdit_5->setValidator(new QIntValidator(0,99999999,this));
    ui->LinerechCong->setValidator(new QIntValidator(0,99999999,this));
    ui->modifierCong_ID->setValidator(new QIntValidator(0,999999999,this));
    ui->supprimerCong->setValidator(new QIntValidator(0,999999999,this));
    ui->supprimerEmp->setValidator(new QIntValidator(0,99999999,this));
    ui->modifierEmp_CIN_chercher->setValidator(new QIntValidator(0,99999999,this));
    ui->lineEdit_9->setValidator(new QIntValidator(0,99999999,this));





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
          this->close();




        c.fermerconnexion();

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
                         {ui->ajouter_succes->setText(" Ajouter Avec Succes ");
                            ui->test1->setStyleSheet(Transparent);ui->test2->setStyleSheet(Transparent);ui->test3->setStyleSheet(Transparent);
                            ui->test4->setStyleSheet(Transparent);ui->test5->setStyleSheet(Transparent);ui->test6->setStyleSheet(Transparent);
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
              bool tri=false;
              if( ui->tri_emp->isChecked() )
                  tri=true;
              ui->tabemployeurs->setModel(tmpemployeurs.afficherEmp(tri,"all"));
          }

  }



  // ************************************ Rechercher Employé **************************
  void acceuil::on_rechercherEmp_clicked()
  {
      QString cin= ui->Linerechemp->text();
      ui->tabemployeurs->setModel(tmpemployeurs.afficherEmp(false,cin));
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
          ui->tabemployeurs->setModel(tmpemployeurs.afficherEmp(false,"all"));//refrech
          QMessageBox::information(nullptr,QObject::tr("Supprimer d'un employé "),QObject::tr("avec Succès.\n"),QMessageBox::Ok);

      }
  }






 // ************************************ Modifier Employé **************************
  void acceuil::on_ModifierEmp_clicked()
  {

      bool test=false;


      QString CIN_recherche=ui->modifierEmp_CIN_chercher->text();
       if(CIN_recherche!= "" && CIN_recherche.length()==8)
           test=true;
       else

           QMessageBox::information(nullptr,QObject::tr("ALERT"),QObject::tr("Le CIN est obligatoire.\n8 caractères"),QMessageBox::Ok);

      if(test)
        {int CIN = ui->modifierEmp_CIN_chercher->text().toInt(),TEL= ui->modifierEmp_tel->text().toInt();
                    QString nom=ui->modifierEmp_nom->text(),
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
                                ui->modifierEmp_CIN_chercher->clear();
                                ui->modifierEmp_nom->clear();ui->modifierEmp_prenom->clear();
                                ui->modifierEmp_tel->clear();ui->modifierEmp_adresse->clear();
                                ui->modifierEmp_email->clear();ui->modifierDate_Nais->clear();
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
                       conges c(cin,typeconge,date_deb,date_fin);
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
                             //Vidé les champs AjoutéCoungé
                             ui->lineEdit_10->clear();ui->lineEdit_11->clear();
                             ui->lineEdit_9->clear(); ui->dateEdit_2->clear(); ui->dateEdit_3->clear();
                             QMessageBox::information(nullptr,QObject::tr("Ajouter Congé"),
                                                      QObject::tr("avec Succès.\n"),QMessageBox::Ok);

                             ui->test_1->setStyleSheet(Transparent);ui->test_2->setStyleSheet(Transparent);ui->test_3->setStyleSheet(Transparent);
                             ui->test_4->setStyleSheet(Transparent);ui->test_5->setStyleSheet(Transparent);
                          }

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
                                qDebug()<<"Modification Terminer";
                                ui->modifierCong_ID->clear();
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
