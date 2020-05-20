#pragma execution_character_set("utf-8")
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "common.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // 主窗口
    ui->setupUi(this);
    // 数据库
//    qDebug() << db.isOpen();
    // 初始化页面
    lp = new LoginPage(this);
    rp = new RegisterPage(this);

    // 信号连接
    connect(lp, SIGNAL(showRegisterPage()), this, SLOT(go2Register()));
    connect(rp, SIGNAL(showLoginPage()), this, SLOT(go2Login()));
    connect(lp, SIGNAL(login(QString, int)), this, SLOT(logedIn(QString, int)));
    // 初始化程序
    ui->stackedWidget->addWidget(lp);
    ui->stackedWidget->addWidget(rp);
    ui->stackedWidget->setCurrentWidget(lp);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::go2Register()
{
    ui->stackedWidget->setCurrentWidget(rp);
}
void MainWindow::go2Login()
{
    ui->stackedWidget->setCurrentWidget(lp);
}
void MainWindow::logedIn(QString iusername, int irole)
{
    mf = new MainFrame(this, iusername, irole);
    ui->stackedWidget->addWidget(mf);
    ui->stackedWidget->setCurrentWidget(mf);
    ui->stackedWidget->removeWidget(lp);
    ui->stackedWidget->removeWidget(rp);
    delete lp;
    delete rp;
}
