#ifndef ATTENDANCEPART_H
#define ATTENDANCEPART_H

#include <QWidget>
#include "common.h"

namespace Ui {
class AttendancePart;
}

class AttendancePart : public QWidget
{
    Q_OBJECT

public:
    explicit AttendancePart(QWidget *parent = nullptr);
    ~AttendancePart();
    void update();
private slots:
    void on_leaveButton_clicked();

    void on_attendButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::AttendancePart *ui;
    QSqlDatabase db = QSqlDatabase::database();
    QSqlTableModel * model = new QSqlTableModel(this, db);

};

#endif // ATTENDANCEPART_H
