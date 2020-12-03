#ifndef COLLECTEUR_H
#define COLLECTEUR_H
#include<QString>
#include <QDate>
#include <QSqlQueryModel>

class collecteur
{
public:
    void setNom(QString n);
    void setAdresse(QString n);
    void setId(QString n);
    QString get_Nom();
    QString get_Adresse();
    QString get_Id();
    bool ajouter();
    QSqlQueryModel* afficher();
    bool modifier(QString, QString,QString);
    bool supprimer(QString);
    collecteur();
    collecteur(QString,QString,QString);
private:
    QString Nom,Adresse,Id;

};

#endif // COLLECTEUR_H
