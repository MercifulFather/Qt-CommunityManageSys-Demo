#pragma execution_character_set("utf-8")
#include "staffmanagepart.h"
#include "ui_staffmanagepart.h"

StaffManagePart::StaffManagePart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StaffManagePart)
{
    ui->setupUi(this);
    FlatUI::Instance()->setPushButtonQss(ui->addButton, 5, 8, "#1ABC9C", "#E6F8F5", "#2EE1C1", "#FFFFFF", "#16A086", "#A7EEE6");
    FlatUI::Instance()->setPushButtonQss(ui->deleteButton, 5, 8, "#1ABC9C", "#E6F8F5", "#2EE1C1", "#FFFFFF", "#16A086", "#A7EEE6");
    FlatUI::Instance()->setPushButtonQss(ui->revertButton, 5, 8, "#1ABC9C", "#E6F8F5", "#2EE1C1", "#FFFFFF", "#16A086", "#A7EEE6");
    FlatUI::Instance()->setPushButtonQss(ui->editButton, 5, 8, "#1ABC9C", "#E6F8F5", "#2EE1C1", "#FFFFFF", "#16A086", "#A7EEE6");
    FlatUI::Instance()->setPushButtonQss(ui->submitButton, 5, 8, "#1ABC9C", "#E6F8F5", "#2EE1C1", "#FFFFFF", "#16A086", "#A7EEE6");

    model->setTable("user");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->setFilter("role= 1");
    model->select();
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    /*
     * Interactive,
        Stretch,
        Fixed,
        ResizeToContents,
        Custom = Fixed
     */
    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setColumnHidden(model->fieldIndex("id"), true);
    ui->tableView->setColumnHidden(model->fieldIndex("role"), true);
}

StaffManagePart::~StaffManagePart()
{
    delete ui;
}

void StaffManagePart::on_addButton_clicked()
{
    ui->tableView->setEditTriggers(QAbstractItemView::DoubleClicked);
    int newRow = model->rowCount();
    model->insertRow(newRow);
    model->setData(model->index(newRow, model->fieldIndex("role")), 1);
}

void StaffManagePart::on_submitButton_clicked()
{

    model->database().transaction(); //开始事务操作
    if (model->submitAll()) {
        model->database().commit(); //提交
    } else {
        model->database().rollback(); //回滚
        qDebug() << "提交失败";
    }
    foreach (int row, delRows) {
        ui->tableView->setRowHidden(row, false);
    }
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
//        QMessageBox::warning(this, tr(“tableModel”),
//                             tr(“数据库错误: %1″)
//                             .arg(model->lastError().text()));
}

void StaffManagePart::on_deleteButton_clicked()
{
    if(QMessageBox::Yes == QMessageBox::question(this, "删除工作人员", "确定要删除此人吗？", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes)) {
        int delRow = ui->tableView->currentIndex().row();
        delRows.append(delRow);
        ui->tableView->setRowHidden(delRow, true);
        model->removeRow(delRow);
        model->submitAll();
    } else {
//        model->revertAll();
    }
}

void StaffManagePart::on_editButton_clicked()
{
    ui->tableView->setEditTriggers(QAbstractItemView::DoubleClicked);
    ui->editButton->setText("请在表格中修改");
}

void StaffManagePart::on_revertButton_clicked()
{
    model->revertAll();
    foreach (int row, delRows) {
        ui->tableView->setRowHidden(row, false);
    }
}
