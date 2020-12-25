#include "employeurs.h"
employeurs::employeurs()
{
    nom="";
    prenom="";
    adresse="";
    email="";
    date_nais="";
    TEL="";
    CIN="";
    service="";
}
employeurs::employeurs(QString cin,QString nomm,QString prenomm,QString emaill,QString adressee,QString date_naiss,QString servicee,QString tel)
{CIN=cin;nom=nomm;prenom=prenomm;adresse=adressee;date_nais=date_naiss;service=servicee;TEL=tel; email=emaill;}

QString employeurs::Get_nom(){return nom;}
QString employeurs::Get_prenom(){return prenom;}
QString employeurs::Get_email(){return email;}
QString employeurs::Get_adresse(){return adresse;}
QString employeurs::Get_date_nais(){return date_nais;}
QString employeurs::Get_service(){return service;}
QString employeurs::Get_CIN(){return CIN;}
QString employeurs::Get_tel(){return TEL;}
//************************************************    AJOUTER EMPLOYEURS ********************
bool employeurs::ajouter()
{
    QSqlQuery query;
    nom = nom.toUpper();
    prenom=prenom.toUpper();
    adresse=adresse.toUpper();
    date_nais.remove(7,1);
    date_nais.remove(4,1);
    query.prepare("INSERT INTO employeurs VALUES(:cin,:nom,:prenom,TO_DATE(:datenais,'yyyymmdd'),:email,:adresse,:tel,:service) ");
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
            {   adresse=adresse.toUpper();
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
                query.prepare("UPDATE employeurs SET date_naissance =TO_DATE(:datenais,'dd/mm/yyyy') WHERE CIN='"+CIN_rechercher+"';");
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

QSqlQueryModel * employeurs::afficherEmp(int tri,QString chaine)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    chaine=chaine.toUpper();
    switch (tri) {
    case 0:
        model->setQuery("select TO_CHAR(cin),nom,prenom,service,TO_CHAR(date_naissance, 'yyyy/mm/dd'),email,adresse,TO_CHAR(tel) FROM employeurs ;");
        break;
    case 1:
        model->setQuery("SELECT TO_CHAR(cin),nom,prenom,service,TO_CHAR(date_naissance, 'yyyy/mm/dd'),email,adresse,TO_CHAR(tel) FROM employeurs ORDER BY prenom ;");
        break;
    case 2:
        model->setQuery("SELECT TO_CHAR(cin),nom,prenom,service,TO_CHAR(date_naissance, 'yyyy/mm/dd'),email,adresse,TO_CHAR(tel) FROM employeurs ORDER BY CIN ;");
        break;
    case 4:
        model->setQuery("SELECT TO_CHAR(cin),nom,prenom,service,TO_CHAR(date_naissance, 'yyyy/mm/dd'),email,adresse,TO_CHAR(tel) FROM employeurs ORDER BY service ;");
        break;
    case 3:
        model->setQuery("SELECT TO_CHAR(cin),nom,prenom,service,TO_CHAR(date_naissance, 'yyyy/mm/dd'),email,adresse,TO_CHAR(tel) FROM employeurs ORDER BY CIN,prenom ;");
        break;
    case 6:
        model->setQuery("SELECT TO_CHAR(cin),nom,prenom,service,TO_CHAR(date_naissance, 'yyyy/mm/dd'),email,adresse,TO_CHAR(tel) FROM employeurs ORDER BY Service,CIN ;");
        break;
    case 7:
        model->setQuery("SELECT TO_CHAR(cin),nom,prenom,service,TO_CHAR(date_naissance, 'yyyy/mm/dd'),email,adresse,TO_CHAR(tel) FROM employeurs ORDER BY Service,CIN,prenom ;");
        break;
    case 10:
        {
        QString select="select TO_CHAR(cin),nom,prenom,service,TO_CHAR(date_naissance, 'dd/mm/yyyy'),email,adresse,TO_CHAR(tel),"
                       "service from employeurs where CIN LIKE'"+chaine+"%' OR nom LIKE'"+chaine+"%' OR adresse LIKE'"+chaine+"%'"
                        "OR (nom LIKE'"+chaine+"%' AND adresse LIKE'"+chaine+"%');";
        model->setQuery(select);
        }
        break;
    }
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom "));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prénom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Service"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("date de naissance"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("E-mail"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("Adresse"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("Tel"));
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
