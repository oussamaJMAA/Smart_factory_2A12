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
    ~acceuil();

private slots:
    void sendMail(QString subject , QString msg){
            Smtp* smtp = new Smtp("nasreddine.elmadhkour@esprit.tn","191JFT2263","smtp.gmail.com", 465);
            connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
            smtp->sendMail("nasreddine.elmadhkour@esprit.tn", "nasreddine1234@gmail.com" , subject,msg);
    };
    void mailSent(QString);
    void on_tabWidget_currentChanged();


    //***************************************** Deconnexion ******************************************************************************

    void on_deconnexion_clicked();

    // ************************************** PushButton Employés ************************************************************************

    void on_ajouterEmploye_clicked();
    void on_AfficherEmp_clicked();
    void on_viderAjouterEmp_clicked();
    void on_afficher_employes_clicked();
    void on_ajouter_employe_clicked();
    void on_rechercherEmp_clicked();
    void on_SupprimerEmp_clicked();

    // *************************************** PushButton Congés ************************************************************************

    void on_ajouterConge_clicked();
    void on_ViderAjouterConge_clicked();
    void on_ajouter_conge_clicked();
    void on_afficher_conge_clicked();
    void on_AfficherCong_clicked();





    void on_SupprimerCong_clicked();

    void on_rechercherCong_clicked();

private:
    Ui::acceuil *ui;
    QMediaPlayer *musicClic=new QMediaPlayer;
    employeurs tmpemployeurs;
    conges tmpconges;
};

#endif // ACCEUIL_H
