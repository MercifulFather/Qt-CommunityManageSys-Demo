#ifndef QUERYREPAIRPART_H
#define QUERYREPAIRPART_H

#include <QWidget>
#include "common.h"
#include "contentdialog.h"
#include "processdialog.h"

namespace Ui {
class QueryRepairPart;
}

class QueryRepairPart : public QWidget
{
    Q_OBJECT

public:
    explicit QueryRepairPart(QWidget *parent = nullptr, QString username = nullptr, int role = 0);
    ~QueryRepairPart();
    void refresh();
private slots:
    void on_contentButton_clicked();

    void on_processButton_clicked();

private:
    Ui::QueryRepairPart *ui;
    QSqlDatabase db = QSqlDatabase::database();
    QSqlTableModel * model = new QSqlTableModel(this, db);
    ContentDialog * cd;
    ProcessDialog * pd;
};

#endif // QUERYREPAIRPART_H
