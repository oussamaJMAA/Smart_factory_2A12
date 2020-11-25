#include "mainwindow.h"
#include "connection.h"
#include <QApplication>
#include "acceuil.h"
#include "start.h"
#include<QGraphicsDropShadowEffect>
#include <QTimer>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSplashScreen *splash=new QSplashScreen;
    //QPixmap addemp("C:/Users/Nasreddine/Documents/FuseSmart/SF.png");
    //splash->setPixmap(addemp);
    //splash->show();
    MainWindow w;
    connection c;
    bool test=c.ouvrirconnexion();

     start star;
     star.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
     QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect;
     effect->setBlurRadius(20);
     effect->setXOffset(0);
     effect->setYOffset(0);
     effect->setColor(QColor(0,0,0,60));
     star.setGraphicsEffect(effect);

    if(test)
        {
           star.show();
            //QTimer::singleShot(2500,splash,SLOT (close()));
            //QTimer::singleShot(2500,&w,SLOT (show()));
            //w.show();
        }
    else
        QMessageBox::information(nullptr,QObject::tr("Database is not open"),QObject::tr("echec de la connexion.\n""clic cancel"));

c.fermerconnexion();
    return a.exec();
}
