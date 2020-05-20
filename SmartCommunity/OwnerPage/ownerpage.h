#ifndef OWNERPAGE_H
#define OWNERPAGE_H

#include <QWidget>
#include "common.h"

namespace Ui {
class OwnerPage;
}

class OwnerPage : public QWidget
{
    Q_OBJECT

public:
    explicit OwnerPage(QWidget *parent = nullptr);
    ~OwnerPage();

private slots:
    void on_editButton_clicked();

    void on_submitButton_clicked();

    void on_queryButton_clicked();

    void on_addButton_clicked();

private:
    Ui::OwnerPage *ui;
    QSqlDatabase db = QSqlDatabase::database();
    QSqlTableModel * model = new QSqlTableModel(this, db);
};

#endif // OWNERPAGE_H
