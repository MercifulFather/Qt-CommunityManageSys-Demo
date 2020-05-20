#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "common.h"
#include "loginpage.h"
#include "registerpage.h"
#include "mainframe.h"

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
    void go2Register();
    void go2Login();
    void logedIn(QString, int);
private:
    Ui::MainWindow *ui;
    LoginPage * lp;
    RegisterPage * rp;
    MainFrame * mf;
    QSqlDatabase db = QSqlDatabase::database();

};
#endif // MAINWINDOW_H
