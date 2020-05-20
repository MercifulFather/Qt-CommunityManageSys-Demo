#ifndef PERSONNELPAGE_H
#define PERSONNELPAGE_H

#include <QWidget>
#include "staffmanagepart.h"

namespace Ui {
class PersonnelPage;
}

class PersonnelPage : public QWidget
{
    Q_OBJECT

public:
    explicit PersonnelPage(QWidget *parent = nullptr);
    ~PersonnelPage();

private:
    Ui::PersonnelPage *ui;
    StaffManagePart * smp;
};

#endif // PERSONNELPAGE_H
