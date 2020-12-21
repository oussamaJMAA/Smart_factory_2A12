#include "materiaux.h"
#include <QDate>



materiaux::materiaux(){
    ref_materiel="";
    nom_materiel="";
    quantite=0;
    quantite_res=0;
    prix=0;
    date_achat.currentDate();
}
materiaux::materiaux(QString ref_materiel,QString nom_materiel,double prix,int quantite,int quantite_res,QDate date_achat)
{
this->ref_materiel=ref_materiel;
    this->nom_materiel=nom_materiel;
     this->prix=prix;
    this->quantite=quantite;
    this->quantite_res=quantite_res;
this->date_achat = date_achat;

}

QString materiaux:: getnom_materiel(){return nom_materiel;}
QString materiaux::getref_materiel(){return ref_materiel;}

int materiaux::getquantite(){return quantite;}
int materiaux:: getquantite_res(){return quantite_res;}
double materiaux:: getprix(){return prix;}


 QDate  materiaux::getdate_achat(){return date_achat;}


bool materiaux:: ajouter(){
    QSqlQuery query;

    query.prepare("INSERT INTO materiaux(ref_materiel,nom_materiel,quantite,prix,quantite_res,date_achat)"
          "VALUES (:ref_materiel,:nom_materiel,:quantite,:prix,:quantite_res,:date_achat)");
   query.bindValue(":ref_materiel",ref_materiel);
   query.bindValue(":nom_materiel",nom_materiel);
   query.bindValue(":quantite",quantite);
   query.bindValue(":quantite_res",quantite_res);
   query.bindValue(":prix",prix);
   query.bindValue(":date_achat",date_achat);
return query.exec();
}

QSqlQueryModel * materiaux::afficher()
{ QSqlQueryModel * model =new QSqlQueryModel();
model->setQuery("select * from materiaux");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ref_materiel"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom_materiel"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("quantite"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("prix"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("quantite_res"));


model->setHeaderData(5,Qt::Horizontal,QObject::tr("date_achat"));
return model;
}



bool materiaux::supprimer(QString ref_materiel){
    QSqlQuery query;
   query.prepare("Delete from materiaux where ref_materiel= :ref_materiel");
   query.bindValue(":ref_materiel",ref_materiel);
   return query.exec();
}

bool materiaux::modifier(QString ref_materiel){

    QSqlQuery query ;
    query.prepare("update materiaux set nom_materiel= :nom_materiel , quantite= :quantite , quantite_res = :quantite_res , prix= :prix,date_achat= :date_achat where ref_materiel= :ref_materiel");
    query.bindValue(":nom_materiel",nom_materiel);
    query.bindValue(":quantite",quantite);
    query.bindValue(":quantite_res",quantite_res);
    query.bindValue(":prix",prix);
     query.bindValue(":ref_materiel",ref_materiel);
       query.bindValue(":date_achat",date_achat);
    return query.exec();

}

QSqlQueryModel *materiaux::trier(){


    QSqlQueryModel * model =new QSqlQueryModel();
    model->setQuery("select * from materiaux order by date_achat,nom_materiel,quantite");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ref_materiel"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom_materiel"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("quantite"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("prix"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("quantite_res"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("date_achat"));

return model;
}


QSqlQueryModel* materiaux ::rechercher (QString s){

    QSqlQueryModel * model =new QSqlQueryModel();

   model->setQuery("select * from materiaux where ref_materiel like  '%'||'"+s+"'||'%' or nom_materiel like '%'||'"+s+"'||'%'  or quantite like '%'||'"+s+"'||'%'");
   model->setHeaderData(0,Qt::Horizontal,QObject::tr("ref_materiel"));

   model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom_materiel"));
   model->setHeaderData(2,Qt::Horizontal,QObject::tr("quantite"));
   model->setHeaderData(3,Qt::Horizontal,QObject::tr("prix"));
   model->setHeaderData(4,Qt::Horizontal,QObject::tr("quantite_res"));
   model->setHeaderData(5,Qt::Horizontal,QObject::tr("date_achat"));

   return model;


}
QSqlQueryModel * materiaux::stat()
{ QSqlQueryModel * model =new QSqlQueryModel();
model->setQuery("select sum(quantite_res) from materiaux");

model->setHeaderData(0,Qt::Horizontal,QObject::tr("Quantite Restante"));

return model;

}

int materiaux::stat_2()
{ QSqlQuery query;
query.prepare("select sum(quantite) from materiaux");



return query.exec();

}
