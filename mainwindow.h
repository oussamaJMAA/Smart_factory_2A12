#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <connection.h>
#include <QMessageBox>
#include <QMediaPlayer>
#include <QString>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QtSql>
#include <QSplashScreen>
#include <QTimer>

#include "employeurs.h"
#include "acceuil.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void GetLogin();
    void GetMusic();
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_exit_clicked();

private:
    Ui::MainWindow *ui;
    QString username="",password="";
    QMediaPlayer *musicLogin= new QMediaPlayer;
    employeurs e;
    connection c;
};
#endif // MAINWINDOW_H
