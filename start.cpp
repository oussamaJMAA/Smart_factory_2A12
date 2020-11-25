#include "start.h"
#include "ui_start.h"

start::start(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::start)
{   counter=0;

    ui->setupUi(this);

    QPixmap FS("C:/Users/Nasreddine/Documents/FuseSmart/FS.png");
    ui->label->setPixmap(FS);


       connect(timer, SIGNAL(timeout()),this, SLOT(update()));
       timer->start(35);

}

start::~start()
{
    delete ui;
}


void start::update()
{   counter++;
    ui->progressBar->setValue(counter);
    //qDebug()<<"update";
    if(counter==100)
    {this->hide();
        timer->stop();
        w.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
        w.show();


    }

}
