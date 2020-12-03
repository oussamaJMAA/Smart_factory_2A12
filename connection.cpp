#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("source_Projet2A");
db.setUserName("ahmed");
db.setPassword("ahmed");

if (db.open())
test=true;





    return  test;
}
