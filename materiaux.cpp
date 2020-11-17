#include "materiaux.h"




materiaux::materiaux(){
    ref_materiel="";
    nom_materiel="";
    quantite=0;
    quantite_res=0;
    prix=0;
}
materiaux::materiaux(QString ref_materiel,QString nom_materiel,double prix,int quantite,int quantite_res)
{
this->ref_materiel=ref_materiel;
    this->nom_materiel=nom_materiel;
     this->prix=prix;
    this->quantite=quantite;
    this->quantite_res=quantite_res;


}

QString materiaux:: getnom_materiel(){return nom_materiel;}
QString materiaux::getref_materiel(){return ref_materiel;}

int materiaux::getquantite(){return quantite;}
int materiaux:: getquantite_res(){return quantite_res;}
double materiaux:: getprix(){return prix;}





bool materiaux:: ajouter(){
    QSqlQuery query;

    query.prepare("INSERT INTO materiaux(ref_materiel,nom_materiel,quantite,prix,quantite_res)"
          "VALUES (:ref_materiel,:nom_materiel,:quantite,:prix,:quantite_res)");
   query.bindValue(":ref_materiel",ref_materiel);
   query.bindValue(":nom_materiel",nom_materiel);
   query.bindValue(":quantite",quantite);
   query.bindValue(":quantite_res",quantite_res);
   query.bindValue(":prix",prix);
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
return model;


}
bool materiaux::supprimer(QString ref_materiel){
    QSqlQuery query;
   query.prepare("Delete from materiaux where ref_materiel= :ref_materiel");
   query.bindValue(":ref_materiel",ref_materiel);
   return query.exec();
}




