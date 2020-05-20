#pragma execution_character_set("utf-8")
#include "signpart.h"
#include "ui_signpart.h"

SignPart::SignPart(QWidget *parent, QString username) :
    QWidget(parent),
    ui(new Ui::SignPart)
{
    curUsername = username;
    ui->setupUi(this);
    FlatUI::Instance()->setPushButtonQss(ui->inButton, 5, 8, "#1ABC9C", "#E6F8F5", "#2EE1C1", "#FFFFFF", "#16A086", "#A7EEE6");
    FlatUI::Instance()->setPushButtonQss(ui->outButton, 5, 8, "#1ABC9C", "#E6F8F5", "#2EE1C1", "#FFFFFF", "#16A086", "#A7EEE6");

    date = QDate::currentDate();
    model->setTable("attendance");
    model->setFilter(tr("username ='%1' and date='%2'").arg(username).arg(date.toString("yyyy-MM-dd")));
    model->select();
    if(model->rowCount() == 0){
        ui->outButton->setEnabled(false);
        ui->inButton->setEnabled(true);
    }else {
        ui->outButton->setEnabled(true);
        ui->inButton->setEnabled(false);
    }
}

SignPart::~SignPart()
{
    delete ui;
}

void SignPart::on_inButton_clicked()
{
    QSqlRecord record = model->record();
    record.setValue("username", curUsername);
    record.setValue("date", date);
    record.setValue("signin_time", QTime::currentTime().toString());
    model->insertRecord(0, record);
    model->submitAll();
    ui->inButton->setEnabled(false);
    ui->outButton->setEnabled(true);
}

void SignPart::on_outButton_clicked()
{
    model->setFilter(tr("username ='%1' and date='%2'").arg(curUsername).arg(date.toString("yyyy-MM-dd")));
    model->select();
    qDebug() << model->rowCount();
    model->setData(model->index(0, model->fieldIndex("signout_time")), QTime::currentTime().toString());
    model->submitAll();
    ui->outButton->setEnabled(false);
}
