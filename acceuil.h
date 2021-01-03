#ifndef ACCEUIL_H
#define ACCEUIL_H

#include <QMediaPlayer>
#include <QDialog>
#include <QMainWindow>
#include <QApplication>
#include <QMessageBox>
#include <QPixmap>
#include <QApplication>
#include <QGraphicsDropShadowEffect>
#include <QDateTime>
#include <QModelIndex>
#include "smtp.h"
#include "employeurs.h"
#include "conges.h"
#include "connection.h"
#include <materiaux.h>
#include <fournisseurs.h>
#include <QtCharts/QChart>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChartView>
#include <QtCharts>
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
        else if(date=="1950/12/24"|| date=="24/12/1950" || date.length()!=10)
                    date="";
        return date;
    }

    bool control_saisie_chaine(QString ch){
        {
            ch=ch.toUpper();
            if(ch=="")
                return true;
            else
            for(int i=0;i<ch.length();i++)
                if((ch[i]<'A' || ch[i]>'Z') && ch[i]!=" " )
                    return true;

            return false;
        }
    }


    void calcul();

private slots:
    void sendMail(QString subject , QString msg){
            Smtp* smtp = new Smtp("nasreddine.elmadhkour@esprit.tn","191JFT2263","smtp.gmail.com", 465);
            connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
            smtp->sendMail("nasreddine.elmadhkour@esprit.tn", "nasreddine1234@gmail.com" , subject,msg);}
    void mailSent(QString);

    void on_tabWidget_currentChanged();


    //***************************************** Deconnexion ******************************************************************************

    void on_deconnexion_clicked();

    // ************************************************************ PushButton Employés ************************************************************************
    void on_ajouterEmploye_clicked();
    void on_AfficherEmp_clicked();
    void on_SupprimerEmp_clicked();
    void on_ModifierEmp_clicked();
    void on_tabemployeurs_activated(const QModelIndex &index);
    void on_Linerechemp_textChanged(const QString &arg1);
    void on_viderAjouterEmp_clicked();
    void on_afficher_employes_pressed();
    void on_ajouter_employe_pressed();
    // ************************************************************ PushButton Congés ************************************************************************
    void on_SupprimerCong_clicked();
    void on_rechercherCong_clicked();
    void on_AfficherCong_clicked();
    void on_ajouterConge_clicked();
    void on_ModifierCong_clicked();
    void on_ajouter_conge_pressed();
    void on_afficher_conge_pressed();
    void on_ViderAjouterConge_clicked();







    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_modifier_2_clicked();

    void on_pushButton_10_clicked();

    void on_supprimer_2_clicked();

    void on_pushButton_15_clicked();

    void on_quitter_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_20_clicked();

    void on_quitter_3_clicked();

    void on_modifier_3_clicked();

    void on_pushButton_25_clicked();

    void on_supprimer_3_clicked();

    void on_pushButton_28_clicked();





    void on_retour_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_22_clicked();



    void on_pushButton_29_clicked();

    void on_pushButton_26_clicked();

    void on_supprimer_4_clicked();

    void on_trier_clicked();




    void on_tableView_2_activated(const QModelIndex &index);

    void on_tableView_activated(const QModelIndex &index);



 //   void on_rechercher_ref_textEdited(const QString &arg1);

    void on_rechercher_ref_cursorPositionChanged();

    void on_rechercher_id_cursorPositionChanged();



    void on_affiche_mat_activated();

    void on_pushButton_23_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_30_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();
    void on_lineEdit_26_textChanged();

    void on_lineEdit_27_textChanged();

    void on_lineEdit_16_textChanged();

    void on_lineEdit_14_textChanged();







    void on_affiche_mat_activated(const QModelIndex &index);

private:
    Ui::acceuil *ui;
    QMediaPlayer *musicClic=new QMediaPlayer;
    employeurs tmpemployeurs;
    conges tmpconges;
    connection c  ;
    QString identifiant;




    QPropertyAnimation *animation;
    QPropertyAnimation *animation1;
    QPropertyAnimation *animation2;
QMediaPlayer *musicConect=new QMediaPlayer;
materiaux Etmp;
fournisseurs Etmp1;
};

#endif // ACCEUIL_H
