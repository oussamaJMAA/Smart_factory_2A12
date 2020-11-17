#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "acceuil.h"
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

private:
    Ui::MainWindow *ui;
    QString username="",password="";
    QMediaPlayer *musicLogin= new QMediaPlayer;


};
#endif // MAINWINDOW_H
