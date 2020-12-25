#ifndef CONGES_H
#define CONGES_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <connection.h>

class conges
{
public:
    conges();
    conges(QString cin,QString typecongee,QString date_debut,QString date_finn);
    bool ajouterConge();
    bool supprimerConge(int);
    QSqlQueryModel * afficherConge(bool,QString);
    bool modifierconge(QString);

private:
    QString CIN,typeconge,date_deb,date_fin;

};

#endif // CONGES_H
