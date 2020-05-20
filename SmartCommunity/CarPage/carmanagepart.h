#ifndef CARMANAGEPART_H
#define CARMANAGEPART_H

#include <QWidget>
#include "common.h"
#include "adddialog.h"

namespace Ui {
class CarManagePart;
}

class CarManagePart : public QWidget
{
    Q_OBJECT

public:
    explicit CarManagePart(QWidget *parent = nullptr);
    ~CarManagePart();
    void query();
private slots:
    void on_addButton_clicked();

    void on_editButton_clicked();

    void on_deleteButton_clicked();

private:
    Ui::CarManagePart *ui;
    QSqlDatabase db = QSqlDatabase::database();
    QSqlTableModel * model = new QSqlTableModel(this, db);
};

#endif // CARMANAGEPART_H
