#ifndef CONTENTDIALOG_H
#define CONTENTDIALOG_H

#include <QDialog>
#include "common.h"

namespace Ui {
class ContentDialog;
}

class ContentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ContentDialog(QWidget *parent = nullptr, int id = 0);
    ~ContentDialog();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::ContentDialog *ui;
    QSqlDatabase db = QSqlDatabase::database();
    QSqlTableModel * model = new QSqlTableModel(this, db);
    int iId;
};

#endif // CONTENTDIALOG_H
