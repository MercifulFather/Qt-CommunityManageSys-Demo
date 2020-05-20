#pragma execution_character_set("utf-8")
#include "repairpage.h"
#include "ui_repairpage.h"

RepairPage::RepairPage(QWidget *parent, QString username, int role) :
    QWidget(parent),
    ui(new Ui::RepairPage)
{
    ui->setupUi(this);
    switch (role) {
    case 0:
        break;
    case 1:
        qrp = new QueryRepairPart(this, username, role);
        ui->tabWidget->addTab(qrp, "维修进度查询与修改");
        ui->tabWidget->setCurrentWidget(qrp);
        break;
    case 2:
        rp = new ReportPart(this, username);
        qrp = new QueryRepairPart(this, username, role);
        ui->tabWidget->addTab(rp, "报修");
        ui->tabWidget->addTab(qrp, "维修进度查询与修改");
        ui->tabWidget->setCurrentWidget(rp);
        break;
    default:
        rp = new ReportPart(this, username);
        qrp = new QueryRepairPart(this, username, role);
        ui->tabWidget->addTab(rp, "报修");
        ui->tabWidget->addTab(qrp, "维修进度查询与修改");
        ui->tabWidget->setCurrentWidget(qrp);
        break;
    }

}

RepairPage::~RepairPage()
{
    delete ui;
}

void RepairPage::on_tabWidget_tabBarClicked(int index)
{
    if (ui->tabWidget->widget(index)->inherits("ReportPart")){
        rp->refresh();
    }else if (ui->tabWidget->widget(index)->inherits("QueryRepairPart")) {
        qrp->refresh();
    }
}
