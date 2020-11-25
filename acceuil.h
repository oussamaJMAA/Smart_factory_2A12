#ifndef ACCEUIL_H
#define ACCEUIL_H

#include <QMediaPlayer>
#include <QDialog>
#include <QMainWindow>
#include <QApplication>
#include "mainwindow.h"
#include <QMessageBox>
#include "connection.h"
#include <QPixmap>
#include "smtp.h"
#include "employeurs.h"
#include "conges.h"
#include <QApplication>
#include <QGraphicsDropShadowEffect>
#include <QDateTime>
#include <QModelIndex>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

namespace Ui {
class acceuil;
}

class acceuil : public QDialog
{
    Q_OBJECT

public:
    explicit acceuil(QWidget *parent = nullptr);
    void Get_utilisateur();
    void Set_Identifiant(QString id){
        identifiant=id;
    }
    ~acceuil();
    bool verifEmail(QString);
    bool verifALPHA(QString chaine)
    {
        chaine=chaine.toUpper();
        if(chaine=="")
            return true;
        else
        for(int i=0;i<chaine.length();i++)
            if((chaine[i]<'A' || chaine[i]>'Z') && chaine[i]!=" " )
                return true;

        return false;
    }
    QString verifDate(QString date)
    {
        if(date.length()==10)
                for(int i=0;i<10;i++)
                    if(date[i]==" ")
                        {  date="" ;break; }
        else if(date=="1950/12/24"|| date.length()!=10)
                    date="";
        return date;
    }

private slots:
    void sendMail(QString subject , QString msg){
            Smtp* smtp = new Smtp("nasreddine.elmadhkour@esprit.tn","191JFT2263","smtp.gmail.com", 465);
            connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
            smtp->sendMail("nasreddine.elmadhkour@esprit.tn", "nasreddine1234@gmail.com" , subject,msg);}


    void mailSent(QString);
    void on_tabWidget_currentChanged();


    //***************************************** Deconnexion ******************************************************************************

    void on_deconnexion_clicked();

    // ************************************** PushButton Employés ************************************************************************
    void on_ajouterEmploye_clicked();
    void on_AfficherEmp_clicked();
    void on_rechercherEmp_clicked();
    void on_SupprimerEmp_clicked();

    void on_viderAjouterEmp_clicked();
    void on_afficher_employes_pressed();
    void on_ajouter_employe_pressed();

    // *************************************** PushButton Congés ************************************************************************
    void on_SupprimerCong_clicked();
    void on_rechercherCong_clicked();
    void on_AfficherCong_clicked();
    void on_ajouterConge_clicked();
    void on_ModifierCong_clicked();

    void on_ajouter_conge_pressed();
    void on_afficher_conge_pressed();
    void on_ViderAjouterConge_clicked();









    void on_ModifierEmp_clicked();

    void on_tabemployeurs_activated(const QModelIndex &index);

private:
    Ui::acceuil *ui;
    QMediaPlayer *musicClic=new QMediaPlayer;
    employeurs tmpemployeurs;
    conges tmpconges;
    connection c  ;
    QString identifiant;

};

#endif // ACCEUIL_H
