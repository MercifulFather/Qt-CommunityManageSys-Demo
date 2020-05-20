#pragma execution_character_set("utf-8")
#include "ownerpage.h"
#include "ui_ownerpage.h"

OwnerPage::OwnerPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OwnerPage)
{
    ui->setupUi(this);
    FlatUI::Instance()->setPushButtonQss(ui->submitButton, 5, 8, "#1ABC9C", "#E6F8F5", "#2EE1C1", "#FFFFFF", "#16A086", "#A7EEE6");
    FlatUI::Instance()->setPushButtonQss(ui->editButton, 5, 8, "#1ABC9C", "#E6F8F5", "#2EE1C1", "#FFFFFF", "#16A086", "#A7EEE6");
    FlatUI::Instance()->setPushButtonQss(ui->addButton, 5, 8, "#1ABC9C", "#E6F8F5", "#2EE1C1", "#FFFFFF", "#16A086", "#A7EEE6");
    FlatUI::Instance()->setPushButtonQss(ui->queryButton, 5, 8, "#1ABC9C", "#E6F8F5", "#2EE1C1", "#FFFFFF", "#16A086", "#A7EEE6");
    FlatUI::Instance()->setTextEditQss(ui->addressEdit, 5, 2, "#DCE4EC", "#1ABC9C");
    FlatUI::Instance()->setLineEditQss(ui->usernameEdit, 5, 2, "#DCE4EC", "#1ABC9C");
    FlatUI::Instance()->setLineEditQss(ui->phoneEdit, 5, 2, "#DCE4EC", "#1ABC9C");

    QIntValidator * validator = new QIntValidator;
    ui->phoneEdit->setValidator(validator);

    model->setTable("user");
    model->setFilter("role=2");
    model->select();
    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setColumnHidden(model->fieldIndex("id"), true);
//    ui->tableView->setColumnHidden(model->fieldIndex("password"), true);
    ui->tableView->setColumnHidden(model->fieldIndex("role"), true);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

OwnerPage::~OwnerPage()
{
    delete ui;
}

void OwnerPage::on_editButton_clicked()
{
    ui->tableView->setEditTriggers(QAbstractItemView::DoubleClicked);
    ui->editButton->setText("请在表格中修改");
}

void OwnerPage::on_submitButton_clicked()
{
    model->database().transaction(); //开始事务操作
    if (model->submitAll()) {
        model->database().commit(); //提交
    } else {
        model->database().rollback(); //回滚
        qDebug() << "提交失败";
    }
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void OwnerPage::on_queryButton_clicked()
{
    QString username = (ui->usernameEdit->text().isEmpty())?"":tr("AND username = '%1'").arg(ui->usernameEdit->text());
    qDebug() << username;
    QString phone = (ui->phoneEdit->text().isEmpty())?"":tr("AND phone = '%1'").arg(ui->phoneEdit->text());
    qDebug() << phone;
    QString address = (ui->addressEdit->toPlainText().isEmpty())?"":tr("AND address = '%1'").arg(ui->addressEdit->toPlainText());
    qDebug() << tr("role=2 %1 %2 %3").arg(username).arg(phone).arg(address);
    model->setFilter(tr("role=2 %1 %2 %3").arg(username).arg(phone).arg(address));
    model->select();
}



void OwnerPage::on_addButton_clicked()
{
    QSqlRecord record = model->record();
    record.setValue("username", ui->usernameEdit->text());
    record.setValue("role", 2);
    record.setValue("phone", ui->phoneEdit->text().toInt());
    record.setValue("address", ui->addressEdit->toPlainText());
    model->insertRecord(model->rowCount(), record);
    model->submitAll();

    model->select();
}
