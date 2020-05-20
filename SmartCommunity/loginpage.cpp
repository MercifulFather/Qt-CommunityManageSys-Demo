#pragma execution_character_set("utf-8")
#include "loginpage.h"
#include "ui_loginpage.h"

LoginPage::LoginPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginPage)
{
    model->setTable("user");
    ui->setupUi(this);
    ui->registerButton->hide();
    ui->errorMessageLabel->hide();
    FlatUI::Instance()->setPushButtonQss(ui->loginButton, 5, 8, "#1ABC9C", "#E6F8F5", "#2EE1C1", "#FFFFFF", "#16A086", "#A7EEE6");
    FlatUI::Instance()->setPushButtonQss(ui->registerButton, 5, 8, "#1ABC9C", "#E6F8F5", "#2EE1C1", "#FFFFFF", "#16A086", "#A7EEE6");
    FlatUI::Instance()->setLineEditQss(ui->usernameEdit, 5, 2, "#DCE4EC", "#1ABC9C");
    FlatUI::Instance()->setLineEditQss(ui->passwordEdit, 5, 2, "#DCE4EC", "#1ABC9C");
}

LoginPage::~LoginPage()
{
    delete ui;
}

void LoginPage::on_loginButton_clicked()
{
    QSqlQuery query = QSqlQuery(QSqlDatabase::database());
    model->setFilter(tr("username= '%1'").arg(ui->usernameEdit->text()));
    if (model->select()) {
        if (model->rowCount() > 0) {
            QSqlRecord record = model->record(0);
            if (record.value("password").toString().compare(ui->passwordEdit->text()) == 0) {
                emit login(ui->usernameEdit->text(), record.value("role").toInt());
            } else {
                // 密码错误
                ui->errorMessageLabel->setText("密码错误");
                ui->errorMessageLabel->show();
                ui->passwordEdit->clear();
            }
        } else {
            // 无此用户
            ui->errorMessageLabel->setText("用户名不存在");
            ui->errorMessageLabel->show();
            ui->usernameEdit->clear();
            ui->passwordEdit->clear();
        }
    }
}

void LoginPage::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Enter){
        ui->loginButton->click();
    }
}

void LoginPage::on_registerButton_clicked()
{
    emit showRegisterPage();
    ui->usernameEdit->clear();
    ui->passwordEdit->clear();
}
