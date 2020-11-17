/* #include "connection.h"
#include "QSqlDatabase"
connection::connection()
{

}

bool connection::CreateConnection()
{
    bool test = false;
    QSqlDatabase db =  QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("projet 2A");
    db.setUserName("moueffek");
    db.setPassword("moueffek");

     if(db.open())
     test=true;

     return test;

} */
