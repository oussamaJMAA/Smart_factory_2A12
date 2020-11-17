#include "connexion.h"


//test tuto git


connexion::connexion(){


}

bool connexion :: ouvrirconnexion(){

    bool test=false ;
    QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_projet2A");
    db.setUserName("oussama");
    db.setPassword("oussama");
    if (db.open()){
        test=true;





    }
 return test;

}
void connexion::fermerconnexion(){

    db.close();
}

