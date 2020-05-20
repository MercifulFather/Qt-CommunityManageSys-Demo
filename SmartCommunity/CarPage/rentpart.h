#ifndef RENTPART_H
#define RENTPART_H

#include <QWidget>
#include "common.h"

namespace Ui {
class RentPart;
}

class RentPart : public QWidget
{
    Q_OBJECT

public:
    explicit RentPart(QWidget *parent = nullptr);
    ~RentPart();
    void query();
private slots:
    void on_rentButton_clicked();

private:
    Ui::RentPart *ui;
    QSqlDatabase db = QSqlDatabase::database();
    QSqlTableModel * queueModel = new QSqlTableModel(this, db);
    QSqlTableModel * parkingModel = new QSqlTableModel(this, db);
};

#endif // RENTPART_H
