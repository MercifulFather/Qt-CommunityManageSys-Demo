#pragma execution_character_set("utf-8")
#include "pricepart.h"
#include "ui_pricepart.h"

PricePart::PricePart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PricePart)
{
    ui->setupUi(this);
    FlatUI::Instance()->setPushButtonQss(ui->saveButton, 5, 8, "#1ABC9C", "#E6F8F5", "#2EE1C1", "#FFFFFF", "#16A086", "#A7EEE6");
    FlatUI::Instance()->setLineEditQss(ui->unitEdit, 5, 2, "#DCE4EC", "#1ABC9C");
    FlatUI::Instance()->setLineEditQss(ui->amountEdit, 5, 2, "#DCE4EC", "#1ABC9C");


    model->setTable("price");
    QDoubleValidator * validator = new QDoubleValidator;
    ui->amountEdit->setValidator(validator);
}

PricePart::~PricePart()
{
    delete ui;
}

void PricePart::refresh()
{
    model->select();
}

void PricePart::on_saveButton_clicked()
{
    model->setFilter(tr("type='%1'").arg(ui->typeComboBox->currentText()));
    model->select();
    if (model->rowCount() != 0) {
        QSqlRecord record = model->record(0);
        record.setValue("unit", ui->unitEdit->text());
        record.setValue("amount", ui->amountEdit->text());
        model->setRecord(0, record);
        model->submitAll();
    }
}
