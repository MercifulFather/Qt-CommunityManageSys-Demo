#pragma execution_character_set("utf-8")
#include "myparkingpart.h"
#include "ui_myparkingpart.h"

MyParkingPart::MyParkingPart(QWidget *parent, QString username) :
    QWidget(parent),
    ui(new Ui::MyParkingPart)
{
    ui->setupUi(this);
    model->setTable("parking");
    model->setFilter(tr("username='%1'").arg(username));
    model->select();
    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setColumnHidden(model->fieldIndex("id"), true);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void MyParkingPart::query(){
    model->select();
}

MyParkingPart::~MyParkingPart()
{
    delete ui;
}
