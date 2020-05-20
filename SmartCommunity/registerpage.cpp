#pragma execution_character_set("utf-8")
#include "registerpage.h"
#include "ui_registerpage.h"

RegisterPage::RegisterPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegisterPage)
{
    model->setTable("user");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    ui->setupUi(this);
    FlatUI::Instance()->setPushButtonQss(ui->confirmButton, 5, 8, "#1ABC9C", "#E6F8F5", "#2EE1C1", "#FFFFFF", "#16A086", "#A7EEE6");
    FlatUI::Instance()->setPushButtonQss(ui->cancelButton, 5, 8, "#1ABC9C", "#E6F8F5", "#2EE1C1", "#FFFFFF", "#16A086", "#A7EEE6");
    FlatUI::Instance()->setLineEditQss(ui->usernameEdit, 5, 2, "#DCE4EC", "#1ABC9C");
    FlatUI::Instance()->setLineEditQss(ui->passwordEdit, 5, 2, "#DCE4EC", "#1ABC9C");
    FlatUI::Instance()->setLineEditQss(ui->confirmEdit, 5, 2, "#DCE4EC", "#1ABC9C");
}

RegisterPage::~RegisterPage()
{
    delete ui;
}

void RegisterPage::on_cancelButton_clicked()
{
    emit showLoginPage();
    ui->confirmEdit->clear();
    ui->usernameEdit->clear();
    ui->passwordEdit->clear();
}

void RegisterPage::on_confirmButton_clicked()
{
    model->setFilter(tr("username= '%1'").arg(ui->usernameEdit->text()));
    if (model->select()) {
        if (model->rowCount() == 0) {
            if (!ui->passwordEdit->text().isEmpty()) {
                if (ui->passwordEdit->text().compare(ui->confirmEdit->text()) == 0) {
                    QSqlRecord record = model->record();
                    record.setValue("username", ui->usernameEdit->text());
                    record.setValue("password", ui->passwordEdit->text());
                    model->insertRecord(0, record);
                    model->submitAll();

                    emit showLoginPage();
                    ui->confirmEdit->clear();
                    ui->usernameEdit->clear();
                    ui->passwordEdit->clear();
                } else {
                    qDebug() << "两次密码不一致";
                    model->revertAll();
                    // 两次密码不一致
                }
            } else {
                qDebug() << "密码为空";
                model->revertAll();
                // 密码为空
            }
        } else {
            qDebug() << "用户名已存在";
            model->revertAll();
            // 用户名已存在
        }
    }
}
