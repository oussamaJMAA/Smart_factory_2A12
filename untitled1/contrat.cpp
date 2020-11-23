#include "contrat.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>

Contrat::Contrat()
{
    num=" ";
    type=" ";
    prix=0;
    qte=0;
    pt=0;
}
Contrat::Contrat(QString num , QString type, float prix, int qte, QDate datec, float pt )
{
   this->num=num;
    this->type=type;
    this->prix=prix;
    this->qte=qte;
    this->pt=pt;
    this->datec=datec;




}


void Contrat::setnum(QString num){this->num=num;}
void Contrat::setprixelement(float prix){this->prix=prix;}
void Contrat::setdate(QDate datec){this->datec=datec;}
void Contrat::setqte(int qte){this->qte=qte;}
void Contrat::setpt(float pt){this->pt=pt;}
void Contrat::settype(QString type){this->type=type;}

QDate Contrat::get_date(){return datec;}
float Contrat::get_prixelement(){return prix;}
QString Contrat::get_num(){return num;}
QString Contrat::get_type(){return type;}
int Contrat::get_qte(){return qte;}
float Contrat::get_pt(){return qte*prix;}





bool Contrat::ajouter()
{ bool test = false;
    QSqlQuery query;
    QString chqt = QString::number(qte);
    QString chpt = QString::number(pt);
    QString chprix = QString::number(prix);
          query.prepare("INSERT INTO client (num, type , qte , pt , prix , datec) "
                        "VALUES (:num, :type, :quantity , :pt ,:prix , :date)");
          query.bindValue(":num", num);
          query.bindValue(":type", type);
          query.bindValue(":quantity", chqt);
          query.bindValue(":pt", chpt);
          query.bindValue(":prix", chprix);
          query.bindValue(":date", datec);
          query.exec();

   return test;
}




QSqlQueryModel* Contrat::afficher()
{
  QSqlQueryModel* model=new QSqlQueryModel();


   model->setQuery("SELECT* FROM Contrat");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("numero du contrat"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("prix d'un element"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prix Total"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("Type"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("Quantite "));
   model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date"));


  return  model;
}



bool Contrat::supprimer(QString )
{
    QSqlQuery query;
         query.prepare(" Delete from Contrat where num=:num");
         query.bindValue(0, num);

        return query.exec();

}








