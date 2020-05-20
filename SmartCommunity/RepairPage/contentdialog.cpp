#pragma execution_character_set("utf-8")
#include "contentdialog.h"
#include "ui_contentdialog.h"

ContentDialog::ContentDialog(QWidget *parent, int id) :
    QDialog(parent),
    ui(new Ui::ContentDialog)
{
    ui->setupUi(this);
    FlatUI::Instance()->setTextEditQss(ui->contentEdit, 5, 2, "#DCE4EC", "#1ABC9C");
    model->setTable("repair");
    model->setFilter(tr("id = %1").arg(id));
    model->select();
}

ContentDialog::~ContentDialog()
{
    delete ui;
}

void ContentDialog::on_buttonBox_accepted()
{
    QSqlRecord record = model->record(0);
    record.setValue("content", ui->contentEdit->toPlainText());
    model->setRecord(0, record);
    model->submitAll();
}

void ContentDialog::on_buttonBox_rejected()
{
    this->close();
}
