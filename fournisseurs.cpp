#include "fournisseurs.h"

fournisseurs::fournisseurs()
{
    nom_fournisseur="";
    mail_fournisseur="";
    reference_materiel="";

    id_fournisseur=0;
           tel_founrisseur=0;
            solde =0;
}


fournisseurs::fournisseurs(QString nom_fournisseur,QString mail_fournisseur,QString reference_materiel,int tel_founrisseur,int id_fournisseur,double solde){



    this->nom_fournisseur=nom_fournisseur;

    this->mail_fournisseur=mail_fournisseur;
    this->reference_materiel=reference_materiel;
    this->tel_founrisseur=tel_founrisseur;
    this->id_fournisseur=id_fournisseur;
    this->solde=solde;
}



QString fournisseurs::getref_materiel(){return reference_materiel;}
QString fournisseurs:: getnom_fournisseur(){return nom_fournisseur;}
QString fournisseurs::getmailfournisseur(){return mail_fournisseur;}
int fournisseurs::gettel_fournisseur(){return tel_founrisseur;}
int fournisseurs:: getid_fournisseur(){return id_fournisseur;}
double fournisseurs::getsolde(){return solde;}


bool fournisseurs:: ajouter_fournisseur(){
    QSqlQuery query;

    query.prepare("INSERT INTO fournisseur(id_fournisseur ,nom_fournisseur,reference_materiel,tel_founrisseur,mail_fournisseur,solde)"
          "VALUES (:id_fournisseur,:nom_fournisseur,:reference_materiel,:tel_founrisseur,:mail_fournisseur,:solde)");
   query.bindValue(":reference_materiel",reference_materiel);
   query.bindValue(":id_fournisseur",id_fournisseur);
   query.bindValue(":nom_fournisseur",nom_fournisseur);
   query.bindValue(":solde",solde);
    query.bindValue(":prix",tel_founrisseur);
    query.bindValue(":mail_fournisseur",mail_fournisseur);
     query.bindValue(":tel_founrisseur",tel_founrisseur);


return query.exec();

}

QSqlQueryModel * fournisseurs::afficher_fournisseur()
{ QSqlQueryModel * model =new QSqlQueryModel();
model->setQuery("select reference_materiel, ID_fournisseur , nom_materiel ,nom_fournisseur,mail_fournisseur,tel_founrisseur,solde from fournisseur inner join  materiaux on (materiaux.ref_materiel=fournisseur.reference_materiel)");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("reference_materiel"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID_fournisseur"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("nom_materiel"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("nom_fournisseur"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("mail_fournisseur"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("tel_founrisseur"));
model->setHeaderData(6,Qt::Horizontal,QObject::tr("solde"));

return model;
}







bool fournisseurs::supprimer_fournisseur(int id_fournisseur){
    QSqlQuery query;
   query.prepare("Delete from fournisseur where id_fournisseur = :id_fournisseur");
   query.bindValue(":id_fournisseur",id_fournisseur);
   return query.exec();
}

bool fournisseurs::modifier_fournisseur(QString reference_materiel,QString nommateriel){

    QSqlQuery query ;
    query.prepare("update fournisseur set nommateriel= :nommateriel   where reference_materiel= :reference_materiel  ");
    query.bindValue(":nommateriel",nommateriel);
     query.bindValue(":reference_materiel",reference_materiel);
    return query.exec();
}


QSqlQueryModel *fournisseurs::trier1(){


    QSqlQueryModel * model =new QSqlQueryModel();
    model->setQuery("select * from fournisseur order by solde,nom_fournisseur,nommateriel");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("reference_materiel"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID_fournisseur"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("nommateriel"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("nom_fournisseur"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("mail_fournisseur"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("tel_founrisseur"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("solde"));

return model;
}
QSqlQueryModel *fournisseurs ::rechercher1 (QString s){


    QSqlQueryModel * model =new QSqlQueryModel();


       model->setQuery("select * from fournisseur where ID_fournisseur like  '%'||'"+s+"'||'%' or nommateriel like '%'||'"+s+"'||'%'  or tel_founrisseur like '%'||'"+s+"'||'%' or nom_fournisseur like  '%'||'"+s+"'||'%' ");
       model->setHeaderData(0,Qt::Horizontal,QObject::tr("reference_materiel"));
       model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID_fournisseur"));
       model->setHeaderData(2,Qt::Horizontal,QObject::tr("nommateriel"));
       model->setHeaderData(3,Qt::Horizontal,QObject::tr("nom_fournisseur"));
       model->setHeaderData(4,Qt::Horizontal,QObject::tr("mail_fournisseur"));
       model->setHeaderData(5,Qt::Horizontal,QObject::tr("tel_founrisseur"));
       model->setHeaderData(6,Qt::Horizontal,QObject::tr("solde"));
    return model;



}

