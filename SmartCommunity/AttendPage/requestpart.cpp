#pragma execution_character_set("utf-8")
#include "requestpart.h"
#include "ui_requestpart.h"

RequestPart::RequestPart(QWidget *parent, QString username, int role) :
    QWidget(parent),
    ui(new Ui::RequestPart)
{
    curUsername = username;
    curRole = role;
    ui->setupUi(this);
    FlatUI::Instance()->setPushButtonQss(ui->finishButton, 5, 8, "#1ABC9C", "#E6F8F5", "#2EE1C1", "#FFFFFF", "#16A086", "#A7EEE6");
    FlatUI::Instance()->setPushButtonQss(ui->createButton, 5, 8, "#1ABC9C", "#E6F8F5", "#2EE1C1", "#FFFFFF", "#16A086", "#A7EEE6");
    FlatUI::Instance()->setTextEditQss(ui->reasonEdit, 5, 2, "#DCE4EC", "#1ABC9C");
    FlatUI::Instance()->setDateEditQss(ui->startTimeEdit, 5, 2, "#DCE4EC", "#1ABC9C");
    FlatUI::Instance()->setDateEditQss(ui->endTimeEdit, 5, 2, "#DCE4EC", "#1ABC9C");
    FlatUI::Instance()->setDateEditQss(ui->actualEndTimeEdit, 5, 2, "#DCE4EC", "#1ABC9C");

    init();
}

void RequestPart::init()
{
    model->setTable("leave");
    model->setFilter(tr("state='待销假' and username='%1'").arg(curUsername));
    model->select();

    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setColumnHidden(model->fieldIndex("id"), true);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

RequestPart::~RequestPart()
{
    delete ui;
}

void RequestPart::on_createButton_clicked()
{
    QSqlRecord record = model->record();
    record.setValue("username", curUsername);
    record.setValue("reason", ui->reasonEdit->toPlainText());
    record.setValue("start_time", ui->startTimeEdit->date().toString());
    record.setValue("end_time", ui->endTimeEdit->date().toString());
    record.setValue("state", "待审批");
    model->insertRecord(model->rowCount(), record);
    model->submitAll();
    ui->reasonEdit->clear();
    ui->startTimeEdit->setDate(QDate(2020, 1, 1));
    ui->endTimeEdit->setDate(QDate(2020, 1, 1));
}

void RequestPart::on_finishButton_clicked()
{
    int finRow = ui->tableView->currentIndex().row();
    model->setData(model->index(finRow, model->fieldIndex("state")), "已销假");
    model->setData(model->index(finRow, model->fieldIndex("end_time")), ui->actualEndTimeEdit->date().toString());
    model->submitAll();
}

void RequestPart::update()
{
    init();
    QWidget::update();
}
