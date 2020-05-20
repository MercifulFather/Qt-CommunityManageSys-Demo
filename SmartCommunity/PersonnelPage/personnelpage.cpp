#pragma execution_character_set("utf-8")
#include "personnelpage.h"
#include "ui_personnelpage.h"

PersonnelPage::PersonnelPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PersonnelPage)
{
    ui->setupUi(this);
    smp = new StaffManagePart(this);
    ui->tabWidget->addTab(smp, "物业工作人员维护");
    ui->tabWidget->setCurrentWidget(smp);
}

PersonnelPage::~PersonnelPage()
{
    delete ui;
}
