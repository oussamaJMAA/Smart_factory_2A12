#include "contrat.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include<QDate>

Contrat::Contrat()
{
    num=" ";
    type=" ";
    prix=0;
    qte=0;
    pt=0;
}
Contrat::Contrat(QString num , QString type, float prix, int qte, QDate datec, float pt,QString idclient,QString REF_mat)
{
   this->num=num;
    this->type=type;
    this->prix=prix;
    this->qte=qte;
    this->pt=pt;
    this->datec=datec;
    this->idclient=idclient;
    this->REF_mat=REF_mat;

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
{
    QSqlQuery query;
    pt=qte*prix;
    QString chqt = QString::number(qte);
    QString chpt = QString::number(pt);
    QString chprix = QString::number(prix);
          query.prepare("INSERT INTO CONTRAT (NUM_C, TYPE , QUANTITE , PRIXTOTAL , PRIXELEMENT , DATEC,REF_MATERIEL,ID) "
                        "VALUES (:num, :type, :quantity , :pt ,:prix , :date , :REF_MATERIEL , :ID )");

          // INSERT INTO contrat (NUM_C,PRIXELEMENT,PRIXTOTAL,TYPE,QUANTITE,DATEC,REF_MATERIEL,ID)VALUES('9999999',10,100,'mat',10,'20/12/2020','dolce','45678977')

          query.bindValue(":num", num);
          query.bindValue(":type", type);
          query.bindValue(":quantity", chqt);
          query.bindValue(":pt", chpt);
          query.bindValue(":prix", chprix);
          query.bindValue(":date", datec);
          query.bindValue(":REF_MATERIEL",REF_mat);
          query.bindValue(":ID", idclient);
          return query.exec();

}
bool Contrat::modifier(QString num,QString type,float prix,int qte,float pt)
{
    QSqlQuery query;
    QString chprix = QString::number(prix);
    pt=prix*qte;
    QString chpt = QString::number(pt);
    QString chqt = QString::number(qte);
    bool test= false;
        query.exec("UPDATE CONTRAT set TYPE='"+type+"', PRIXELEMENT='"+chprix+"', QUANTITE ='"+chqt+"', PRIXTOTAL='"+chpt+"'  WHERE NUM_C='"+num+"'");

     test=true;
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
  model->setHeaderData(6, Qt::Horizontal, QObject::tr("id client"));
  model->setHeaderData(7, Qt::Horizontal, QObject::tr("Reference mat"));


  return  model;
}



bool Contrat::supprimer(QString )
{
    QSqlQuery query;
         query.prepare(" Delete from CONTRAT WHERE NUM_C=:NUM_C");
         query.bindValue(0, num);
         return query.exec();

}




QSqlQueryModel* Contrat::trierc()
{
  QSqlQueryModel* model=new QSqlQueryModel();


   model->setQuery("SELECT* from Contrat order by  PRIXELEMENT , PRIXTOTAL , TYPE , QUANTITE , DATEC");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM_C"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRIXELEMENT"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIXTOTAL"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("QUANTITE "));
   model->setHeaderData(5, Qt::Horizontal, QObject::tr("DATEC"));
   model->setHeaderData(6, Qt::Horizontal, QObject::tr("id client"));
   model->setHeaderData(7, Qt::Horizontal, QObject::tr("Reference mat"));

  return  model;
}




QSqlQueryModel *Contrat::rechercherc(QString chaine1){


    QSqlQueryModel * model =new QSqlQueryModel();

   QSqlQuery query ;
       model->setQuery("SELECT* FROM CONTRAT WHERE NOM_C like '%"+chaine1+"' OR PRIXELEMENT like '%"+chaine1+"'  OR PRIXTOTAL like '%"+chaine1+"' OR TYPE like '%"+chaine1+"'");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM_C"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRIXELEMENT"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIXTOTAL"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("QUANTITE"));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("DATEC"));
       model->setHeaderData(6, Qt::Horizontal, QObject::tr("id client"));
       model->setHeaderData(7, Qt::Horizontal, QObject::tr("Reference mat"));
    return model;


}













