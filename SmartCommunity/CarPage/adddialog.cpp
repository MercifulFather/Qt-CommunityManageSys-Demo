#pragma execution_character_set("utf-8")
#include "adddialog.h"
#include "ui_adddialog.h"

addDialog::addDialog(QWidget *parent, int type, int id) :
    QDialog(parent),
    ui(new Ui::addDialog)
{
    ui->setupUi(this);
    model->setTable("parking");
//    ui->typeGroup->setId(ui->groundRadioButton, 0);
//    ui->typeGroup->setId(ui->buildingRadioButton, 1);
//    ui->sizeGroup->setId(ui->bigRadioButton, 0);
//    ui->sizeGroup->setId(ui->smallRadioButton, 1);
    if(type == 1){
        iType = type;
        iId = id;
        model->setFilter(tr("id = %1").arg(id));
        model->select();
        QSqlRecord record = model->record(0);
        ui->positionEdit->setText(record.value("position").toString());
        ui->typeGroup->button((record.value("type").toString().compare("地上") == 0)?0:1)->click();
        ui->sizeGroup->button((record.value("size").toString().compare("大") == 0)?0:1)->click();
        ui->chargeableCheckBox->setTristate((record.value("chargeable").toString().compare("是") == 0)?true:false);
    }

    FlatUI::Instance()->setLineEditQss(ui->positionEdit, 5, 2, "#DCE4EC", "#1ABC9C");

}

addDialog::~addDialog()
{
    delete ui;
}

void addDialog::on_buttonBox_accepted()
{
    QSqlRecord record = model->record();
    record.setValue("position", ui->positionEdit->text());
    record.setValue("type", ui->typeGroup->button(ui->typeGroup->checkedId())->text());
    record.setValue("chargeable", ui->chargeableCheckBox->isTristate()?"是":"否");
    record.setValue("size", ui->sizeGroup->button(ui->sizeGroup->checkedId())->text());
    if(iType == 1){
        model->setRecord(0, record);
    }else{
        record.setValue("state", "空闲");
        model->insertRecord(model->rowCount(), record);
    }
    model->submitAll();
}

void addDialog::on_buttonBox_rejected()
{
    this->close();
}
