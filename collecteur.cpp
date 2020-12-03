#include "collecteur.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>

collecteur::collecteur()
{
    Id="";
    Nom="";
    Adresse="";

}

collecteur::collecteur(QString Id ,QString Nom,QString Adresse )
{
    this->Id=Id;
    this->Nom=Nom;
    this->Adresse=Adresse;
}

void collecteur::setAdresse(QString Adresse){this->Adresse=Adresse;}
void collecteur::setId(QString Id){this->Id=Id;}
void collecteur::setNom(QString Nom){this->Nom=Nom;}

QString collecteur::get_Id(){return Id;}
QString collecteur::get_Adresse(){return Adresse;}
QString collecteur::get_Nom(){return Nom;}

bool collecteur::ajouter()
{

    QSqlQuery query;
         query.prepare("INSERT INTO COLLECTEUR (ID,NOM,ADRESSE_EMAIL) "
                       "VALUES (:ID, :NOM, :ADRESSE_EMAIL)");
         query.bindValue(":ID",Id);
         query.bindValue(":NOM", Nom);
         query.bindValue(":ADRESSE_EMAIL", Adresse);
        return query.exec();

}

QSqlQueryModel* collecteur::afficher()
{
  QSqlQueryModel* model=new QSqlQueryModel();


   model->setQuery("SELECT* FROM COLLECTEUR");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSE_EMAIL"));


  return  model;
}

bool collecteur::supprimer(QString )
{
    QSqlQuery query;
         query.prepare(" Delete from COLLECTEUR WHERE ID =: ID ");
         query.bindValue(0,Id);

        return query.exec();

}

bool collecteur::modifier(QString Id,QString Nom,QString Adresse)
{
    QSqlQuery query;
    bool test= false;
        query.exec("UPDATE COLLECTEUR set NOM='"+Nom+"', ADRESSE_EMAIL='"+Adresse+"'  WHERE ID='"+Id+"'");

     test=true;
     return test;

}
