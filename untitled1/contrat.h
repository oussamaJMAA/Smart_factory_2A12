#ifndef CONTRAT_H
#define CONTRAT_H
#include <QString>
#include <QDate>
#include <QSqlQueryModel>

class Contrat
{
public:
    void setnum(QString n);
    void settype(QString n);
    void setprixelement(float b);
    void setqte(int k);
    void setdate(QDate d);
    void setpt(float b);
    QString get_num();
    QString get_type();
    float get_prixelement();
    QDate get_date();
    int get_qte();
    float get_pt();
    bool ajouter();
    QSqlQueryModel* afficher();
    bool modifier(QString, QString,float,int,float);
    bool supprimer(QString);
    Contrat();
    Contrat(QString,QString,float,int,QDate,float);

private:
    QString num,type;
    QDate datec;
    int qte;
    float pt,prix;
};

#endif // CONTRAT_H
