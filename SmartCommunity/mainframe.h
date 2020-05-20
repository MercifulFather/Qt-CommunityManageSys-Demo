#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <QWidget>
#include "common.h"
#include "AttendPage/attendpage.h"
#include "CarPage/carpage.h"
#include "SettingsPage/settingspage.h"
#include "PersonnelPage/personnelpage.h"
#include "EstatePage/estatepage.h"
#include "OwnerPage/ownerpage.h"
#include "PayPage/paypage.h"
#include "RepairPage/repairpage.h"

namespace Ui {
class MainFrame;
}

class MainFrame : public QWidget
{
    Q_OBJECT

public:
    explicit MainFrame(QWidget *parent = nullptr, QString username = nullptr, int role = 0);
    ~MainFrame();

private:
    Ui::MainFrame *ui;
    SettingsPage * sp;
    PersonnelPage * pp;
    AttendPage * ap;
    OwnerPage * op;
    CarPage * cp;
    EstatePage * ep;
    PayPage * pyp;
    RepairPage * rp;
    QList<NavButton *> navButtons;
    QStringList buttonAction;
    void initMenu();
private slots:
    void navButtons_clicked();
};

#endif // MAINFRAME_H
