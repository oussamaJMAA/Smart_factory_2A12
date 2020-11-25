#include "conges.h"
conges::conges()
{
CIN="";
typeconge="";
date_deb="";
date_fin="";
}

conges::conges(QString cin,QString typecongee,QString date_debut,QString date_finn)
{
CIN=cin;
typeconge=typecongee;
date_deb=date_debut;
date_fin=date_finn;
}


//************************************************    AJOUTER EMPLOYEURS  ********************

bool conges::ajouterConge()
{
    QSqlQuery query;
    query.prepare("INSERT INTO conges VALUES(IDCONGE.nextval,:cin,:typeConge,:date_deb_conge,:date_fin_conge) ");
    query.bindValue(":cin",CIN);
    query.bindValue(":typeConge",typeconge);
    query.bindValue(":date_deb_conge",date_deb);
    query.bindValue(":date_fin_conge",date_fin);
    return query.exec();
}
//*************************************************   SUPPRIMER CONGES  ********************
bool conges::supprimerConge(int idd)
{
    QSqlQuery query;
    QString id=QString::number(idd);
    query.prepare("Delete FROM conges where ID_CONGE=:id");
    query.bindValue(":id",id);
    return query.exec();
}

//************************************************    MODIFIER CONGES ********************

bool conges::modifierconge(QString id)
{   QSqlQuery query;
    bool Testquery=false;
    QSqlQuery qry;
    qry.prepare("SELECT ID_CONGE FROM conges where ID_CONGE=?;");
    qry.addBindValue(id);
    bool exist=false;
    if(qry.exec())
        if(qry.next())
            {
            QVariant ch=qry.value(0);
            QString verif = QVariant(ch).toString();
            qDebug()<<verif;
            if(verif==id)
                exist=true;
             }
    if(exist)
       {
            if(date_deb!="")
            {
                query.prepare("UPDATE conges SET date_deb_conge =? WHERE ID_CONGE='"+id+"';");
                query.addBindValue(date_deb);query.exec();Testquery=true;

            }
            if(date_fin!="")
            {

                query.prepare("UPDATE conges SET date_fin_conge =? WHERE ID_CONGE='"+id+"';");
                query.addBindValue(date_fin);query.exec();Testquery=true;
            }
            if(typeconge!="")
            {
                query.prepare("UPDATE conges SET type_conge =? WHERE ID_CONGE='"+id+"';");
                query.addBindValue(typeconge);query.exec();Testquery=true;
            }

        }


 return Testquery;
}
//************************************************    AFFICHAGE CONGES ********************

QSqlQueryModel * conges::afficherConge(bool tri,QString chaine)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    if(tri)
        model->setQuery("SELECT id_conge,nom,prenom,type_conge,date_deb_conge,date_fin_conge from employeurs,conges where employeurs.cin=conges.cin ORDER BY nom;");
    else if(chaine=="all")
          model->setQuery("SELECT id_conge,nom,prenom,type_conge,date_deb_conge,date_fin_conge from employeurs,conges where employeurs.cin=conges.cin;");

    else
    {
        //*****************  Un congé ***************

        QSqlQuery qry;
        qry.prepare("SELECT CIN FROM conges where CIN=?;");
        qry.addBindValue(chaine);
        bool exist=false;
        if(qry.exec())
            if(qry.next())
                {
                QVariant ch=qry.value(0);
                QString verif = QVariant(ch).toString();
                qDebug()<<verif;
                if(verif==chaine)
                    exist=true;

                }
        if(exist)
           {
            QString select="select id_conge,nom,prenom,type_conge,date_deb_conge,date_fin_conge from conges,employeurs where employeurs.cin=conges.cin and conges.CIN='"+chaine+"';";
            model->setQuery(select);
           }
    }
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Type Congé"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Debut"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Fin"));

    return model;
}
