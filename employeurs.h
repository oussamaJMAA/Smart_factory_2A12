#ifndef EMPLOYEURS_H
#define EMPLOYEURS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <connection.h>

class employeurs
{
public:
    employeurs();
    employeurs(int cin,QString nomm,QString preomm,QString emaill,QString adressee,QString date_naiss,QString servicee,int tel);
    int Get_CIN();
    int Get_tel();
    QString Get_nom();
    QString Get_prenom();
    QString Get_email();
    QString Get_adresse();
    QString Get_date_nais();
    QString Get_service();
    bool ajouter();
    QSqlQueryModel * afficherEmp(bool tri,QString chaine);
    bool supprimerEmp(QString cin);

    bool supprimer(int);
private:
    QString nom,prenom,adresse,email,date_nais,service;
    int TEL,CIN;

};

#endif // EMPLOYEURS_H
