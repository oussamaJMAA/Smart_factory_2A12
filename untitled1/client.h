#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QSqlQueryModel>

class Client
{
public:
    void setid(QString n);
    void setnom(QString n);
    void setadr(QString adr);
    QString get_id();
    QString get_nom();
    QString get_adr();
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(QString);
    bool modifier(QString,QString,QString);
    Client();
    Client(QString,QString,QString);
    QSqlQueryModel * trier();
    QSqlQueryModel *rechercher(QString);

private:
    QString id,nom,adr;
};

#endif // CLIENT_H
