#pragma execution_character_set("utf-8")
#include "paypage.h"
#include "ui_paypage.h"

PayPage::PayPage(QWidget *parent, QString username, int role) :
    QWidget(parent),
    ui(new Ui::PayPage)
{
    ui->setupUi(this);
//    switch (role) {
//    case 0:
//        break;
//    case 1:
//        break;
//    case 2:
//        break;
//    default:
//        break;
//    }
    switch (role) {
    case 0:
        break;
    case 1:
        pyp = new PayPart(this, username, role);
        pcp = new PricePart(this);
        qp = new QueryPart(this, username, role);
        ui->tabWidget->addTab(pcp, "价格维护");
        ui->tabWidget->addTab(qp, "缴费查询");
        ui->tabWidget->addTab(pyp, "缴费");
        ui->tabWidget->setCurrentWidget(pcp);
        break;
    case 2:
        pyp = new PayPart(this, username, role);
        qp = new QueryPart(this, username, role);
        ui->tabWidget->addTab(qp, "缴费查询");
        ui->tabWidget->addTab(pyp, "缴费");
        ui->tabWidget->setCurrentWidget(qp);
        break;
    default:
        pyp = new PayPart(this, username, role);
        pcp = new PricePart(this);
        qp = new QueryPart(this, username, role);
        ui->tabWidget->addTab(pcp, "价格维护");
        ui->tabWidget->addTab(qp, "缴费查询");
        ui->tabWidget->addTab(pyp, "缴费");
        ui->tabWidget->setCurrentWidget(pcp);
        break;
    }

}

PayPage::~PayPage()
{
    delete ui;
}

void PayPage::on_tabWidget_tabBarClicked(int index)
{
    if (ui->tabWidget->widget(index)->inherits("PayPart")){
        pyp->refresh();
    }else if (ui->tabWidget->widget(index)->inherits("PricePart")) {
        pcp->refresh();
    }else if (ui->tabWidget->widget(index)->inherits("QueryPart")) {
        qp->refresh();
    }
}
