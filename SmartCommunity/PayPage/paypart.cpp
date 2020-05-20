#pragma execution_character_set("utf-8")
#include "paypart.h"
#include "ui_paypart.h"

PayPart::PayPart(QWidget *parent, QString username, int role) :
    QWidget(parent),
    ui(new Ui::PayPart)
{
    ui->setupUi(this);

    FlatUI::Instance()->setPushButtonQss(ui->payButton, 5, 8, "#1ABC9C", "#E6F8F5", "#2EE1C1", "#FFFFFF", "#16A086", "#A7EEE6");
    FlatUI::Instance()->setLineEditQss(ui->quantityEdit, 5, 2, "#DCE4EC", "#1ABC9C");
    FlatUI::Instance()->setLineEditQss(ui->usernameEdit, 5, 2, "#DCE4EC", "#1ABC9C");

    QIntValidator * validator = new QIntValidator;
    ui->quantityEdit->setValidator(validator);

    model->setTable("pay");
    model->select();

    if (role == 2) {
        ui->usernameEdit->setText(username);
        ui->usernameEdit->setEnabled(false);
    }
}

PayPart::~PayPart()
{
    delete ui;
}

void PayPart::refresh()
{
    model->select();
}

void PayPart::on_payButton_clicked()
{
    QSqlRecord record = model->record();
    record.setValue("pay_date", QDate::currentDate().toString("yyyy-MM-dd"));
    record.setValue("type", ui->typeComboBox->currentText());
    record.setValue("username", ui->usernameEdit->text());
    record.setValue("quantity", ui->quantityEdit->text());
    model->insertRecord(model->rowCount(), record);
    model->submitAll();
    ui->quantityEdit->clear();
}
