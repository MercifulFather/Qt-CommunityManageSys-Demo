#ifndef REGISTERPAGE_H
#define REGISTERPAGE_H

#include <QWidget>

#include "common.h"

namespace Ui {
class RegisterPage;
}

class RegisterPage : public QWidget
{
    Q_OBJECT

public:
    explicit RegisterPage(QWidget *parent = nullptr);
    ~RegisterPage();

private:
    Ui::RegisterPage *ui;
    QSqlDatabase db = QSqlDatabase::database();
    QSqlTableModel * model = new QSqlTableModel(this, db);
signals:
    void showLoginPage();
private slots:
    void on_cancelButton_clicked();
    void on_confirmButton_clicked();
};

#endif // REGISTERPAGE_H
