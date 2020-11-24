#include "mainwindow.h"
#include "connection.h"
#include <QApplication>
#include "acceuil.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSplashScreen *splash=new QSplashScreen;
    QPixmap addemp("C:/Users/Nasreddine/Documents/FuseSmart/SF.png");
    splash->setPixmap(addemp);
    splash->show();
    MainWindow w;
    connection c;
    bool test=c.ouvrirconnexion();






    if(test)
        {
        QTimer::singleShot(2500,splash,SLOT (close()));
        QTimer::singleShot(2500,&w,SLOT (show()));
        //w.show();
        }
    else
        QMessageBox::information(nullptr,QObject::tr("Database is not open"),QObject::tr("echec de la connexion.\n""clic cancel"));






    return a.exec();
}
