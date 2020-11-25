#ifndef FOURNISSEURS_H
#define FOURNISSEURS_H


#include <QSqlQuery>
#include <QSqlQueryModel>

class fournisseurs
{


    QString  reference_materiel,nommateriel,nom_fournisseur,mail_fournisseur;


    int id_fournisseur,tel_founrisseur;
    double solde ;

public:
    fournisseurs();
     fournisseurs(QString,QString,QString,QString,int,int,double);

     //getters
     QString getref_materiel();
QString getnom_materiel();
     QString getnom_fournisseur();
     QString getmailfournisseur();
     int getid_fournisseur();
     int gettel_fournisseur();
     double getsolde();


     //les fonctions :
     bool ajouter_fournisseur();
     QSqlQueryModel * afficher_fournisseur();
     bool supprimer_fournisseur(int);
     bool modifier_fournisseur(QString ,QString);
     QSqlQueryModel * trier1();
};

#endif // FOURNISSEURS_H
