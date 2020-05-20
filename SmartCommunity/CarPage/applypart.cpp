#pragma execution_character_set("utf-8")
#include "applypart.h"
#include "ui_applypart.h"

ApplyPart::ApplyPart(QWidget *parent, QString username) :
    QWidget(parent),
    ui(new Ui::ApplyPart)
{
    iUsername = username;
    ui->setupUi(this);
    FlatUI::Instance()->setPushButtonQss(ui->saveButton, 5, 8, "#1ABC9C", "#E6F8F5", "#2EE1C1", "#FFFFFF", "#16A086", "#A7EEE6");
    FlatUI::Instance()->setLineEditQss(ui->licenseEdit, 5, 2, "#DCE4EC", "#1ABC9C");
    model->setTable("queue");
    model->select();
}

ApplyPart::~ApplyPart()
{
    delete ui;
}

void ApplyPart::query(){
    model->select();
}


void ApplyPart::on_saveButton_clicked()
{
    QSqlRecord record = model->record();
    record.setValue("username", iUsername);
    record.setValue("license", ui->licenseEdit->text());
    record.setValue("size", ui->sizeGroup->button(ui->sizeGroup->checkedId())->text());
    record.setValue("chargeable", ui->checkBox->isTristate()?"是":"否");
    model->insertRecord(model->rowCount(), record);
    model->submitAll();
    ui->licenseEdit->clear();
}
