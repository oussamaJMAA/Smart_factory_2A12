#include "employeurs.h"

employeurs::employeurs()
{
    nom="";
    prenom="";
    adresse="";
    email="";
    date_nais="";
    TEL=0;
    CIN=0;
    service="";
}
employeurs::employeurs(int cin,QString nomm,QString prenomm,QString emaill,QString adressee,QString date_naiss,QString servicee,int tel)
{
    CIN=cin;
    nom=nomm;
    prenom=prenomm;
    adresse=adressee;
    date_nais=date_naiss;
    service=servicee;
    TEL=tel;
    email=emaill;

}

QString employeurs::Get_nom(){return nom;}
QString employeurs::Get_prenom(){return prenom;}
QString employeurs::Get_email(){return email;}
QString employeurs::Get_adresse(){return adresse;}
QString employeurs::Get_date_nais(){return date_nais;}
QString employeurs::Get_service(){return service;}
int employeurs::Get_CIN(){return CIN;}
int employeurs::Get_tel(){return TEL;}

//************************************************    AJOUTER EMPLOYEURS ********************
bool employeurs::ajouter()
{
    QSqlQuery query;
    QString cin=QString::number(CIN);
    QString tel=QString::number(TEL);
    nom = nom.toUpper();
    prenom=prenom.toUpper();

    query.prepare("INSERT INTO employeurs VALUES(:cin,:nom,:prenom,:datenais,:email,:adresse,:tel,:service) ");
    query.bindValue(":cin",CIN);
    query.bindValue(":tel",TEL);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":datenais",date_nais);
    query.bindValue(":email",email);
    query.bindValue(":service",service);
    query.bindValue(":adresse",adresse);
    return query.exec();
}
//************************************************    SUPPRIMER EMPLOYEURS ********************
bool employeurs::supprimerEmp(QString cin)
{
    QSqlQuery query;
    query.prepare("Delete FROM employeurs where CIN=:id");
    query.bindValue(":id",cin);
    return query.exec();
}
//************************************************    AFFICHAGE EMPLOYEURS ********************

QSqlQueryModel * employeurs::afficherEmp(bool tri,QString chaine)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    if(tri)
        model->setQuery("SELECT * FROM employeurs ORDER BY prenom ;");
    else if(chaine=="all")
          model->setQuery("select * FROM employeurs ;");

    else
    {
        //*****************  Un employé ***************

        QSqlQuery qry;
        qry.prepare("SELECT CIN FROM employeurs where CIN=?;");
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
            QString select="select * from employeurs where CIN='"+chaine+"';";
            model->setQuery(select);
           }
    }
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("date de naissance"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("E-mail"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Adresse"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("Tel"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("Service"));
    return model;
}







