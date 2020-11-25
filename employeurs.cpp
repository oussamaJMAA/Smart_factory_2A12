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
    date_nais.remove(7,1);
    date_nais.remove(4,1);
    query.prepare("INSERT INTO employeurs VALUES(:cin,:nom,:prenom,TO_DATE(:datenais,'YYYYMMDD'),:email,:adresse,:tel,:service) ");
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

//************************************************    MODIFIER EMPLOYEURS ********************
bool employeurs::modifierEmp(QString CIN_rechercher)
{   QSqlQuery query;
    bool Testquery=false;
    QSqlQuery qry;
    qry.prepare("SELECT CIN FROM employeurs where CIN=?;");
    qry.addBindValue(CIN_rechercher);
    bool exist=false;
    if(qry.exec())
        if(qry.next())
            {
            QVariant ch=qry.value(0);
            QString verif = QVariant(ch).toString();
            qDebug()<<verif;
            if(verif==CIN_rechercher)
                exist=true;
             }
    if(exist)
       {
            if(nom!="")
            {   nom=nom.toUpper();
                query.prepare("UPDATE employeurs SET nom =? WHERE CIN='"+CIN_rechercher+"';");
                query.addBindValue(nom);query.exec();Testquery=true;

            }
            if(prenom!="")
            {
                prenom=prenom.toUpper();
                query.prepare("UPDATE employeurs SET prenom =? WHERE CIN='"+CIN_rechercher+"';");
                query.addBindValue(prenom);query.exec();Testquery=true;
            }
            if(adresse!="")
            {
                query.prepare("UPDATE employeurs SET adresse =? WHERE CIN='"+CIN_rechercher+"';");
                query.addBindValue(adresse);query.exec();Testquery=true;
            }
            if(email!="")
             {
                query.prepare("UPDATE employeurs SET email =? WHERE CIN='"+CIN_rechercher+"';");
                query.addBindValue(email);query.exec();Testquery=true;
            }
            if(service!="")
             {
                query.prepare("UPDATE employeurs SET service =? WHERE CIN='"+CIN_rechercher+"';");
                query.addBindValue(service);query.exec();Testquery=true;
            }

            if(TEL!=0)
             {
                query.prepare("UPDATE employeurs SET Tel =? WHERE CIN='"+CIN_rechercher+"';");
                query.addBindValue(TEL);query.exec();Testquery=true;
            }
            if(date_nais!="")
             {
                query.prepare("UPDATE employeurs SET date_naissance =? WHERE CIN='"+CIN_rechercher+"';");
                query.addBindValue(date_nais);query.exec();Testquery=true;
            }
            if(CIN!=0)
             {
                query.prepare("UPDATE employeurs SET CIN =? WHERE CIN='"+CIN_rechercher+"';");
                query.addBindValue(CIN);query.exec();Testquery=true;
            }
        }


 return Testquery;
}
//************************************************    AFFICHAGE EMPLOYEURS ********************

QSqlQueryModel * employeurs::afficherEmp(bool tri,QString chaine)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    if(tri)
        model->setQuery("SELECT cin,nom,prenom,TO_CHAR(date_naissance, 'yyyy/mm/dd'),email,adresse,tel,service FROM employeurs ORDER BY prenom ;");
    else if(chaine=="all")
          model->setQuery("select cin,nom,prenom,TO_CHAR(date_naissance, 'yyyy/mm/dd'),email,adresse,tel,service FROM employeurs ;");

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
            QString select="select cin,nom,prenom,TO_CHAR(date_naissance, 'dd/mm/yyyy'),email,adresse,tel,service from employeurs where CIN='"+chaine+"';";
            model->setQuery(select);
           }
    }
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom "));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prénom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("date de naissance"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("E-mail"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Adresse"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("Tel"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("Service"));
    return model;
}





// ********************************************   Login   ****************************************
bool employeurs::login(QString username , QString password)
{
    QSqlQuery qry;
    qry.prepare("SELECT CIN FROM employeurs where CIN=? and prenom =?");
    qry.addBindValue(username);
    qry.addBindValue(password);
    if(qry.exec())
        if(qry.next())
            {
                QString user = QVariant(qry.value(0)).toString();
                qDebug()<<qry.value(0);
            if(user==username)
            {return true;}            }
    return false;
}





