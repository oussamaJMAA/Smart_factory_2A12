#ifndef DECHET_H
#define DECHET_H
#include<QString>
#include <QSqlQueryModel>


class Dechet
{
public:
    void setRef(QString n);
    void setVolume(QString n);
    void setNature(QString n);
    void setMode(QString n);
    void setFiliere(QString n);
    void setLieu(QString n);
    QString get_Ref();
    QString get_Volume();
    QString get_Nature();
    QString get_Mode();
    QString get_Filiere();
    QString get_Lieu();
    bool ajouter();
    QSqlQueryModel* afficher();
    bool modifier(QString, QString,QString,QString,QString,QString);
    bool supprimer(QString);
    Dechet();
    Dechet(QString,QString,QString,QString,QString,QString);

private:
    QString Ref,Volume,Nature,Mode,Filiere,Lieu;
};

#endif // DECHET_H
