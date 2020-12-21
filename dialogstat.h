#ifndef DIALOGSTAT_H
#define DIALOGSTAT_H

#include <QDialog>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtCharts/QChartView>
#include "donutbreakdownchart.h"
namespace Ui {
class Dialogstat;
}

class Dialogstat : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogstat(QWidget *parent = nullptr);
    ~Dialogstat();

private:
    Ui::Dialogstat *ui;
};

#endif // DIALOGSTAT_H
