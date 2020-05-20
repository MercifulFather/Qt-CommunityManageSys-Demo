#pragma execution_character_set("utf-8")
#include "carpage.h"
#include "ui_carpage.h"

CarPage::CarPage(QWidget *parent, QString username, int role) :
    QWidget(parent),
    ui(new Ui::CarPage)
{
    ui->setupUi(this);
    switch (role) {
    case 0:
        break;
    case 1:
        cmp = new CarManagePart(this);
        rp = new RentPart(this);
        ui->tabWidget->addTab(cmp, "车位管理");
        ui->tabWidget->addTab(rp, "车位出租");
        ui->tabWidget->setCurrentWidget(cmp);
        break;
    case 2:
        ap = new ApplyPart(this, username);
        mpp = new MyParkingPart(this, username);
        ui->tabWidget->addTab(ap, "车位申请");
        ui->tabWidget->addTab(mpp, "我的车位");
        ui->tabWidget->setCurrentWidget(mpp);
        break;
    default:
        cmp = new CarManagePart(this);
        rp = new RentPart(this);
        ap = new ApplyPart(this, username);
        mpp = new MyParkingPart(this, username);
        ui->tabWidget->addTab(cmp, "车位管理");
        ui->tabWidget->addTab(rp, "车位出租");
        ui->tabWidget->addTab(ap, "车位申请");
        ui->tabWidget->addTab(mpp, "我的车位");
        ui->tabWidget->setCurrentWidget(cmp);
        break;
    }

}

CarPage::~CarPage()
{
    delete ui;
}

void CarPage::on_tabWidget_tabBarClicked(int index)
{
    if (ui->tabWidget->widget(index)->inherits("CarManagePart")){
        cmp->query();
    }else if (ui->tabWidget->widget(index)->inherits("RentPart")) {
        rp->query();
    }else if (ui->tabWidget->widget(index)->inherits("ApplyPart")) {
        ap->query();
    }else if (ui->tabWidget->widget(index)->inherits("MyParkingPart")) {
        mpp->query();
    }
}
