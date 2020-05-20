#pragma execution_character_set("utf-8")
#include "rentpart.h"
#include "ui_rentpart.h"

RentPart::RentPart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RentPart)
{
    ui->setupUi(this);
    queueModel->setTable("queue");
    queueModel->select();
    ui->queueTable->setModel(queueModel);
    ui->queueTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->queueTable->setColumnHidden(queueModel->fieldIndex("id"), true);
    ui->queueTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    parkingModel->setTable("parking");
    parkingModel->setFilter("state='空闲'");
    parkingModel->select();
    ui->parkingTable->setModel(parkingModel);
    ui->parkingTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->parkingTable->setColumnHidden(parkingModel->fieldIndex("id"), true);
    ui->parkingTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    FlatUI::Instance()->setPushButtonQss(ui->rentButton, 5, 8, "#1ABC9C", "#E6F8F5", "#2EE1C1", "#FFFFFF", "#16A086", "#A7EEE6");
}

RentPart::~RentPart()
{
    delete ui;
}

void RentPart::query(){
    parkingModel->select();
    queueModel->select();
}


void RentPart::on_rentButton_clicked()
{
    int selUsername = (ui->queueTable->currentIndex().row() == -1)?0:ui->queueTable->currentIndex().row();
    if(ui->parkingTable->currentIndex().row() != -1){
        int selParking = ui->parkingTable->currentIndex().row();
        QString username = queueModel->record(selUsername).value("username").toString();
        QSqlRecord record = parkingModel->record(selParking);
        record.setValue("username", username);
        record.setValue("pay_state", "未支付");
        record.setValue("state", "使用中");
        record.setValue("expair_time", QDate::currentDate().addDays(3).toString());
        parkingModel->setRecord(selParking, record);
        parkingModel->submitAll();
        parkingModel->select();
        queueModel->removeRow(selUsername);
        queueModel->submitAll();
        queueModel->select();
    }
}
