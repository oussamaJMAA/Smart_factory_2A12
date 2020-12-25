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
    employeurs(QString cin,QString nomm,QString preomm,QString emaill,QString adressee,QString date_naiss,QString servicee,QString tel);
    QString Get_CIN();
    QString Get_tel();
    QString Get_nom();
    QString Get_prenom();
    QString Get_email();
    QString Get_adresse();
    QString Get_date_nais();
    QString Get_service();
    bool ajouter();
    QSqlQueryModel * afficherEmp(int,QString);
    bool supprimerEmp(QString);
    bool modifierEmp(QString);
    bool login(QString,QString);


private:
    QString nom,prenom,adresse,email,date_nais,service,TEL,CIN;
};

#endif // EMPLOYEURS_H
