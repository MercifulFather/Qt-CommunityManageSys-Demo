#pragma execution_character_set("utf-8")
#include "querypart.h"
#include "ui_querypart.h"

QueryPart::QueryPart(QWidget *parent, QString username, int role) :
    QWidget(parent),
    ui(new Ui::QueryPart)
{
    ui->setupUi(this);
    FlatUI::Instance()->setPushButtonQss(ui->queryButton, 5, 8, "#1ABC9C", "#E6F8F5", "#2EE1C1", "#FFFFFF", "#16A086", "#A7EEE6");
    FlatUI::Instance()->setDateEditQss(ui->payTimeEdit, 5, 2, "#DCE4EC", "#1ABC9C");


    model->setTable("pay");
    if (role == 2) {
        model->setFilter(tr("username='%1'").arg(username));
        iUsername = username;
        iRole = role;
    }
    model->select();
    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setColumnHidden(model->fieldIndex("id"), true);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

QueryPart::~QueryPart()
{
    delete ui;
}

void QueryPart::refresh()
{
    model->select();
}

void QueryPart::on_queryButton_clicked()
{
    QString type = (ui->typeComboBox->currentText().isEmpty())?"":tr("AND type = '%1'").arg(ui->typeComboBox->currentText());
    qDebug() << type;
    QString payTime = (ui->payTimeEdit->text().isEmpty())?"":tr("AND pay_time = '%1'").arg(ui->payTimeEdit->time().toString("yyyy-MM-dd"));
    qDebug() << payTime;
    if (iRole == 2) {
        model->setFilter(tr("username = %1 %2 %3").arg(iUsername).arg(type).arg(payTime));
    }
    model->setFilter(tr("1=1 %1 %2").arg(type).arg(payTime));
    model->select();
}
