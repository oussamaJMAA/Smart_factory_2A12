#include "dechet.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>

Dechet::Dechet()
{
 Ref="";
 Volume="";
 Nature="";
 Mode="";
 Filiere="";
 Lieu="";
}
Dechet::Dechet(QString Ref ,QString Volume,QString Nature,QString Mode,QString Filiere,QString Lieu )
{
    this->Ref=Ref;
    this->Volume=Volume;
    this->Nature=Nature;
    this->Mode=Mode;
    this->Filiere=Filiere;
    this->Lieu=Lieu;
}
void Dechet::setRef(QString n){this->Ref=n;}
void Dechet::setVolume(QString n){this->Volume=n;}
void Dechet::setNature(QString n){this->Nature=n;}
void Dechet::setMode(QString n){this->Mode=n;}
void Dechet::setFiliere(QString n){this->Filiere=n;}
void Dechet::setLieu(QString n){this->Lieu=n;}

QString Dechet::get_Ref(){return Ref;}
QString Dechet::get_Volume(){return Volume;}
QString Dechet::get_Nature(){return Nature;}
QString Dechet::get_Mode(){return Mode;}
QString Dechet::get_Filiere(){return Filiere;}
QString Dechet::get_Lieu(){return Lieu;}

bool Dechet::ajouter()
{

    QSqlQuery query;
         query.prepare("INSERT INTO DECHET (:REF,VOLUME,NATURE,MODE,FILIERE,LIEU) "
                       "VALUES (:REF, :VOLUME, :NATURE, :MODE, :FILIERE, :LIEU)");
         query.bindValue(":REF",Ref);
         query.bindValue(":VOLUME", Volume);
         query.bindValue(":NATURE", Nature);
         query.bindValue(":MODE", Mode);
         query.bindValue(":FILIERE", Filiere);
         query.bindValue(":LIEU", Lieu);
        return query.exec();

}

QSqlQueryModel* Dechet::afficher()
{
  QSqlQueryModel* model=new QSqlQueryModel();


   model->setQuery("SELECT* FROM DECHET");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("VOLUME"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("NATURE"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("MODE"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("FILIERE"));
   model->setHeaderData(5, Qt::Horizontal, QObject::tr("LIEU"));


  return  model;
}

bool Dechet::supprimer(QString )
{
    QSqlQuery query;
         query.prepare(" Delete from DECHET WHERE REF =: REF ");
         query.bindValue(0,Ref);

        return query.exec();

}

bool Dechet::modifier(QString Ref ,QString Volume,QString Nature,QString Mode,QString Filiere,QString Lieu )
{
    QSqlQuery query;
    bool test= false;
        query.exec("UPDATE DECHET set VOLUME='"+Volume+"', NATURE='"+Nature+"' ,MODE ='"+Mode+"',FILIERE ='"+Filiere+"',LIEU ='"+Lieu+"'  WHERE REF='"+Ref+"'");

     test=true;
     return test;

}
