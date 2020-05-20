#pragma execution_character_set("utf-8")
#include "processdialog.h"
#include "ui_processdialog.h"

ProcessDialog::ProcessDialog(QWidget *parent, int id) :
    QDialog(parent),
    ui(new Ui::ProcessDialog)
{
    ui->setupUi(this);
    FlatUI::Instance()->setLineEditQss(ui->resultEdit, 5, 2, "#DCE4EC", "#1ABC9C");

    model->setTable("repair");
    model->setFilter(tr("id = %1").arg(id));
    model->select();
}

ProcessDialog::~ProcessDialog()
{
    delete ui;
}

void ProcessDialog::on_buttonBox_accepted()
{
    QSqlRecord record = model->record(0);
    record.setValue("state", ui->stateComboBox->currentText());
    record.setValue("result", ui->resultEdit->text());
    model->setRecord(0, record);
    model->submitAll();
}

void ProcessDialog::on_buttonBox_rejected()
{
    this->close();
}
