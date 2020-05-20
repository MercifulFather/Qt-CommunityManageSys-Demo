#ifndef CARPAGE_H
#define CARPAGE_H

#include <QWidget>
#include "common.h"
#include "carmanagepart.h"
#include "rentpart.h"
#include "applypart.h"
#include "myparkingpart.h"

namespace Ui {
class CarPage;
}

class CarPage : public QWidget
{
    Q_OBJECT

public:
    explicit CarPage(QWidget *parent = nullptr, QString username = nullptr, int role = 0);
    ~CarPage();

private slots:
    void on_tabWidget_tabBarClicked(int index);

private:
    Ui::CarPage *ui;
    CarManagePart * cmp;
    RentPart * rp;
    ApplyPart * ap;
    MyParkingPart * mpp;

};

#endif // CARPAGE_H
