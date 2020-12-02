#include "client.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
Client::Client()
{
    nom=" ";
    adr=" ";
    id=" ";
}

Client::Client(QString id ,QString nom,QString adr )
{
    this->id=id;
    this->nom=nom;
    this->adr=adr;
}

void Client::setadr(QString adr){this->adr=adr;}
void Client::setid(QString id){this->id=id;}
void Client::setnom(QString nom){this->nom=nom;}



QString Client::get_id(){return id;}
QString Client::get_adr(){return adr;}
QString Client::get_nom(){return nom;}

bool Client::ajouter()
{

    QSqlQuery query;
         query.prepare("INSERT INTO CLIENT (id, nom, adr) "
                       "VALUES (:id, :forename, :surname)");
         query.bindValue(":id",id);
         query.bindValue(":forename", nom);
         query.bindValue(":surname", adr);
        return query.exec();

}

QSqlQueryModel* Client::afficher()
{
  QSqlQueryModel* model=new QSqlQueryModel();


   model->setQuery("SELECT* FROM Client");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identenfiant"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("Adresse"));


  return  model;
}



bool Client::supprimer(QString )
{
    QSqlQuery query;
         query.prepare(" Delete from CLIENT WHERE ID =: ID ");
         query.bindValue(0,id);

        return query.exec();

}


bool Client::modifier(QString id,QString nom,QString adr)
{
    QSqlQuery query;
    bool test= false;
        query.exec("UPDATE CLIENT set NOM='"+nom+"', ADR='"+adr+"'  WHERE ID='"+id+"'");

     test=true;
     return test;

}


QSqlQueryModel *Client::trier(){


    QSqlQueryModel * model =new QSqlQueryModel();
    model->setQuery("select * from Client order by ID , NOM");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("ADR"));

return model;
}


QSqlQueryModel *Client::rechercher(QString chaine){


    QSqlQueryModel * model =new QSqlQueryModel();

   QSqlQuery query ;
       model->setQuery("SELECT* FROM CLIENT WHERE NOM like '%"+chaine+"' OR ADR like '%"+chaine+"'");
       model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
       model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
       model->setHeaderData(2,Qt::Horizontal,QObject::tr("ADR"));
    return model;

}























