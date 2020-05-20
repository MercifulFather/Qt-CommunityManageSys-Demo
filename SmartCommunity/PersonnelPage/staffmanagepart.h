#ifndef STAFFMANAGEPART_H
#define STAFFMANAGEPART_H

#include <QWidget>
#include "common.h"

namespace Ui {
class StaffManagePart;
}

class StaffManagePart : public QWidget
{
    Q_OBJECT

public:
    explicit StaffManagePart(QWidget *parent = nullptr);
    ~StaffManagePart();

private slots:
    void on_addButton_clicked();

    void on_submitButton_clicked();

    void on_deleteButton_clicked();

    void on_editButton_clicked();

    void on_revertButton_clicked();

private:
    Ui::StaffManagePart *ui;
    QSqlDatabase db = QSqlDatabase::database();
    QSqlTableModel * model = new QSqlTableModel(this, db);
    QList<int> delRows;
};

#endif // STAFFMANAGEPART_H
