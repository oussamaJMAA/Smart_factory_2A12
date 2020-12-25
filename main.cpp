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
    //QSplashScreen *splash=new QSplashScreen;
    //QPixmap addemp("C:/Users/Nasreddine/Documents/FuseSmart/SF.png");
    //splash->setPixmap(addemp);
    //splash->show();


     start star;
     star.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
 /*  QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect;
     effect->setBlurRadius(40);
     effect->setXOffset(0);
     effect->setYOffset(0);
     effect->setColor(QColor(0,0,0,60));
     star.setGraphicsEffect(effect);
 */

           star.show();
            //QTimer::singleShot(2500,splash,SLOT (close()));
            //QTimer::singleShot(2500,&w,SLOT (show()));
            //w.show();

    return a.exec();
}
