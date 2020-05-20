#pragma execution_character_set("utf-8")
#include "queryrepairpart.h"
#include "ui_queryrepairpart.h"

QueryRepairPart::QueryRepairPart(QWidget *parent, QString username, int role) :
    QWidget(parent),
    ui(new Ui::QueryRepairPart)
{
    ui->setupUi(this);
    FlatUI::Instance()->setPushButtonQss(ui->contentButton, 5, 8, "#1ABC9C", "#E6F8F5", "#2EE1C1", "#FFFFFF", "#16A086", "#A7EEE6");
    FlatUI::Instance()->setPushButtonQss(ui->processButton, 5, 8, "#1ABC9C", "#E6F8F5", "#2EE1C1", "#FFFFFF", "#16A086", "#A7EEE6");

    model->setTable("repair");
    if (role == 2) {
        model->setFilter(tr("username = '%1'").arg(username));
        ui->processButton->hide();
    } else {
        ui->contentButton->hide();
    }
    model->select();
    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setColumnHidden(model->fieldIndex("id"), true);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

QueryRepairPart::~QueryRepairPart()
{
    delete ui;
}

void QueryRepairPart::refresh()
{
    model->select();
}

void QueryRepairPart::on_contentButton_clicked()
{
    int selRow = ui->tableView->currentIndex().row();
    if (selRow >= 0) {
        int id = model->record(selRow).value("id").toInt();
        ContentDialog * dialog = new ContentDialog(this, id);
        dialog->exec();
        model->select();
    }
}

void QueryRepairPart::on_processButton_clicked()
{
    int selRow = ui->tableView->currentIndex().row();
    if (selRow >= 0) {
        int id = model->record(selRow).value("id").toInt();
        ProcessDialog * dialog = new ProcessDialog(this, id);
        dialog->exec();
        model->select();
    }
}
