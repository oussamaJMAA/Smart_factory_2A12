#ifndef START_H
#define START_H
#include <QDebug>
#include <QDialog>
#include <QTimer>
#include "mainwindow.h"
#include <QPixmap>

namespace Ui {
class start;
}

class start : public QDialog
{
    Q_OBJECT

public:
    explicit start(QWidget *parent = nullptr);
    ~start();
    int counter;

private slots:
    void update();

private:
    Ui::start *ui;
    MainWindow w;
     QTimer *timer = new QTimer(this);
};

#endif // START_H
