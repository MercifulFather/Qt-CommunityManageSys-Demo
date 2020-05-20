#pragma execution_character_set("utf-8")
#include "attendpage.h"
#include "ui_attendpage.h"

AttendPage::AttendPage(QWidget *parent, QString username, int role) :
    QWidget(parent),
    ui(new Ui::AttendPage)
{
    ui->setupUi(this);
    switch (role) {
    case 0:
        rvp = new ReviewPart(this);
        ap = new AttendancePart(this);
        ui->tabWidget->addTab(rvp, "请假审批");
        ui->tabWidget->addTab(ap, "月度出勤");
        ui->tabWidget->setCurrentWidget(rvp);
        break;
    case 1:
        ap = new AttendancePart(this);
        rqp = new RequestPart(this, username, role);
        sp = new SignPart(this, username);
        ui->tabWidget->addTab(ap, "月度出勤");
        ui->tabWidget->addTab(rqp, "请销假");
        ui->tabWidget->addTab(sp, "出勤");
        ui->tabWidget->setCurrentWidget(sp);
        break;
    case 2:
        break;
    default:
        ap = new AttendancePart(this);
        rvp = new ReviewPart(this);
        rqp = new RequestPart(this, username, role);
        sp = new SignPart(this, username);
        ui->tabWidget->addTab(ap, "月度出勤");
        ui->tabWidget->addTab(rqp, "请销假");
        ui->tabWidget->addTab(rvp, "请假审批");
        ui->tabWidget->addTab(sp, "出勤");
        ui->tabWidget->setCurrentWidget(sp);
        break;
    }
}

AttendPage::~AttendPage()
{
    delete ui;
}

void AttendPage::on_tabWidget_tabBarClicked(int index)
{
    if (ui->tabWidget->widget(index)->inherits("AttendancePart")){
        ap->update();
    }else if (ui->tabWidget->widget(index)->inherits("RequestPart")) {
        rqp->update();
    }else if (ui->tabWidget->widget(index)->inherits("ReviewPart")) {
        rvp->update();
    }
}
