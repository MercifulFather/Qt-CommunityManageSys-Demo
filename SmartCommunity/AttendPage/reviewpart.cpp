#pragma execution_character_set("utf-8")
#include "reviewpart.h"
#include "ui_reviewpart.h"

ReviewPart::ReviewPart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReviewPart)
{
    ui->setupUi(this);
    FlatUI::Instance()->setPushButtonQss(ui->acceptButton, 5, 8, "#1ABC9C", "#E6F8F5", "#2EE1C1", "#FFFFFF", "#16A086", "#A7EEE6");
    FlatUI::Instance()->setPushButtonQss(ui->rejectButton, 5, 8, "#1ABC9C", "#E6F8F5", "#2EE1C1", "#FFFFFF", "#16A086", "#A7EEE6");

    init();
}

void ReviewPart::init()
{
    model->setTable("leave");
    model->setFilter("state='待审批'");
    model->select();

    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setColumnHidden(model->fieldIndex("id"), true);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void ReviewPart::update()
{
    init();
    QWidget::update();
}

ReviewPart::~ReviewPart()
{
    delete ui;
}

void ReviewPart::on_rejectButton_clicked()
{
    int rejRow = ui->tableView->currentIndex().row();
    model->setData(model->index(rejRow, model->fieldIndex("state")), "待销假");
    model->submitAll();
}

void ReviewPart::on_acceptButton_clicked()
{
    int rejRow = ui->tableView->currentIndex().row();
    model->setData(model->index(rejRow, model->fieldIndex("state")), "已拒绝");
    model->submitAll();
}
