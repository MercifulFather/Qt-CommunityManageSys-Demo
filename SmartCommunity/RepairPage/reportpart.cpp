#pragma execution_character_set("utf-8")
#include "reportpart.h"
#include "ui_reportpart.h"

ReportPart::ReportPart(QWidget *parent, QString username) :
    QWidget(parent),
    ui(new Ui::ReportPart)
{
    ui->setupUi(this);
    FlatUI::Instance()->setPushButtonQss(ui->saveButton, 5, 8, "#1ABC9C", "#E6F8F5", "#2EE1C1", "#FFFFFF", "#16A086", "#A7EEE6");
    FlatUI::Instance()->setLineEditQss(ui->informationEdit, 5, 2, "#DCE4EC", "#1ABC9C");

    iUsername = username;
    model->setTable("repair");
    model->select();
}

ReportPart::~ReportPart()
{
    delete ui;
}

void ReportPart::refresh()
{
    model->select();
}

void ReportPart::on_saveButton_clicked()
{
    QSqlRecord record = model->record();
    record.setValue("username", iUsername);
    record.setValue("information", ui->informationEdit->text());
    model->insertRecord(model->rowCount(), record);
    model->submitAll();
    ui->informationEdit->clear();
}
