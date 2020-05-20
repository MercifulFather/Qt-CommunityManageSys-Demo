#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>
#include "common.h"

namespace Ui {
class addDialog;
}

class addDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addDialog(QWidget *parent = nullptr, int type = 0, int id = 0);
    ~addDialog();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::addDialog *ui;
    QSqlDatabase db = QSqlDatabase::database();
    QSqlTableModel * model = new QSqlTableModel(this, db);
    int iType;
    int iId;
};

#endif // ADDDIALOG_H
