#pragma execution_character_set("utf-8")
#include "carmanagepart.h"
#include "ui_carmanagepart.h"

CarManagePart::CarManagePart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CarManagePart)
{
    ui->setupUi(this);
    model->setTable("parking");
    model->select();

    QSqlRecord checkRecord;
    for (int row = 0; row < model->rowCount(); row++) {
        checkRecord = model->record(row);
        if(checkRecord.value("expair_time").toString().compare(QDate::currentDate().toString("yyyy-MM-dd")) == 0 && checkRecord.value("pay_state").toString().compare("未支付") == 0){
            checkRecord.setValue("username", "");
            checkRecord.setValue("expair_time", "");
            checkRecord.setValue("pay_state", "");
            checkRecord.setValue("license", "");
            checkRecord.setValue("state", "空闲");
            model->setRecord(row, checkRecord);
        }
    }
    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setColumnHidden(model->fieldIndex("id"), true);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    FlatUI::Instance()->setPushButtonQss(ui->addButton, 5, 8, "#1ABC9C", "#E6F8F5", "#2EE1C1", "#FFFFFF", "#16A086", "#A7EEE6");
    FlatUI::Instance()->setPushButtonQss(ui->editButton, 5, 8, "#1ABC9C", "#E6F8F5", "#2EE1C1", "#FFFFFF", "#16A086", "#A7EEE6");
    FlatUI::Instance()->setPushButtonQss(ui->deleteButton, 5, 8, "#1ABC9C", "#E6F8F5", "#2EE1C1", "#FFFFFF", "#16A086", "#A7EEE6");

}

CarManagePart::~CarManagePart()
{
    delete ui;
}

void CarManagePart::query(){
    model->select();
}

void CarManagePart::on_addButton_clicked()
{
    addDialog * dialog = new addDialog(this, 0);
//    dialog->setModal(true);
    dialog->exec();
    model->select();

}

void CarManagePart::on_editButton_clicked()
{
    int selRow = ui->tableView->currentIndex().row();
    int id = model->record(selRow).value("id").toInt();
    addDialog * dialog = new addDialog(this, 1, id);
//    dialog->setModal(true);
    dialog->exec();
    model->select();
}

void CarManagePart::on_deleteButton_clicked()
{
    int delRow = ui->tableView->currentIndex().row();
    QString state = model->record(delRow).value("state").toString();
    if(state.compare("空闲") == 0){
        if(QMessageBox::Yes == QMessageBox::question(this, "删除车位", "确定要删除此车位吗？", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes)) {
            model->removeRow(delRow);
            model->submitAll();
        }
    }else{
        if(QMessageBox::Yes == QMessageBox::question(this, "删除车位", "此车位正在被使用，无法删除！", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes)) {

        }
    }
}
