#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QObject>
#include <QMainWindow>
#include<QPropertyAnimation>
#include <QString>
#include <QDoubleValidator>
#include <QMediaPlayer>
#include <QDebug>
#include <materiaux.h>
#include <fournisseurs.h>

#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtCharts/QChartView>
#include "donutbreakdownchart.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();




private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_modifier_2_clicked();

    void on_pushButton_10_clicked();

    void on_supprimer_2_clicked();

    void on_pushButton_15_clicked();

    void on_quitter_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_20_clicked();

    void on_quitter_3_clicked();

    void on_modifier_3_clicked();

    void on_pushButton_25_clicked();

    void on_supprimer_3_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_4_clicked();



    void on_retour_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_22_clicked();



    void on_pushButton_29_clicked();

    void on_pushButton_26_clicked();

    void on_supprimer_4_clicked();

    void on_trier_clicked();




    void on_tableView_2_activated(const QModelIndex &index);

    void on_tableView_activated(const QModelIndex &index);



 //   void on_rechercher_ref_textEdited(const QString &arg1);

    void on_rechercher_ref_cursorPositionChanged();

    void on_rechercher_id_cursorPositionChanged();



    void on_tableView_3_activated(const QModelIndex &index);

    void on_pushButton_23_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_30_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
      QPropertyAnimation *animation;
      QPropertyAnimation *animation1;
      QPropertyAnimation *animation2;
 QMediaPlayer *musicConect=new QMediaPlayer;
 materiaux Etmp;
 fournisseurs Etmp1;

};
#endif // MAINWINDOW_H
