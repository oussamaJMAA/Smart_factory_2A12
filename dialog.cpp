#include "dialog.h"
#include "ui_dialog.h"
#include <QApplication>


QT_CHARTS_USE_NAMESPACE
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
QApplication a(int argc,char *argv[]);
QPieSeries *series1 = new QPieSeries();
series1->setName("Materiaux Restante");
series1->append("Quantite Materiaux",10);
/*
QPieSeries *series2 = new QPieSeries();
series2->setName("Renewables");
series2->append("quantite", 77);
*/

QPieSeries *series3 = new QPieSeries();
series3->setName("Others");
series3->append("quantite restante",10 );

//![1]

//![2]
DonutBreakdownChart *donutBreakdown = new DonutBreakdownChart();
donutBreakdown->setAnimationOptions(QChart::AllAnimations);
donutBreakdown->setTitle("Materiaux");
donutBreakdown->legend()->setAlignment(Qt::AlignRight);
donutBreakdown->addBreakdownSeries(series1, Qt::red);
//donutBreakdown->addBreakdownSeries(series2, Qt::darkGreen);
donutBreakdown->addBreakdownSeries(series3, Qt::darkBlue);
//![2]

//![3]
QMainWindow window;
QChartView *chartView = new QChartView(donutBreakdown);
chartView->setRenderHint(QPainter::Antialiasing);
window.setCentralWidget(chartView);
window.resize(800, 500);
window.show();
}

Dialog::~Dialog()
{
    delete ui;
}
