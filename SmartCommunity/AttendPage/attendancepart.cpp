#pragma execution_character_set("utf-8")
#include "attendancepart.h"
#include "ui_attendancepart.h"

AttendancePart::AttendancePart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AttendancePart)
{
    ui->setupUi(this);
    model->setTable("user");
    model->setFilter("role in (0,1)");
    model->select();
    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setColumnHidden(model->fieldIndex("id"), true);
    ui->tableView->setColumnHidden(model->fieldIndex("password"), true);
    ui->tableView->setColumnHidden(model->fieldIndex("role"), true);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->cancelButton->setEnabled(false);

    FlatUI::Instance()->setPushButtonQss(ui->cancelButton, 5, 8, "#1ABC9C", "#E6F8F5", "#2EE1C1", "#FFFFFF", "#16A086", "#A7EEE6");
    FlatUI::Instance()->setPushButtonQss(ui->attendButton, 5, 8, "#1ABC9C", "#E6F8F5", "#2EE1C1", "#FFFFFF", "#16A086", "#A7EEE6");
    FlatUI::Instance()->setPushButtonQss(ui->leaveButton, 5, 8, "#1ABC9C", "#E6F8F5", "#2EE1C1", "#FFFFFF", "#16A086", "#A7EEE6");

}

AttendancePart::~AttendancePart()
{
    delete ui;
}

void AttendancePart::update()
{
    model->select();
    QWidget::update();
}

void AttendancePart::on_leaveButton_clicked()
{
    int selRow = ui->tableView->currentIndex().row();
    QString username = model->record(selRow).value("username").toString();
    qDebug() << selRow;
    qDebug() << model->index(selRow, model->fieldIndex("username")).data().toString();
    qDebug() << model->record(selRow).value("username").toString();
    qDebug() << model->itemData(model->index(selRow, model->fieldIndex("username")))[0].toString();
    model->setTable("leave");
    model->setFilter(tr("username= '%1'").arg(username));
    model->select();
    ui->cancelButton->setEnabled(true);
    ui->leaveButton->setEnabled(false);
    ui->attendButton->setEnabled(false);
    ui->tableView->setColumnHidden(model->fieldIndex("id"), true);
}

void AttendancePart::on_attendButton_clicked()
{
    int selRow = ui->tableView->currentIndex().row();
    QString username = model->record(selRow).value("username").toString();
    qDebug() << selRow;
    qDebug() << model->index(selRow, model->fieldIndex("username")).data().toString();
    qDebug() << model->record(selRow).value("username").toString();
    qDebug() << model->itemData(model->index(selRow, model->fieldIndex("username")))[0].toString();
    model->setTable("attendance");
    model->setFilter(tr("username= '%1'").arg(username));
    model->select();
    ui->cancelButton->setEnabled(true);
    ui->leaveButton->setEnabled(false);
    ui->attendButton->setEnabled(false);
    ui->tableView->setColumnHidden(model->fieldIndex("id"), true);
}

void AttendancePart::on_cancelButton_clicked()
{
    ui->cancelButton->setEnabled(false);
    ui->leaveButton->setEnabled(true);
    ui->attendButton->setEnabled(true);
    model->setTable("user");
    model->setFilter("role in (0,1)");
    model->select();
    ui->tableView->setColumnHidden(model->fieldIndex("id"), true);
    ui->tableView->setColumnHidden(model->fieldIndex("password"), true);
    ui->tableView->setColumnHidden(model->fieldIndex("role"), true);
}
