#include "mainwindow.h"
#include <QMessageBox>
#include "connexion.h"
#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    connexion c;
    bool test=c.ouvrirconnexion();
    if (test){


    w.show();
    QMessageBox::information(nullptr,QObject::tr("database is open"),
                             QObject::tr("connection succesful \n"
                                         "click cancel to exit"),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("database is not open"),
                              QObject::tr("connection failed"),QMessageBox::Cancel);

    return a.exec();
}
