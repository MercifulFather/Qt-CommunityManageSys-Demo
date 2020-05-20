#ifndef REPAIRPAGE_H
#define REPAIRPAGE_H

#include <QWidget>
#include "reportpart.h"
#include "queryrepairpart.h"

namespace Ui {
class RepairPage;
}

class RepairPage : public QWidget
{
    Q_OBJECT

public:
    explicit RepairPage(QWidget *parent = nullptr, QString username = nullptr, int role = 0);
    ~RepairPage();

private slots:
    void on_tabWidget_tabBarClicked(int index);

private:
    Ui::RepairPage *ui;
    ReportPart * rp;
    QueryRepairPart * qrp;
};

#endif // REPAIRPAGE_H
