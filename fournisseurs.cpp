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


fournisseurs::fournisseurs(QString reference_materiel,int id_fournisseur,QString mail_fournisseur,int tel_founrisseur,double solde,QString nom_fournisseur){



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

    query.prepare("INSERT INTO fournisseur(reference_materiel ,ID_fournisseur,mail_fournisseur,tel_founrisseur,solde,nom_fournisseur)"
          "VALUES (:reference_materiel,:id_fournisseur,:mail_fournisseur,:tel_founrisseur,:solde,:nom_fournisseur)");
   query.bindValue(":reference_materiel",reference_materiel);
   query.bindValue(":id_fournisseur",id_fournisseur);
   query.bindValue(":nom_fournisseur",nom_fournisseur);
   query.bindValue(":solde",solde);
    query.bindValue(":tel_founrisseur",tel_founrisseur);
    query.bindValue(":mail_fournisseur",mail_fournisseur);



return query.exec();

}

QSqlQueryModel * fournisseurs::afficher_fournisseur()
{ QSqlQueryModel * model =new QSqlQueryModel();
model->setQuery("select reference_materiel,ID_fournisseur,nom_fournisseur,mail_fournisseur,tel_founrisseur,solde from fournisseur");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ref_materiel"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID_fournisseur"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("nom_fournisseur"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("mail_fournisseur"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("tel_founrisseur"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("solde"));

return model;
}







bool fournisseurs::supprimer_fournisseur(int id_fournisseur){
    QSqlQuery query;

   query.prepare("Delete from fournisseur where id_fournisseur= :id_fournisseur");
   query.bindValue(":id_fournisseur",id_fournisseur);
   return query.exec();
}

bool fournisseurs::modifier_fournisseur(int id_fournisseur){

    QSqlQuery query ;
    query.prepare("update fournisseur set  solde=:solde,nom_fournisseur=:nom_fournisseur ,tel_founrisseur=:tel_founrisseur,mail_fournisseur=:mail_fournisseur where id_fournisseur=:id_fournisseur  ");

    query.bindValue(":id_fournisseur",id_fournisseur);
query.bindValue(":tel_founrisseur",tel_founrisseur);
query.bindValue(":solde",solde);
query.bindValue(":mail_fournisseur",mail_fournisseur);
query.bindValue(":nom_fournisseur",nom_fournisseur);
    return query.exec();
}


QSqlQueryModel *fournisseurs::trier1(){


    QSqlQueryModel * model =new QSqlQueryModel();
    model->setQuery("select * from fournisseur order by solde,nom_fournisseur,tel_founrisseur");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("reference_materiel"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID_fournisseur"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("nommateriel"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("nom_fournisseur"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("mail_fournisseur"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("tel_fournisseur"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("solde"));

return model;
}
QSqlQueryModel *fournisseurs ::rechercher1 (QString s){


    QSqlQueryModel * model =new QSqlQueryModel();


       model->setQuery("select * from fournisseur where ID_fournisseur like  '%'||'"+s+"'||'%' or reference_materiel like '%'||'"+s+"'||'%'  or tel_founrisseur like '%'||'"+s+"'||'%' or nom_fournisseur like  '%'||'"+s+"'||'%' ");
       model->setHeaderData(0,Qt::Horizontal,QObject::tr("reference_materiel"));
       model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID_fournisseur"));
       model->setHeaderData(2,Qt::Horizontal,QObject::tr("nommateriel"));
       model->setHeaderData(3,Qt::Horizontal,QObject::tr("nom_fournisseur"));
       model->setHeaderData(4,Qt::Horizontal,QObject::tr("mail_fournisseur"));
       model->setHeaderData(5,Qt::Horizontal,QObject::tr("tel_founrisseur"));
       model->setHeaderData(6,Qt::Horizontal,QObject::tr("solde"));
    return model;



}

