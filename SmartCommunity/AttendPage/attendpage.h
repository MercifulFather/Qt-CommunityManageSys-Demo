#ifndef ATTENDPAGE_H
#define ATTENDPAGE_H

#include <QWidget>
#include "attendancepart.h"
#include "requestpart.h"
#include "reviewpart.h"
#include "signpart.h"

namespace Ui {
class AttendPage;
}

class AttendPage : public QWidget
{
    Q_OBJECT

public:
    explicit AttendPage(QWidget *parent = nullptr, QString username = nullptr, int role = 0);
    ~AttendPage();

private slots:
    void on_tabWidget_tabBarClicked(int index);

private:
    Ui::AttendPage *ui;
    AttendancePart * ap;
    RequestPart * rqp;
    ReviewPart * rvp;
    SignPart * sp;
};

#endif // ATTENDPAGE_H
