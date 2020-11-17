#include "mainwindow.h"
#include <QApplication>
#include "connection.h"
#include "QDebug"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
        //connection co;
       // bool test = co.CreateConnection();
      //if (test)
           // qDebug() <<"connection succes";
    w.show();
     // else
          // qDebug() <<"error";

    return a.exec();
}
