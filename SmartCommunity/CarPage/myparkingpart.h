#ifndef MYPARKINGPART_H
#define MYPARKINGPART_H

#include <QWidget>
#include "common.h"

namespace Ui {
class MyParkingPart;
}

class MyParkingPart : public QWidget
{
    Q_OBJECT

public:
    explicit MyParkingPart(QWidget *parent = nullptr, QString username = nullptr);
    ~MyParkingPart();
    void query();
private:
    Ui::MyParkingPart *ui;
    QSqlDatabase db = QSqlDatabase::database();
    QSqlTableModel * model = new QSqlTableModel(this, db);
};

#endif // MYPARKINGPART_H
