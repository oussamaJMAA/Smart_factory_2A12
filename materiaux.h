#ifndef MATERIAUX_H
#define MATERIAUX_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
class materiaux
{
    QString nom_materiel,ref_materiel;
   double prix;
    int quantite,quantite_res;
    QDate date_achat ;
public:
    //constructeurs
    materiaux();
    materiaux(QString,QString,double,int,int,QDate);
//getters
    QString getnom_materiel();
    QString getref_materiel();
    int getquantite();
    int getquantite_res();
    double getprix();
QDate getdate_achat();

    //fonction de base relatives à l'entité materiauux
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
QSqlQueryModel *afficher1();
bool modifier (QString);

QSqlQueryModel * trier();

QSqlQueryModel* rechercher(QString);
int stat ();
int stat_2();
};

#endif // MATERIAUX_H
