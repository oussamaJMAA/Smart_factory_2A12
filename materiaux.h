#ifndef MATERIAUX_H
#define MATERIAUX_H
#include <QSqlQuery>
#include <QSqlQueryModel>

class materiaux
{
    QString nom_materiel,ref_materiel;
   double prix;
    int quantite,quantite_res;
    QString date;
public:
    //constructeurs
    materiaux();
    materiaux(QString,QString,double,int,int);
//getters
    QString getnom_materiel();
    QString getref_materiel();
    int getquantite();
    int getquantite_res();
    double getprix();


    //fonction de base relatives à l'entité materiauux
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);




};

#endif // MATERIAUX_H
