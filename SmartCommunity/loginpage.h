#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QWidget>
#include "common.h"

namespace Ui {
class LoginPage;
}

class LoginPage : public QWidget
{
    Q_OBJECT

public:
    explicit LoginPage(QWidget *parent = nullptr);
    ~LoginPage();

signals:
    void showRegisterPage();
    void login(QString username, int role);

private slots:
    void on_loginButton_clicked();
    void on_registerButton_clicked();

private:
    Ui::LoginPage *ui;
    void keyPressEvent(QKeyEvent *event);

    QSqlDatabase db = QSqlDatabase::database();
    QSqlTableModel * model = new QSqlTableModel(this, db);
};

#endif // LOGINPAGE_H
