#pragma execution_character_set("utf-8")
#include "settingspage.h"
#include "ui_settingspage.h"
#include <QProcess>

SettingsPage::SettingsPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingsPage)
{
    ui->setupUi(this);
    model->setTable("settings");
    model->select();
    record = model->record(0);
    qDebug() << record.value("author").toString();
    ui->authorEdit->setText(record.value("author").toString());
    FlatUI::Instance()->setPushButtonQss(ui->initButton, 5, 8, "#1ABC9C", "#E6F8F5", "#2EE1C1", "#FFFFFF", "#16A086", "#A7EEE6");
    FlatUI::Instance()->setPushButtonQss(ui->saveButton, 5, 8, "#1ABC9C", "#E6F8F5", "#2EE1C1", "#FFFFFF", "#16A086", "#A7EEE6");
    FlatUI::Instance()->setLineEditQss(ui->authorEdit, 5, 2, "#DCE4EC", "#1ABC9C");
    FlatUI::Instance()->setDateEditQss(ui->alterTimeEdit, 5, 2, "#DCE4EC", "#1ABC9C");
}

SettingsPage::~SettingsPage()
{
    delete ui;
}

void SettingsPage::on_saveButton_clicked()
{
    record.setValue("author", ui->authorEdit->text());
    record.setValue("alter_time", ui->alterTimeEdit->date().toString("yyyy-MM-dd"));
    model->setRecord(0, record);
    model->submitAll();
}

void SettingsPage::on_initButton_clicked()
{
    if(QMessageBox::Yes == QMessageBox::question(this, "系统初始化", "确定要将系统初始化吗？", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes)) {
        QSqlQuery query(db);
        query.exec("PRAGMA foreign_keys = off;");
        query.exec("BEGIN TRANSACTION;");
        query.exec("DROP TABLE IF EXISTS attendance;");
        query.exec("CREATE TABLE attendance ( \
                   id           INTEGER PRIMARY KEY AUTOINCREMENT \
                                        NOT NULL, \
                   username     TEXT, \
                   signin_time  TIME, \
                   signout_time TIME, \
                   date         DATE, \
                   CONSTRAINT fkey0 FOREIGN KEY ( \
                       username \
                   ) \
                   REFERENCES user (username) ON UPDATE CASCADE \
               );");
        query.exec("DROP TABLE IF EXISTS leave;");
        query.exec("CREATE TABLE leave ( \
                   id         INTEGER PRIMARY KEY AUTOINCREMENT \
                                      NOT NULL, \
                   username   TEXT    NOT NULL, \
                   reason     TEXT, \
                   start_time DATE, \
                   end_time   DATE, \
                   state      TEXT, \
                   CONSTRAINT user_username FOREIGN KEY ( \
                       username \
                   ) \
                   REFERENCES user (username) ON UPDATE CASCADE \
               );");
        query.exec("DROP TABLE IF EXISTS parking;");
        query.exec("CREATE TABLE parking ( \
                   id          INTEGER PRIMARY KEY AUTOINCREMENT \
                                       NOT NULL, \
                   position    TEXT, \
                   type        TEXT, \
                   chargeable  TEXT, \
                   size        TEXT, \
                   state       TEXT, \
                   license     TEXT, \
                   username    TEXT    REFERENCES user (username) ON DELETE SET NULL \
                                                                  ON UPDATE CASCADE, \
                   expair_time DATE, \
                   pay_state   TEXT \
               );");
        query.exec("DROP TABLE IF EXISTS pay;");
        query.exec("CREATE TABLE pay ( \
                   id       INTEGER PRIMARY KEY AUTOINCREMENT \
                                    NOT NULL, \
                   pay_date DATE, \
                   type     TEXT    REFERENCES price (type) ON DELETE CASCADE \
                                                            ON UPDATE CASCADE, \
                   username TEXT    REFERENCES user (username) ON DELETE CASCADE \
                                                               ON UPDATE CASCADE, \
                   quantity INTEGER \
               );");
        query.exec("DROP TABLE IF EXISTS price;");
        query.exec("CREATE TABLE price ( \
                   id     INTEGER PRIMARY KEY AUTOINCREMENT \
                                  NOT NULL, \
                   type   TEXT    UNIQUE, \
                   unit   TEXT, \
                   amount REAL \
               );");
        query.exec("INSERT INTO price (id, type, unit, amount) VALUES (1, '维修费', '元', 10);");
        query.exec("INSERT INTO price (id, type, unit, amount) VALUES (2, '车位费', '元', 10);");
        query.exec("INSERT INTO price (id, type, unit, amount) VALUES (3, '物业费', '元', 10);");
        query.exec("DROP TABLE IF EXISTS queue;");
        query.exec("CREATE TABLE queue ( \
                   id         INTEGER PRIMARY KEY AUTOINCREMENT \
                                      NOT NULL, \
                   username   TEXT    REFERENCES user (username) ON DELETE CASCADE \
                                                                 ON UPDATE CASCADE, \
                   license    TEXT, \
                   size       TEXT, \
                   chargeable TEXT \
               );");
        query.exec("DROP TABLE IF EXISTS repair;");
        query.exec("CREATE TABLE repair ( \
                   id          INTEGER PRIMARY KEY AUTOINCREMENT \
                                       NOT NULL, \
                   username    TEXT    REFERENCES user (username) ON DELETE CASCADE \
                                                                  ON UPDATE CASCADE, \
                   information TEXT, \
                   state       TEXT, \
                   result      TEXT, \
                   content     TEXT \
               );");
        query.exec("DROP TABLE IF EXISTS settings;");
        query.exec("CREATE TABLE settings ( \
                   id         INTEGER PRIMARY KEY AUTOINCREMENT \
                                      NOT NULL, \
                   author     TEXT, \
                   alter_time DATE \
               );");
        query.exec("INSERT INTO settings (id, author, alter_time) VALUES (1, '赵曰艺', '2020-01-01');");
        query.exec("DROP TABLE IF EXISTS user;");
        query.exec("CREATE TABLE user ( \
                   id       INTEGER PRIMARY KEY AUTOINCREMENT \
                                    NOT NULL, \
                   username TEXT, \
                   password TEXT, \
                   role     INTEGER, \
                   phone    INTEGER, \
                   address  TEXT, \
                   CONSTRAINT unique_username UNIQUE ( \
                       username \
                   ) \
               );");
        query.exec("INSERT INTO user (id, username, password, role, phone, address) VALUES (3, '3', '3', 3, NULL, NULL);");
        query.exec("INSERT INTO user (id, username, password, role, phone, address) VALUES (0, '0', '0', 0, NULL, NULL);");
        query.exec("INSERT INTO user (id, username, password, role, phone, address) VALUES (1, '1', '1', 1, NULL, NULL);");
        query.exec("INSERT INTO user (id, username, password, role, phone, address) VALUES (2, '2', '2', 2, NULL, NULL);");
        query.exec("COMMIT TRANSACTION;");
        query.exec("PRAGMA foreign_keys = on;");
        qApp->quit();
        QProcess::startDetached(qApp->applicationFilePath(),QStringList());
    }
}
