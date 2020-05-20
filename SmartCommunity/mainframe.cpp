#pragma execution_character_set("utf-8")
#include "mainframe.h"
#include "ui_mainframe.h"

MainFrame::MainFrame(QWidget *parent, QString username, int role) :
    QWidget(parent),
    ui(new Ui::MainFrame)
{
    buttonAction<< "首页" << "出勤" << "房产" << "故障报修" << "人员管理" << "业主管理" << "车位管理" << "缴费管理" << "系统设置" << "退出系统";
    ui->setupUi(this);
    initMenu();
    foreach (NavButton * btn, navButtons) {
        btn->hide();
    }
    ui->exitButton->show();
    switch (role) {
    case 0:
        pp = new PersonnelPage(this);
        sp = new SettingsPage(this);
        ap = new AttendPage(this, username, role);
        ui->stackedWidget->addWidget(pp);
        ui->stackedWidget->addWidget(sp);
        ui->stackedWidget->addWidget(ap);
        ui->stackedWidget->setCurrentWidget(pp);
        ui->personnelButton->show();
        ui->settingsButton->show();
        ui->attendButton->show();
        break;
    case 1:
        cp = new CarPage(this, username, role);
        pyp = new PayPage(this, username, role);
        rp = new RepairPage(this, username, role);
        ap = new AttendPage(this, username, role);
        op = new OwnerPage(this);
        ep = new EstatePage(this);
        ui->stackedWidget->addWidget(cp);
        ui->stackedWidget->addWidget(pyp);
        ui->stackedWidget->addWidget(rp);
        ui->stackedWidget->addWidget(ap);
        ui->stackedWidget->addWidget(op);
        ui->stackedWidget->addWidget(ep);
        ui->stackedWidget->setCurrentWidget(ap);
        ui->carButton->show();
        ui->payButton->show();
        ui->repairButton->show();
        ui->attendButton->show();
        ui->ownerButton->show();
        ui->estateButton->show();
        break;
    case 2:
        cp = new CarPage(this, username, role);
        pyp = new PayPage(this, username, role);
        rp = new RepairPage(this, username, role);
        ui->stackedWidget->addWidget(cp);
        ui->stackedWidget->addWidget(pyp);
        ui->stackedWidget->addWidget(rp);
        ui->stackedWidget->setCurrentWidget(pyp);
        ui->carButton->show();
        ui->payButton->show();
        ui->repairButton->show();
        break;
    default:
        sp = new SettingsPage(this);
        pp = new PersonnelPage(this);
        ap = new AttendPage(this, username, role);
        op = new OwnerPage(this);
        cp = new CarPage(this, username);
        pyp = new PayPage(this, username, role);
        rp = new RepairPage(this, username, role);
        ep = new EstatePage(this);
        ui->stackedWidget->addWidget(pp);
        ui->stackedWidget->addWidget(sp);
        ui->stackedWidget->addWidget(ap);
        ui->stackedWidget->addWidget(op);
        ui->stackedWidget->addWidget(cp);
        ui->stackedWidget->addWidget(pyp);
        ui->stackedWidget->addWidget(rp);
        ui->stackedWidget->addWidget(ep);
        ui->stackedWidget->setCurrentWidget(pp);
        foreach (NavButton * btn, navButtons) {
            btn->show();
        }
        break;
    }



}

MainFrame::~MainFrame()
{
    delete ui;
}

void MainFrame::initMenu()
{
    quint32 size = 15;
    quint32 pixWidth = 15;
    quint32 pixHeight = 15;

    //从图形字体获得图片,也可以从资源文件或者路径文件获取
    QChar icon = 0xf105;
    QPixmap iconNormal = IconHelper::Instance()->getPixmap(QColor(100, 100, 100).name(), icon, size, pixWidth, pixHeight);
    QPixmap iconHover = IconHelper::Instance()->getPixmap(QColor(255, 255, 255).name(), icon, size, pixWidth, pixHeight);
    QPixmap iconCheck = IconHelper::Instance()->getPixmap(QColor(255, 255, 255).name(), icon, size, pixWidth, pixHeight);

    navButtons << ui->personnelButton << ui->payButton << ui->attendButton << ui->homeButton << ui->repairButton << ui->ownerButton << ui->carButton << ui->estateButton << ui->settingsButton << ui->exitButton;
    for (int i = 0; i < navButtons.count(); i++) {
        NavButton *btn = navButtons.at(i);
        btn->setLineSpace(10);
        btn->setLineWidth(10);
        btn->setPaddingRight(25);
        btn->setShowTriangle(true);
        btn->setTextAlign(NavButton::TextAlign_Right);
        btn->setTrianglePosition(NavButton::TrianglePosition_Left);
        btn->setLinePosition(NavButton::LinePosition_Right);

        btn->setShowIcon(true);
        btn->setIconSpace(25);
        btn->setIconSize(QSize(20, 20));
        btn->setIconNormal(iconNormal);
        btn->setIconHover(iconHover);
        btn->setIconCheck(iconCheck);

        connect(btn, SIGNAL(clicked(bool)), this, SLOT(navButtons_clicked()));
    }
}

void MainFrame::navButtons_clicked()
{
    NavButton * b = (NavButton *) sender();
    switch (buttonAction.indexOf(b->text())) {
    case 0:

        break;
    case 1:
        ui->stackedWidget->setCurrentWidget(ap);
        break;
    case 2:
        ui->stackedWidget->setCurrentWidget(ep);
        break;
    case 3:
        ui->stackedWidget->setCurrentWidget(rp);
        break;
    case 4:
        ui->stackedWidget->setCurrentWidget(pp);
        break;
    case 5:
        ui->stackedWidget->setCurrentWidget(op);
        break;
    case 6:
        ui->stackedWidget->setCurrentWidget(cp);
        break;
    case 7:
        ui->stackedWidget->setCurrentWidget(pyp);
        break;
    case 8:
        ui->stackedWidget->setCurrentWidget(sp);
        break;
    case 9:
        this->close();
        qApp->exit(0);
        break;
    default:
        break;
    }
    qDebug() << "当前按下" << b->text();
    for (int i = 0; i < navButtons.count(); i++) {
        NavButton *btn = navButtons.at(i);
        btn->setChecked(b == btn);
    }
}

